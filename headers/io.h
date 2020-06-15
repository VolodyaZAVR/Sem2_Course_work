#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void cls();

char **simple_split(char *str, int length, char sep);

int safe_scand();

float safe_scanf();

char *safe_scans();

#endif // IO_H_INCLUDED
