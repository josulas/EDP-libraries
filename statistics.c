#include "statistics.h"

long maxLongArray(const long int *array, size_t length){
    size_t i;
    long max;
    max = array[0];
    for (i = 1; i < length; i++){
        if (array[i] > max) max = array[i];
    }
    return max;
}


long maxUnsignedLongArray(const unsigned long *array, size_t length){
    size_t i;
    unsigned long max;
    max = array[0];
    for (i = 1; i < length; i++) if (array[i] > max) max = array[i];
    return max;
}


long minLongArray(const long int *array, size_t length){
    size_t i;
    long min;
    min = array[0];
    for (i = 1; i < length; i++){
        if (array[i] < min) min = array[i];
    }
    return min;
}

double averageLongArray(const long int array[], size_t length){
    if (!length) return 0;   
    double sum = 0.0;
    for (int i = 0; i < length; i++){
        sum += array[i]; 
    }
    return sum / length;
}


double varianceLongArray(const long int array[], size_t length){
    if (!length) return 0;  
    double sum = 0.0, average;
    average = averageLongArray(array, length);
    for (int i = 0; i < length; i++){
        sum += (array[i] - average) * (array[i] - average); 
    }
    return sum / length;
}


double devEstLongArray(const long int array[], size_t length){
    double variance = varianceLongArray(array, length);
    return sqrt(variance);
}


long int **frequenciesLongArray(const long int *array, size_t length, size_t *mat_len){
    size_t mat_size = 16;
    size_t increment = 16;
    long unsigned int i, j;
    int in_mat;
    long int actual, **freq_matrix;
    freq_matrix = (long int**) calloc(mat_size, sizeof(long int));
    if (!freq_matrix) return freq_matrix;
    for (i = 0; i < length; i++){
        actual = array[i];
        in_mat = 0;
        for (j = 0; j < *mat_len; j++){
            if (freq_matrix[j][0] == actual){
                in_mat = 1;
                freq_matrix[j][1]++;
                break;
            }
        }
        if(!in_mat){
            freq_matrix[*mat_len] = (long int*) calloc(2, sizeof(long int));
            if (!freq_matrix[*mat_len]) return freq_matrix;
            freq_matrix[*mat_len][0] = actual;
            freq_matrix[*mat_len][1] = 1;
            *mat_len += 1;
        }
        if (mat_size == *mat_len) {
            freq_matrix = (long int**) realloc(freq_matrix, sizeof(long int) * (mat_size += increment));
            if (!freq_matrix) return freq_matrix;
        }
    }
    return freq_matrix;
}

