// takes each character from the string, converts it to an int, and adds them
// together
int stringToInt(char* string) {
    int val = 0;
    for (int i = 0; i < strlen(string); i++) {
        val += (int)string[i];
    }
    return (val);
}
