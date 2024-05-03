typedef struct hashType* hashTable;

hashTable createHT(void);
void addElementHT(hashTable*, char*, int);
void removeElementHT(hashTable*, char*);
int findValueHT(hashTable, char*);
void printHT(hashTable);
