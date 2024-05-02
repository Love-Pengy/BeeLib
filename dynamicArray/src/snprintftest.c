#include <stdio.h>
#include <string.h>

int main() {
    char string1[10] = "meow";
    char string2[10] = "meow2";
    char string3[100];

    snprintf(string3, 20, "%s%s", string1, string2);
    printf("TEST: %s\n", string3);
    snprintf(string3, (sizeof(string3) * 2), "%s%s", string3, string3);
    return 0;
}
