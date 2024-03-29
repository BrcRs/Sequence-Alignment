#ifndef TOOLS_H
#define TOOLS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "debug.h"

#define MAX(x, y) (x < y ? y : x)
#define MIN(x, y) (x < y ? x : y)

#define MAXBUFFER 255


//#define MALLOC(n, x) ((x*)malloc(sizeof(x) * n))


char* tools_basename( char* src);

int tools_LineInFile(char* line, char* filename);
int tools_LineInFILE(char** line, FILE* f);


int tools_countZerosInTab(int * tab, int size);

char* tools_suppressChar(char* dest, char* src, const char sup );

int tools_LS(char* folderName);


#endif
