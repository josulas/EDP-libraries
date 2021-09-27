#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

char *inputString(FILE* fp, size_t size);
long int inputLong();
long unsigned inputLongUnsigned();
size_t inputSize_t();
double inputDouble();

#include "input&output.c"

#endif //INPUT_OUTPUT_H
