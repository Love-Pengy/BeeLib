#include "../include/hashTable.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/boardingPassExample.h"

// max size would be 0 to k - 1
#define HASH_CONSTANT 3
#define CONST_MULTIPLIER 287987
int MAX_SIZE = 3;

// example using border passes
struct hashType {
    boardingPass* passes;
    char** keys;
};

bool keyExists(hashTable table, char* key) {
    bool found = false;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (!strcmp(key, table->keys[i])) {
            found = true;
            break;
        }
    }
    if (found) {
        return (true);
    }
    return (false);
}

hashTable createHT(void) {
    hashTable meow = malloc(sizeof(struct hashType));
    meow->passes = malloc(sizeof(boardingPass) * MAX_SIZE);
    meow->keys = malloc(sizeof(char*) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        meow->passes[i] = NULL;
        meow->keys = malloc(sizeof(NULL));
        meow->keys[i] = NULL;
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
int hashKey(char* key, int numCollisions) {
    // get to the end and then start at 0 with your current offsets
    int keyVal = asciiSum(key);
    int hash = (CONST_MULTIPLIER * keyVal) % HASH_CONSTANT;
    if ((hash + numCollisions) > MAX_SIZE) {
        return (numCollisions - (MAX_SIZE - hash));
    }
    return (hash + numCollisions);
}

void addElementHT(hashTable* table, char* key, boardingPass value) {
    int numCollisions = 0;
    bool notFull = true;
    while ((*table)->passes[hashKey(key, numCollisions)] != NULL) {
        if (numCollisions == MAX_SIZE) {
            printf("HIT END OF TABLE\n");
            notFull = false;
            break;
        }
        numCollisions++;
    }
    if (notFull) {
        (*table)->passes[hashKey(key, numCollisions)] =
            malloc(sizeof(struct hashType));
        (*table)->passes[hashKey(key, numCollisions)] = value;

        (*table)->keys[hashKey(key, numCollisions)] =
            malloc(sizeof(char) * strlen(key) + 1);
        strcpy((*table)->keys[hashKey(key, numCollisions)], key);
    }
}

void removeElementHT(hashTable* table, char* key) {
    printHT((*table));
    int offset = 0;
    bool found = false;
    // THIS NEEDS TO BE BASED OFF OF HASH VALUES NOT SEQUENTIAL
    for (int i = 0; i < MAX_SIZE; i++) {
        if ((*table)->keys[i] == NULL) {
            continue;
        }
        if (!strcmp(key, (*table)->keys[i])) {
            offset = i;
            found = true;
            break;
        }
    }
    if (found) {
        free((*table)->keys[hashKey(key, offset)]);
        free((*table)->passes[hashKey(key, offset)]);

        (*table)->passes[hashKey(key, offset)] =
            malloc(sizeof(struct hashType));
        (*table)->passes[hashKey(key, offset)] = NULL;

        (*table)->keys[hashKey(key, offset)] = malloc(sizeof(struct hashType));
        (*table)->keys[hashKey(key, offset)] = NULL;
    }
}

boardingPass findValueHT(hashTable table, char* key) {
    return (table->passes[hashKey(key, 0)]);
}

void printHT(hashTable table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == 0) {
            printf(
                "{ %s: %s, ", table->keys[i],
                boardingPassToString(table->passes[i]));
        }

        else if (i == (MAX_SIZE - 1)) {
            printf(
                "%s: %s }\n", table->keys[i],
                boardingPassToString(table->passes[i]));
        }

        else {
            printf(
                "%s: %s, ", table->keys[i],
                boardingPassToString(table->passes[i]));
        }
    }
}
