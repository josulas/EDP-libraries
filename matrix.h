#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

void showMatrix(double **matrix, size_t rows, size_t columns);
double **newMatrix(size_t rows, size_t columns);
double **transpose(const double **matrix, size_t rows, size_t columns);
double **matrixSum(const double **matrixA, const double **matrixB, size_t rows, size_t columns);
double **matrixScalar(const double **matrix, const double scalar, size_t rows, size_t columns);
double **matrixProduct(const double **matrixA, const double **matrixB, size_t rows1, size_t columns1, size_t columns2);

#include "matrix.c"

#endif //MATRIX_H
