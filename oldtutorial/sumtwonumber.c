#include <stdio.h>

int main(void) {

  int num1;
  int num2;
  printf("give first number: \n");

  scanf("%d", &num1);

  printf("give second number: \n");
  scanf("%d", &num2);
  printf("sum is: %d", (num1 + num2));
  printf("asd\n");
  printf("memory address %p\n", (void *)&num1);
  return 0;
}
