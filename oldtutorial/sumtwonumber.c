#include <stdio.h>
int main() {
  int x = 0;
  int y = 0;

  printf("hello there");
  scanf("%d", &x);

  scanf("%d", &y);
  printf("result: %d", (x + y));

  return 0;
}
