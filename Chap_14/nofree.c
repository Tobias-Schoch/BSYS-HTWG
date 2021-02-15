#include "stdlib.h"
#include "stdio.h"

int main() {
  int *p = (int *) malloc(sizeof(int));

  if (p == NULL) {
      perror("Error ");
      return EXIT_FAILURE;
  }

  printf("%lu\n", sizeof(p));
  return EXIT_SUCCESS;
}
