#ifndef TOOLS_H
#define TOOLS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(x, y) (x < y ? y : x)
#define MIN(x, y) (x < y ? x : y)

//#define MALLOC(n, x) ((x*)malloc(sizeof(x) * n))


char* tools_basename( char* src);

int tools_LineInFile(char* line, char* filename);
int tools_countZerosInTab(int * tab, int size);

char* tools_suppressChar(char* dest, char* src, const char sup );


#endif
