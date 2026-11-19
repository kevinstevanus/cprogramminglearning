https : // brennan.io/2015/01/16/write-a-shell-in-c/
#include <cstdio>
#include <stdlib.h>
#define LSH_RL_BUFSIZE 1024
        char *lsh_read_line(void) {
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(FILE *__restrict stream, const char *__restrict format, ...)
  }
}
void lsh_loop(void) {
  char *line;
  char **args;
  int status;
  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);

  } while (status);
}
int main(int argc, char **argv) {

  // load config files, if any

  // command loop
  lsh_loop();

  // cleanup shutdown
  //
  return EXIT_SUCCESS;
}
