#include <stdio.h>

int main() {

  int numbers[3] = {10, 20, 30};
  int *p = numbers;

  printf("%d\n", *p);
  printf("%d\n", *(p + 1));
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of double: %zu bytes\n", sizeof(double));
  return 0;
}
