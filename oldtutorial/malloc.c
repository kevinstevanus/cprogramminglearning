#include <stdio.h>
#include <stdlib.h>

int main() {
  int count;

  printf("how many temperature readings do you want to records?");

  if (scanf("%d", &count) != 1 || count <= 0) {
    printf("invalid input");
    return 1;
  }

  float *temperatures = malloc(count * sizeof(float));

  if (temperatures == NULL) {
    printf("memory allocation failed, out of ram.");
    return 1;
  }

  // get data from user dynamically
  for (int i = 0; i < count; i++) {
    printf("enter reading %d: ", i + 1);
    scanf("%f", &temperatures[i]);
  }

  // processing the data
  float sum = 0.0;
  for (int i = 0; i < count; i++) {
    sum += temperatures[i];
  }
  float average = sum / count;

  printf("results----\n");
  printf("recorded %d readings. \n", count);
  printf("average temperature: %.2f celc \n", average);

  free(temperatures);
  temperatures = NULL;
  return 0;
}
