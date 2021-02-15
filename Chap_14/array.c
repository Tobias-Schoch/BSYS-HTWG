#include <stdio.h>
#include "stdlib.h"

int main() {
  int *data = (int *) malloc(100 * sizeof(int));

  if (data == NULL) {
      perror("Error ");
      return EXIT_FAILURE;
  }

  data[100] = 0;
  return EXIT_SUCCESS;
}
