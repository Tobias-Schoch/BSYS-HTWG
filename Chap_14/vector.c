#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    struct vec {
        int arrSize;
        int arr[];
    };

    struct vec *vecArr;
    vecArr = malloc(sizeof(struct vec));

    if (vecArr == NULL) {
        perror("Error ");
        return EXIT_FAILURE;
    }

    if (argc != 2) {
        fprintf(stderr, "Parameter missing or too many");
        return EXIT_FAILURE;
    }

    int amountOfElements = atoi(argv[1]);

    if (amountOfElements < 0) {
        fprintf(stderr, "Parameter needs to be >= 0");
        return EXIT_FAILURE;
    }

    vecArr->arrSize = vecArr->arrSize + amountOfElements;
    vecArr = realloc(vecArr, amountOfElements * sizeof(int));

    if (vecArr == NULL) {
        perror("Error");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < vecArr->arrSize; i++) {
        printf("%u\n", vecArr->arr[i]);
    }
	free(vecArr);
    return EXIT_SUCCESS;
}
