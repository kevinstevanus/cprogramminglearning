#include <stdio.h>

struct Player {
  char name[50];
  int health;
  int score;
};

int main() {
  struct Player p1;
  p1.health = 100;
  p1.score = 999;

  printf("health: %d, score: %d\n", p1.health, p1.score);
  return 0;
}
