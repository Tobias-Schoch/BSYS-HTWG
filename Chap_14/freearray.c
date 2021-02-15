#include "stdlib.h"
#include "stdio.h"

int main() {
  int *data = (int *) malloc(100 * sizeof(int));

  if (data == NULL) {
      perror("Error ");
      return EXIT_FAILURE;
  }

  data[99] = 99;
  //free(data);
  int *funnyPointer = &data[99];
  free(funnyPointer);
  printf("%d\n", data[99]);
  return EXIT_SUCCESS;
}
