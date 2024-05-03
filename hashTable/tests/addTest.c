#include <stdio.h>

#include "../include/hashTable.h"

int main() {
    hashTable test = createHT();
    addElementHT(&test, "key1", 1982);
    addElementHT(&test, "laskjhf", 2001);
    addElementHT(&test, "kasdlfkj", 2002);
    addElementHT(&test, "keyalskdj2ck", 2003);
    addElementHT(&test, "key2", 2091);
    addElementHT(&test, "Key2", 002);
    printHT(test);
    return 0;
}
