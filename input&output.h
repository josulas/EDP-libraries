#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#define MiB 1048576
#define MAX_SHORT_CHARACTERS 6
#define MAX_U_SHORT_CHARACTERS 5
#define MAX_LONG_CHARACTERS 11
#define MAX_U_LONG_CHARACTERS 10
#define MAX_LONG_LONG_CHARACTERS 20
#define MAX_U_LONG_LONG_CHARACTERS 20
#define MAX_FLOAT_CHARACTERS 47
#define MAX_U_FLOAT_CHARACTERS 46
#define MAX_DOUBLE_CHARACTERS 347
#define MAX_U_DOUBLE_CHARACTERS 346

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void flush(FILE *ptr);
char *inputShortString(size_t len, unsigned *verifier);
char *inputString(FILE* fp, size_t size);
long int inputLong();
long unsigned inputLongUnsigned();
size_t inputSize_t();
double inputDouble();

#include "input&output.c"

#endif //INPUT_OUTPUT_H
