#define _GNU_SOURCE
#define CPU_ZERO
#define CPU_SET
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>
#include <time.h>

// Gruppe 15 | Tobias Schoch, Luis Nothvogel

int main(int argc, char **argv) {

    // set Program to run solely on Core 0
    cpu_set_t my_set;
    CPU_ZERO(&my_set);
    CPU_SET(1, &my_set);
    sched_setaffinity(0, sizeof(cpu_set_t), &my_set);

    struct timespec startTime, endTime;

    int numbOfPagesToTouch = 1024;
    int numberOfTrials = 1000000;
    int parameter;

    // Process Input Paramters
    while ((parameter = getopt(argc, argv, "hn:l:")) != -1) {
        switch (parameter) {
            case 'h':
                printf("Dieses Programm tut dinge");
                break;
            case 'n':
                numbOfPagesToTouch = atoi(optarg);
                break;
            case 'l':
                numberOfTrials = atoi(optarg);
                break;
            case '?':
                printf("Unknown paramter: %c\n", optopt);
                break;
        }
    }

    // Error handling if Paramaters are too small
    if (numbOfPagesToTouch <= 0) {
        printf("-n must be > 0");
        return EXIT_FAILURE;
    }

    if (numberOfTrials <= 0) {
        printf("-l must be > 0");
        return EXIT_FAILURE;
    }

    printf("Number of Pages to Touch: %d\n", numbOfPagesToTouch);
    printf("Number of Trials: %d\n", numberOfTrials);

    // Formula from Book, calcualte jump size
    int PAGESIZE = getpagesize();
    int jump = PAGESIZE / sizeof(int);
    int *a = (int *) calloc(numbOfPagesToTouch * jump, sizeof(int));

    if (a == NULL) {
        perror("Error ");
        return EXIT_FAILURE;
    }
    clock_gettime(CLOCK_REALTIME, &startTime);
    for (int i = 0; i < numberOfTrials; i++) {
        for (int j = 0; j < numbOfPagesToTouch * jump; j += jump) {
            a[j] += 1;
        }
    }

    clock_gettime(CLOCK_REALTIME, &endTime);
    printf("Total time needed: %ld\n", (endTime.tv_nsec - startTime.tv_nsec) / numberOfTrials);
    free(a);
    return EXIT_SUCCESS;
}