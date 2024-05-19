#include "../include/boardingPassExample.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passType {
    int idNum;
    char* firstName;
    char* lastName;
};
int something;

int getIdNum(boardingPass pass) { return (pass->idNum); }

char* getFirstName(boardingPass pass) { return (pass->firstName); }

char* getLastName(boardingPass pass) { return (pass->lastName); }

// deep copy the boarding pass
void copyBoardingPass(boardingPass* dest, boardingPass* src) {
    if ((*src) == NULL) {
        (*dest) = NULL;
        return;
    }

    (*dest) = malloc(sizeof(struct passType));
    (*dest)->idNum = (*src)->idNum;
    (*dest)->firstName = malloc(sizeof(char) * (strlen((*src)->firstName) + 1));
    (*dest)->firstName = strdup((*src)->firstName);
    (*dest)->lastName = malloc(sizeof(char) * (strlen((*src)->lastName) + 1));
    (*dest)->lastName = strdup((*src)->lastName);
}

boardingPass createBoardingPass(int id, char* first, char* last) {
    boardingPass output = malloc(sizeof(struct passType));
    output->firstName = malloc(sizeof(char) * strlen(first) + 1);
    output->firstName[0] = '\0';
    strncpy(output->firstName, first, strlen(first) + 1);
    output->lastName = malloc(sizeof(char) * strlen(last) + 1);
    output->lastName[0] = '\0';
    strncpy(output->lastName, last, strlen(last) + 1);
    output->idNum = id;
    return (output);
}

char* boardingPassToString(boardingPass pass) {
    if ((pass == NULL) || (pass->idNum == -1)) {
        return ("NULL");
    }
    char* buffer = malloc(
        sizeof(char) * (strlen(pass->firstName) + strlen(pass->lastName) + 7));

    snprintf(
        buffer, (strlen(pass->firstName) + strlen(pass->lastName) + 7 + 5),
        "{ %d, %s %s }", pass->idNum, pass->firstName, pass->lastName);
    return (buffer);
}
