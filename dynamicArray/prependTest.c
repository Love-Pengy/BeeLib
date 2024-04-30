#include "dynamicArray.h"

int main() {
    list tester = createList();
    prependString(&tester, "test1");
    printList(tester);
    freeList(tester);
    tester = createList();
    prependString(&tester, "test1");
    listAppendList(&tester, tester);
    printList(tester);
}
