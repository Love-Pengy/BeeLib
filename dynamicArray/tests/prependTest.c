#include <stdio.h>

#include "../include/dynamicArray.h"

int main() {
    list tester = createList();
    listAppendString(&tester, "something");
    prependString(&tester, "\n");
    listAppendList(&tester, tester);
    listAppendString(&tester, "       ");
    listAppendString(&tester, "end");
    printList(tester);
}
