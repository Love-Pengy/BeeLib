#include <stdlib.h>

char* charToStr(char input) {
    char* output = malloc(sizeof(char) * 2);
    output[0] = input;
    output[1] = '\0';
    return (output);
}
