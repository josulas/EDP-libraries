#ifndef STATISTICS_H
#define STATISTICS_H

#include <math.h>
#include <stdlib.h>

long maxLongArray(const long int *array, size_t length);
long maxUnsignedLongArray(const unsigned long *array, size_t length);
long minLongArray(const long int *array, size_t length);
double averageLongArray(const long int array[], size_t length);
double varianceLongArray(const long int array[], size_t length);
double devEstLongArray(const long int array[], size_t length);
long int **frequenciesLongArray(const long int *array, size_t length, size_t *mat_len);

#include "statistics.c"

#endif //STATISTICS_H
