#include "../include/boardingPassExample.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passType {
    int idNum;
    char* firstName;
    char* lastName;
};

int getIdNum(boardingPass pass) { return (pass->idNum); }

char* getFirstName(boardingPass pass) { return (pass->firstName); }

char* getLastName(boardingPass pass) { return (pass->lastName); }

boardingPass createBordingPass(int id, char* first, char* last) {
    boardingPass output = malloc(sizeof(struct passType));
    output->firstName = malloc(sizeof(char) * strlen(first));
    output->firstName[0] = '\0';
    strncpy(output->firstName, first, strlen(first) + 1);
    output->lastName = malloc(sizeof(char) * strlen(last));
    output->lastName[0] = '\0';
    strncpy(output->lastName, last, strlen(last) + 1);
    int idNum = rand() % 100000;
    return (output);
}

char* boardingPassToString(boardingPass pass) {
    if (pass->idNum == -1) {
        return ("NULL");
    }
    char* buffer = malloc(
        sizeof(char) * (strlen(pass->firstName) + strlen(pass->lastName) + 7));
    snprintf(
        buffer, (strlen(pass->firstName) + strlen(pass->lastName) + 7 + 1),
        "{ %d, %s %s }\n", pass->idNum, pass->firstName, pass->lastName);
    return (buffer);
}
