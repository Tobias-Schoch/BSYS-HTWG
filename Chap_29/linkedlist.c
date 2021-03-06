#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <pthread.h>

typedef struct snote_t {
    int value;
    struct snote_t *next;
} node_t;

typedef struct slist_t {
    node_t *head;
    int size;
    pthread_mutex_t lock;
} list_t;

typedef struct {
    list_t *L;
    int searchAtPosition;
    int threadNumber;
} myarg_t;

// Init empty List
void initList(list_t *L) {
    pthread_mutex_init(&L->lock, NULL);
    L->head = NULL;
    L->size = 0;
}

// basic list insert with couple lock
// insert at the end of list
int listInsert(list_t *L, int valueToInsert) {
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
        perror("Malloc Error");
        return -1;
    }
    if (L->size > 0) {
        node_t *nodePointer = L->head;
        while (nodePointer->next != NULL) {
            nodePointer = nodePointer->next;
        }
        nodePointer->next = newNode;
        newNode->value = valueToInsert;
        newNode->next = NULL;
        L->size = L->size + 1;
    } else {
        L->head = newNode;
        newNode->value = valueToInsert;
        newNode->next = NULL;
        L->size = L->size + 1;
    }
    return 0;
}

// search methode iterates over data structure until it finds the requested value
void* searchAtPos(void *arg) {
    myarg_t *myargs = (myarg_t  *) arg;
    struct timespec startTime, endTime;
    node_t *nodePointer = myargs->L->head;
    int pos = 0;
    clock_gettime(CLOCK_REALTIME, &startTime);
    pthread_mutex_lock(&myargs->L->lock);
    while (nodePointer) {
        if (pos >= myargs->searchAtPosition || nodePointer->next == NULL) {
            break;
        }
        nodePointer = nodePointer->next;
        pos = pos + 1;
    }
    pthread_mutex_unlock(&myargs->L->lock);
    clock_gettime(CLOCK_REALTIME, &endTime);
    long threadTime = endTime.tv_nsec - startTime.tv_nsec;
    printf("Thread %d: The Value at %d is: %d\nTime needed: %ld ns\n", myargs->threadNumber, myargs->searchAtPosition, nodePointer->value, threadTime);
    return NULL;
}

// free every node in List + free list
void freeList(list_t *L) {
    free(L);
}

int main(int argc, char **argv) {
    list_t *L = malloc(sizeof(list_t));
    if (L == NULL) {
        perror("Malloc Error");
        return -1;
    }
    initList(L);

    int listSize = 0;
    int searchAtListPos = 0;
    int parameter;
    int threadsize = 0;
    // Process Input Paramters
    while ((parameter = getopt(argc, argv, "hs:p:t:")) != -1) {
        switch (parameter) {
            case 'h':
                printf("Dieses Programm benötigt -s als Baumgroesse und -p als Suchwert im Baum und -t als threadanzahl\n");
                break;
            case 's':
                listSize = atoi(optarg);
                break;
            case 'p':
                searchAtListPos = atoi(optarg);
                break;
            case 't':
                threadsize = atoi(optarg);
                break;
            case '?':
                printf("Unknown paramter: %c\n", optopt);
                break;
        }
    }

    if (listSize <= 0) {
        printf("s must be > 0\n");
        return EXIT_FAILURE;
    }

    if (searchAtListPos <= 0 || searchAtListPos >= listSize) {
        printf("p must be > 0 and < listsize\n");
        return EXIT_FAILURE;
    }

    if (threadsize <= 0) {
        printf("t must be > 0\n");
        return EXIT_FAILURE;
    }


    printf("Listsize: %d\n", listSize);

    for (int i = 0; i < listSize; i++) {
        listInsert(L, i);
    }
    pthread_t threads[threadsize];
    myarg_t myargArray[threadsize];
    for (int i = 0; i < threadsize; i++) {
        myarg_t myarg = {L, searchAtListPos, i};
        myargArray[i] = myarg;
    }
    for (int run = 0; run < 10; run++) {
        for (int f = 0; f < threadsize; f++) {
            if ((pthread_create(&threads[f], NULL, searchAtPos, &myargArray[f]) != 0)) {
                perror("Thread Creation Error");
                return -1;
            }
        }
        for (int f = 0; f < threadsize; f++) {
            pthread_join(threads[f], NULL);
        }
        printf("------------------\n");
    }
    freeList(L);
    return EXIT_SUCCESS;
}
