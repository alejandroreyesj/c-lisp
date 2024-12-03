#include "mpc.h"
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

  mpc_parser_t *Number = mpc_new("number");
  mpc_parser_t *Operator = mpc_new("operator");
  mpc_parser_t *Expr = mpc_new("expr");
  mpc_parser_t *Lispy = mpc_new("lispy");

  mpca_lang(MPCA_LANG_DEFAULT, "                                               \
      number: /-?[0-9]+/;                           \
      operator: '+' | '-' | '*' | '/';              \
      expr: <number> | '(' | <operator> <expr>+ ')';\
      lispy: /^/ <operator> <expr>+ /$/;            \
    ",
            Number, Operator, Expr, Lispy);

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