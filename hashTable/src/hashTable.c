#include "../include/hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max size would be 0 to k - 1
int HASH_CONSTANT = 101;

struct hashType {
    void** values;
};
typedef struct hashType* hashTable;

hashTable createHashTable(void) {
    hashTable meow = malloc(sizeof(struct hashType));
    meow->length = 0;
    return (meow);
}

int stringToInt(char* string) {
    int val = 0;
    for (int i = 0; i < strlen(string); i++) {
        val += (int)string[i];
    }
    return (val);
}

// hashes key and returns the index
int hashKey(char* key) {
    int keyVal = stringToInt(key);
    return (keyVal % HASH_CONSTANT);
}

void addElement(hashTable* table, char* key, void* value) {
    table->values[hashKey(key)] = malloc(sizeof(value));
    table->values[hashKey(key)] = value;
    table->length++;
}
