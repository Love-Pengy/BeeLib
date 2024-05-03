#include "../include/hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max size would be 0 to k - 1
int HASH_CONSTANT = 101;
#define MAX_SIZE 100

struct hashType {
    int* values;
};

hashTable createHT(void) {
    hashTable meow = malloc(sizeof(struct hashType));
    meow->values = malloc(sizeof(int) * MAX_SIZE);
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

void addElementHT(hashTable* table, char* key, int value) {
    (*table)->values[hashKey(key)] = value;
}

void removeElementHT(hashTable* table, char* key) {
    (*table)->values[hashKey(key)] = 0;
}

int findValueHT(hashTable table, char* key) {
    return (table->values[hashKey(key)]);
}

void printHT(hashTable table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == 0) {
            printf("{ %d, ", table->values[i]);
        } else if (i == (MAX_SIZE - 1)) {
            printf("%d }\n", table->values[i]);
        } else {
            printf("%d, ", table->values[i]);
        }
    }
}
