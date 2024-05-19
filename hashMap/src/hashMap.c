#include "hashMap.h"

#include <stdlib.h>

#include "../lib/include/hashTable.h"

struct hashMapType {
    hashTable table;
};

hashMap createHashMap(hashTable input) {
    hashMap output = malloc(sizeof(struct hashMapType));
    output->table = input;
    return (output);
}

void addElementHM(hashMap* map, char* key, boardingPass value) {
    if (!findValueHT((*map)->table, key)) {
        addElementHT(&((*map)->table), key, value);
    }
    else {
        updateValueHT(&((*map)->table), key, value);
    }
}

void removeElementHM(hashMap* map, char* key) {
    removeElementHT(&((*map)->table), key);
}

boardingPass findValueHM(hashMap map, char* key) {
    return (findValueHT((map)->table, key));
}
