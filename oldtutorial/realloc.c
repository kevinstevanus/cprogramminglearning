#include <stdio.h>
#include <stdlib.h>

int main() {
  int count;
  int addedCount;

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

  // printf("%p", (void *)temperatures);

  // get data from user dynamically
  for (int i = 0; i < count; i++) {
    printf("enter reading %d: ", i + 1);
    scanf("%f", &temperatures[i]);
  }

  // ask the user if want to add another reading
  printf("how many temperatures that you want to add to the existing records?");
  if (scanf("%d", &addedCount) != 1 || addedCount <= 0) {
    printf("invalid input");
    return 1;
  }

  int new_total_count = count + addedCount;
  float *temp = realloc(temperatures, new_total_count * sizeof(float));

  if (temp == NULL) {
    printf("failed realloc");
    free(temperatures);
    return 1;
  }

  temperatures = temp;

  // reallocate
  //  realloc(*temperatures,  (count+addedCount) * sizeof(float));
  // temperatures = realloc(temperatures, (count + addedCount) * sizeof(float));

  // get data from user dynamically
  for (int i = count; i < (new_total_count); i++) {
    printf("enter reading %d: ", i + 1);
    scanf("%f", &temperatures[i]);
  }
  // processing the data
  float sum = 0.0;
  for (int i = 0; i < (new_total_count); i++) {
    sum += temperatures[i];
  }
  float average = sum / (new_total_count);

  printf("results----\n");
  printf("recorded %d readings. \n", (count + addedCount));
  printf("average temperature: %.2f celc \n", average);

  free(temperatures);
  temperatures = NULL;
  return 0;
}
