#include <stdio.h>

struct point {
  float x;
  float y;
};

int main(int argc, char **argv) {
  struct point p;
  p.x = 0.1;
  p.y = 10.0;
  printf("x = %2.2f\n", p.x);
  printf("y = %2.2f\n", p.y);

  for (int i = 0; i < 100; i++) {
    puts("Loop Interation");
    printf("%d\n", i);
  }
}
