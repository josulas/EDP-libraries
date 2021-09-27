#ifndef SEARCH_SORTING_H
#define SEARCH_SORTING_H

#include <stdlib.h>
#include "statistics.h"

size_t* binarySearchLong(const long *array, size_t size, long value);
size_t* linearSearchLong(const long *array, size_t size, long value);
void swapLong(long *a, long *b);
void bubbleSortLong(long *array, size_t size);
void selectionSortLong(long *array, size_t size);
void insertionSortLong(long *array, size_t size);
void heapify(long *array, size_t size, size_t nodes);
void heapSortLong(long *array, size_t size);
void radixSortUnsignedLong(unsigned long *array, size_t size);

#include "search&sorting.c"

#endif //SEARCH_SORTING_H
