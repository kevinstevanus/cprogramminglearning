#include <stdio.h>

int main() {
  int score = 42;
  int *ptr = &score;

  printf("%p\n", ptr);
  printf("%p\n", (void *)ptr);
  printf("%d\n", *ptr);

  return 0;
}
