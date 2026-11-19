#include <stdio.h>

int main() {
  // int testages = 44;
  //
  // printf("%d\n", testages);
  // printf("%p", &testages);
  // return 0;
  int testage = 100;
  int *ptr = &testage;
  int *anotherptr = &testage;

  *ptr = 50;
  *anotherptr = 30;

  printf("%p\n", ptr);
  printf("%p\n", anotherptr);

  printf("%d\n", ptr);

  printf("%d", testage);
  printf("%d", testage);
  return 0;
}
