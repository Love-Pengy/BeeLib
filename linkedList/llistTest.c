#include "llist.h"

int main(void) {
  node test = createLListNode();
  int var = 1;
  char something[] = "something";
  float f = 9.1112;
  double d = 9.22;
  int var2 = 2;
  llistPrepend(test, "somethingMore");
  llistPrepend(test, something);

  printLList(test);
  freeLList(test);
  printLList(test);
  return (0);
}
