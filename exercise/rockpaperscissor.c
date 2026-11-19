#include <stdbool.h>
#include <stdio.h>
enum choices { ROCK, PAPER, SCISSOR };
enum choices getUserChoice() {
  printf("getting user choice..\n");
  printf("hello there\n");
  return ROCK;
}
enum choices lettingAiChoose() {
  printf("this ai is thinking..\n");
  printf("this ai is thinking..\n");
  return PAPER;
}
bool didYouWin(enum choices humanChoice, enum choices aiChoice) {

  if (humanChoice == ROCK && aiChoice == PAPER) {
    return 0;
  }
}
int main() {
  enum choices humanChoice = getUserChoice();
  enum choices aiChoice = lettingAiChoose();

  bool isHumanWon = didYouWin(humanChoice, aiChoice);

  if (isHumanWon) {
    printf("congrats you've won");
  } else {
    printf("congrats you've lose");
  }
  return 0;
}
