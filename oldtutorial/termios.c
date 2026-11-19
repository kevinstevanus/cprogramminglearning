#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig;

void reset_terminal(void) { tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig); }
int main(void) {
  // 1. save original terminal & switch to raw mode(no enter needed, no echo)
  tcgetattr(STDIN_FILENO, &orig);
  atexit(reset_terminal);

  struct termios raw = orig;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

  // 2. hardcoded 3 choices
  int choices[4] = {10, 20, 30, 40};
  int selected = 0;

  printf("pick a number up and down arrows \n");

  while (1) {
    for (int i = 0; i < 4; i++) {
      if (i == selected) {
        printf(" > %d\n", choices[i]);
      } else {
        printf("   %d\n", choices[i]);
      }
    }
    // read 1 byte from keyboard
    char c;
    read(STDIN_FILENO, &c, 1);
    if (c == '\n') {
      break;
    }

    // arrow keys send 3 bytes: '\033', '[', then 'A' (up) or 'B' down
    if (c == '\033') {
      char seq[2];
      read(STDIN_FILENO, &seq[0], 1);
      read(STDIN_FILENO, &seq[1], 1);

      if (seq[1] == 'A')
        selected = (selected - 1 + 4) % 4; // up
      if (seq[1] == 'B')
        selected = (selected + 1) % 4; // up
    }
    printf("\033[4A");
  }
  printf("you picked %d\n", choices[selected]);
  return 0;
}
