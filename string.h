#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

size_t strLen(const char *string);
void stringCopy(char *receptor, const char *string);
unsigned strComp(const char *string1, const char *string2);
unsigned isAlpha(char ch);
unsigned isDigit(char ch);
size_t wordCounter(const char *string);
char *concatenate(char *string_1, char *string_2, unsigned total_strings, ...);
long int isSubstring(const char sub[], const char string[]);
void strUpr(char *string);
void strLwr(char *string);

#include "string.c"

#endif //STRING_H
