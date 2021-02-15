#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>

int main() {

    cpu_set_t my_set;
    CPU_ZERO(&my_set);
    CPU_SET(0, &my_set);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    gettimeofday(&end_time, NULL);

    int pipe_one[2] = {0, 0};
    int pipe_two[2] = {0, 0};
    pid_t cpid = fork();

    if (cpid < 0) {
        fprintf(stderr, "fork failed");
    } else if (cpid == 0) {
        for (int i = 0; i < 1000; i++) {
            read(pipe_one[0], NULL, 0);
            write(pipe_two[1], NULL, 0);
        }
    } else {
        gettimeofday(&start_time, NULL);
        for (int i = 0; i < 1000; i++) {
            write(pipe_one[1], NULL, 0);
            read(pipe_two[0], NULL, 0);
        }
        gettimeofday(&end_time, NULL);
        printf("Content Switch: %f microseconds\n", (float) (end_time.tv_usec - start_time.tv_usec) / 1000);
    }
    return 0;
}
