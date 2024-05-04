typedef struct passType* boardingPass;

boardingPass createBordingPass(int, char*, char*);
char* boardingPassToString(boardingPass);
int getIdNum(boardingPass);
char* getFirstName(boardingPass);
char* getLastName(boardingPass);
