#include <stdio.h>

int main() {
  int x;
  int *p = &x;
  *p = 10;
  printf("value of x: %d\n", x);
  printf("address of x:  %p\n", (void *)p);
  // int *p; printf("%p\n", (void *)p + 5);

  return 0;
}
