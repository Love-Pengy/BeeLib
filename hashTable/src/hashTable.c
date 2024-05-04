#include "../include/hashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/boardingPassExample.h"

// max size would be 0 to k - 1
int HASH_CONSTANT = 101;
#define MAX_SIZE 100

// example using border passes
struct hashType {
    boardingPass* passes;
};

hashTable createHT(void) {
    hashTable meow = malloc(sizeof(struct hashType));
    meow->passes = malloc(sizeof(boardingPass) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        meow->passes[i] = NULL;
    }
    return (meow);
}

int asciiSum(char* string) {
    int val = 0;
    for (int i = 0; i < strlen(string); i++) {
        val += (int)string[i];
    }
    return (val);
}

// hashes key and returns the index
int hashKey(char* key) {
    int keyVal = asciiSum(key);
    return (keyVal % HASH_CONSTANT);
}

void addElementHT(hashTable* table, char* key, boardingPass value) {
    (*table)->passes[hashKey(key)] = value;
}

void removeElementHT(hashTable* table, char* key) {
    (*table)->passes[hashKey(key)] = NULL;
}

boardingPass findValueHT(hashTable table, char* key) {
    return (table->passes[hashKey(key)]);
}

void printHT(hashTable table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == 0) {
            printf("{ %s, ", boardingPassToString(table->passes[i]));
        }

        else if (i == (MAX_SIZE - 1)) {
            printf("%s }\n", boardingPassToString(table->passes[i]));
        }

        else {
            printf("%s, ", boardingPassToString(table->passes[i]));
        }
    }
}
