#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 10;
  printf("%d | %d\n", a, b);
  b ^= a;
  a ^= b;
  b ^= a;
  printf("%d | %d\n", a, b);
  return (0);
}
