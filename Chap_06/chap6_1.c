#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>
//chap61
int main() {
  int repeat = 1000;
  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);

  for(int i = 0; i < repeat; i++) {
    read(0, NULL, 0);
  }

  gettimeofday(&end_time, NULL);
  printf("System-Call Dauer im Durchschnitt: %f microseconds\n", (float) (end_time.tv_usec - start_time.tv_usec) / repeat);
  return 0;
}
