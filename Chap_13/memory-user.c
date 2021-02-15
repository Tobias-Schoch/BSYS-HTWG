#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Die Aufgabe wurde so verstanden, dass ein Programm erstellt werden soll was 2 Parameter entgegen nimmt und solange läuft bis die Zeit abgelaufen ist.
// Dabei soll es eine gewissen Größe an Speicher für einen Array allokieren und dann anschließend dauert darüber iterieren und einen wert setzen.
// Der erste Parameter ist für die Größe des zu belegenden Speichers in MB.
// Der zweite Parameter ist die zeit in Sekunden, die das Programm laufen soll
int main(int argc, char *argv[]) {
    if (argc != 3) {
      printf("Please enter 2 Arguments (allocated memory in MB) (time in seconds)");
      return 1;
    }
    printf("PID: %d", getpid());

    // Multiply by 100000 to get MB from User Input Byte
    int memory = atoi(argv[1]) * 1000000;
    int time = atoi(argv[2]);

    if (memory <= 0 || time <= 0) {
        printf("Please enter values > 0");
        return 1;
    }

    int real_size = (int)(memory / sizeof(int));
    int *fill_array = malloc(memory);
    struct timespec start, stop;
    double accum;

    clock_gettime(CLOCK_REALTIME, &start);
    while (time > accum) {
        for (int i = 0; i < real_size; i++) {
            clock_gettime(CLOCK_REALTIME, &stop);
            accum = stop.tv_sec - start.tv_sec;
            if (time <= accum) {
                break;
            }
            fill_array[i] = 0;
        }
    }

    free(fill_array);
    return 0;
}
