#include "llist.h"

int main(void) {
  node test = createLListNode();
  int var = 1;
  char *something = "something";
  float f = 9.1112;
  double d = 9.22;
  int var2 = 2;
  llistAppend(test, f);
  llistAppend(test, something);
  llistAppend(test, something);
  llistAppend(test, var);
  llistAppend(test, d);
  llistPrepend(test, var2);
  llistAppend(test, var2);
  llistPrepend(test, something);
  llistPrepend(test, f);
  llistPrepend(test, d);
  printLList(test);
  freeLList(test);
  printLList(test);
  return (0);
}
