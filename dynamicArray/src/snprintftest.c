#include <stdio.h>
#include <string.h>

int main() {
    char string1[10] = "meow";
    char string2[10] = "meow2";
    char string3[40];

    snprintf(string3, 20, "%s%s", string1, string2);
    strcat(string3, string1);
    printf("RESULT: %s\n", string3);

    return 0;
}
