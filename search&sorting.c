#include "search&sorting.h"

// This version could be called with an unsorted array and will not crash
size_t* binarySearchLong(const long *array, size_t size, long value){
    register size_t min = 0, max = size - 1;
    register size_t medium = (max + min) / 2;
    static size_t pos;
    register long actual;
    if(value == array[max]){
        pos = max;
        return &pos;
    }
    while (min < max){
        actual = array[medium];
        if(actual == value){
            pos = medium;
            return &pos;
        }
        if (medium == min) break;
        if(actual > value) max = medium;
        else min = medium;
        medium = (max + min) / 2;
    }
    return NULL;
}


size_t* linearSearchLong(const long *array, size_t size, long value){
    register size_t i;
    static size_t pos;
    for(i = 0; i < size; i++){
        if(value == array[i]){
            pos = i;
            return &pos;
        }
    }
    return NULL;
}


void swapLong(long *a, long *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void bubbleSortLong(long *array, size_t size){
    register size_t i, j;
    for( i= 0; i < size - 1; i++){
        for(j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j + 1]) swapLong(array + j, array + j + 1);
        }
    }
}


void selectionSortLong(long *array, size_t size){
    register size_t i, j;
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size ; j++){
            if(array[i] > array[j]) swapLong(array + i, array + j);
        }
    }
}


void insertionSortLong(long *array, size_t size){
    register size_t i, j;
    register long key;
    for(i = 1; i < size; i++){
        j = i - 1;
        key = array[i];
        while(j > 0 && array[j] > key){
            array[j + 1] = array[j];
            if(j) j--;
        }
        if(j) array[j + 1] = key;
        else array[j] = key;
    }
}


void heapify(long *array, size_t size, size_t max_parental){
    register size_t i;
    for(i = max_parental; i >= 0; i--){
        if (array[i] < array[2 * i + 1]) swapLong(array + i, array + 2 * i + 1);
        if (2 * i + 2 < size && array[i] < array[2 * i + 2]) swapLong(array + i, array + 2 * i + 2);
        if(!i) break;
    }
}


void heapSortLong(long *array, size_t size){
    register size_t i, max_parental;
    for(i = size; i > 1; i--){
        max_parental = i / 2 - 1;
        heapify(array, i, max_parental);
        swapLong(array, array + i - 1);
    }
}


void radixSortUnsignedLong(unsigned long *array, size_t size){
    unsigned long bucket[10][size];
    size_t bucket_counter[10];
    register size_t k, l;
    unsigned long max = maxUnsignedLongArray(array, size);
    register unsigned digits = 1, i, j;
    register unsigned long divisor = 1;
    while(max) if(max /= 10) digits++;
    for(i = 0; i < digits; i++){
        for(j = 0; j < 10; j++) bucket_counter[j] = 0;
        for(k = 0; k < size; k++){
            bucket[(array[k] / divisor) % 10][bucket_counter[(array[k] / divisor) % 10]] = array[k];
            bucket_counter[(array[k] / divisor) % 10] += 1;
        }
        k = 0;
        for(j = 0; j < 10; j++){
            for(l = 0; l < bucket_counter[j]; l++) array[k++] = bucket[j][l];
        }
        divisor *= 10;
    }
}
