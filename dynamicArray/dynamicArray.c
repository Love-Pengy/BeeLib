//B. Frazier 3/17/24

#include "./dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define CHUNK_SIZE 50

struct listType{
    char *string;
    int size;
    int buffSize;
};

list createList(void) {
    list output = malloc(sizeof(struct listType));
    output->string = malloc(sizeof(char) * (CHUNK_SIZE + 1));
    output->string[0] = '\0';
    output->size = 0;
    output->buffSize = 50;
    return(output);
}

void expandList(list *expandee) {
    char *newList = malloc(sizeof(char) * ((*expandee)->buffSize + CHUNK_SIZE));
    strcpy(newList, (*expandee)->string);
    free((*expandee)->string);
    (*expandee)->string = newList;
    (*expandee)->buffSize = (*expandee)->buffSize + CHUNK_SIZE;
}

void listAppendList(list *dest, list source) {
    if(source) {
        while((*dest)->buffSize < ((*dest)->size + source->size + 1)){
            expandList(dest);
        }
        strcat((*dest)->string, source->string);
        (*dest)->size = ((*dest)->size + source->size);
    }
}

void listAppendString(list* dest, char* source){
    while(((strlen(source) + (*dest)->size) + 1) > (*dest)->buffSize) {
        expandList(dest);
    }
    strcat((*dest)->string, source);
    (*dest)->size = ((*dest)->size + strlen(source));
}

void prependString(list* dest, char* source) {
    while( ((strlen(source) + (*dest)->size) + 1) > (*dest)->buffSize) {
        expandList(dest);
    }
    snprintf((*dest)->string, (strlen(source)+1), "%s%s", source, (*dest)->string); 
    (*dest)->size = ((*dest)->size + strlen(source));
}

char *listToString(list printee) {
    return(printee->string);       
}

list stringToList(char *string) {
    list output = createList();
    listAppendString(&output, string);
    return(output);
}

void printList(list printee){
    printf("%s\n", listToString(printee));
}

void freeList(list goodbye) {
    free(goodbye->string);
    free(goodbye);
}