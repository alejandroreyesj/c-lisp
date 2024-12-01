#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char *readline(char *prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char *cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/history.h>
#include <editline/readline.h>
#endif

int main(int argc, char **argv) {

  puts("Welcome!");
  puts("Lispy Version 0.0.0.0.2");
  puts("Press CTRL+c to Exit");

  while (true) {

    char *input = readline("c-lisp> ");
    add_history(input);

    printf("No you're a %s\n", input);
    free(input);
  }
  return 0;
}
