#pragma once
#include <stdio.h>
void logErr(char* , int , char *, ...);
void logWarn(char *, ...);
void fileLog(char *, ...);
#define LOGFILE "log"
#define LOG(s, data...) logErr(__FILE__, __LINE__, s, ##data)
