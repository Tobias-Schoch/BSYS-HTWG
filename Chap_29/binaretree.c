#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <pthread.h>
#include <assert.h>

typedef struct snode_t {
    int value;
    struct snode_t *left;
    struct snode_t *right;
} node_t;

typedef struct sbtree_t {
    node_t *root;
    pthread_mutex_t lock;
} btree_t;

typedef struct {
    btree_t *tree;
    int searchForValue;
    int threadNumber;
} myarg_t;

// Inits an empty tree
void treeInit(btree_t *btree) {
    btree->root = NULL;
    int rc = pthread_mutex_init(&btree->lock, NULL);
    assert(rc == 0);
}

// Inits nodes from an array
// Construct a balanced BinaryTree
node_t *nodeInsert(int array[], int start, int end, struct snode_t* nodeArray, int arrayIdx) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = array[mid];
    nodeArray[arrayIdx] = *nodeArray;
    newNode->left = nodeInsert(array, start, mid - 1, nodeArray, arrayIdx + 1);
    newNode->right = nodeInsert(array, mid + 1, end, nodeArray, arrayIdx + 1);

    return newNode;
}

// search methode iterates over data structure until it finds the requested value
void *searchBTree(void *arg) {
    myarg_t *myargs = (myarg_t *) arg;
    struct timespec startTime, endTime;
    clock_gettime(CLOCK_REALTIME, &startTime);
    pthread_mutex_lock(&myargs->tree->lock);
    node_t *node = myargs->tree->root;
    while (1) {
        if (node->value == myargs->searchForValue) {
            break;
        }
        if (myargs->searchForValue > node->value) {
            node = node->right;
        } else if (myargs->searchForValue < node->value) {
            node = node->left;
        } else {
            break;
        }
    }
    pthread_mutex_unlock(&myargs->tree->lock);
    clock_gettime(CLOCK_REALTIME, &endTime);
    long threadTime = endTime.tv_nsec - startTime.tv_nsec;
    printf("Thread %d\nTime needed: %ld ns\n", myargs->threadNumber, threadTime);
    return NULL;
}

void freeNode(node_t* node) {
    if (node == NULL) {
        return;
    }
    freeNode(node->left);
    freeNode(node->right);
    free(node);
}

// frees every node then frees the tree
void freeTree(btree_t *btree) {
    freeNode(btree->root);
    free(btree);
}

int main(int argc, char **argv) {
    btree_t *btree = malloc(sizeof(btree_t));
    if (btree == NULL) {
        perror("Malloc Error");
        return EXIT_FAILURE;
    }
    treeInit(btree);
    int binareTreeSize = 0;
    int searchTreeValue = 0;
    int parameter;
    int threadsize = 0;
    // Process Input Paramters
    while ((parameter = getopt(argc, argv, "hs:p:t:")) != -1) {
        switch (parameter) {
            case 'h':
                printf("Dieses Programm benötigt -s als Baumgroesse und -p als Suchwert im Baum und -t als threadanzahl\n");
                break;
            case 's':
                binareTreeSize = atoi(optarg);
                break;
            case 'p':
                searchTreeValue = atoi(optarg);
                break;
            case 't':
                threadsize = atoi(optarg);
                break;
            case '?':
                printf("Unknown paramter: %c\n", optopt);
                break;
        }
    }

    if (binareTreeSize <= 0) {
        printf("s must be > 0\n");
        return EXIT_FAILURE;
    }

    if (searchTreeValue <= 0 || searchTreeValue >= binareTreeSize) {
        printf("p must be > 0 and < listsize\n");
        return EXIT_FAILURE;
    }

    if (threadsize <= 0) {
        printf("t must be > 0\n");
        return EXIT_FAILURE;
    }

    printf("Binarytreesize: %d\n", binareTreeSize);

    int nodesArray[binareTreeSize];
    for (int i = 0; i < binareTreeSize; i++) {
        nodesArray[i] = i + 1;
    }
    struct snode_t nodeArray[binareTreeSize];
    node_t *root = nodeInsert(nodesArray, 0, binareTreeSize - 1, nodeArray, 0);
    btree->root = root;
    pthread_t threads[threadsize];
    myarg_t myargArray[threadsize];
    for (int i = 0; i < threadsize; i++) {
        myarg_t myarg = {btree, searchTreeValue, i};
        myargArray[i] = myarg;
    }
    for (int run = 0; run < 10; run++) {
        for (int f = 0; f < threadsize; f++) {
            if ((pthread_create(&threads[f], NULL, searchBTree, &myargArray[f]) != 0)) {
                perror("Thread Creation Error");
                return -1;
            }
        }
        for (int f = 0; f < threadsize; f++) {
            pthread_join(threads[f], NULL);
        }
        printf("------------------\n");
    }

    freeTree(btree);
    return EXIT_SUCCESS;
}
