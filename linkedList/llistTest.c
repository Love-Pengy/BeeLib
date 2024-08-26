#include "llist.h"

int main(void) {
  node test = createLListNode();
  int var = 1;
  char *something = "something";
  float f = 9.1112;
  double d = 9.22;
  int var2 = 2;
  llistAppend(test, something);
  llistPrepend(test, "somethingMore");

  printLList(test);
  freeLList(test);
  printLList(test);
  return (0);
}
