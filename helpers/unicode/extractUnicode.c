#include <uchar.h>
#include <locale.h>

// extracts first unicode character from a given string
char* extractUnicode(const char* input) {
    printf("INPUT: %s\n", input);
    char* buff = malloc(sizeof(char) * MB_CUR_MAX);
    buff[0] = '\0';
    char* test = malloc(sizeof(char) * (strlen(input) + 2));
    test[0] = '\0';
    strncpy(test, input, strlen(input) + 1);
    printf("TEST: %s\n", test);
    char32_t specChar;
    mbstate_t mbs;
    char* locale = setlocale(LC_ALL, "");

    if (!locale) {
        obs_log(LOG_ERROR, "Locale Could Not Be Set");
        free(buff);
        return (NULL);
    }
    memset(&mbs, 0, sizeof(mbs));

    size_t size = mbrtoc32(&specChar, test, 16, &mbs);
    if (size == (size_t)-1 || size == (size_t)-2) {
        obs_log(LOG_WARNING, "Unicode Character Not Found");
        return (NULL);
    }
    int cpy = c32rtomb(buff, specChar, &mbs);
    printf("CPY: %d\n", cpy);
    if (cpy < 0) {
        obs_log(LOG_ERROR, "Failed To Convert Unicode Character");
        return (NULL);
    }
    // ASSUMED: if cpy = 1 then its a normal character not a nerdfont character
    else if (cpy == 1) {
        return (test);
    }
    // ensure that string gets terminated in the correct spot
    buff[cpy] = '\0';
    printf("BUFF: %s\n", buff);
    return (buff);
}

