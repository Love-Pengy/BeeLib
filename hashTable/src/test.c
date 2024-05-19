#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    /*
    char** strings = malloc(sizeof(char*) * 2);
    strings[0] = "strings0";
    strings[1] = "strings1";
    printf("%ld\n", sizeof(strings));
    strings = reallocarray(strings, 3, (sizeof(char*)));
    printf("%ld\n", sizeof(strings));
    printf("%s %s\n", strings[0], strings[1]);
    strings[2] = "strings2";
    printf("%s\n", strings[2]);
    char* string1 = malloc(sizeof(char) * 10);
    strcpy(string1, "meow");
    char* string2 = malloc(sizeof(char) * 10);
    string2 = strdup(string1);
    free(string1);
    printf("%s\n", string2);
    */
    printf("%ld\n", sizeof(NULL));
}
