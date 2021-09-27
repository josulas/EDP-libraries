# include "matrix.h"


void showMatrix(double **matrix, size_t rows, size_t columns){
    size_t i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("%le\t", matrix[i][j]);
        }
        puts("");
    }
}


double **newMatrix(size_t rows, size_t columns){
    double **new_matrix;
    size_t i, j;
    new_matrix = calloc(rows, sizeof(double));
    if(!new_matrix) return new_matrix;
    for(i = 0; i < rows; i++) {
        new_matrix[i] = calloc(columns, sizeof(double ));
        if(!new_matrix[i]) return new_matrix;
    }
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            new_matrix[i][j] = 0;
        }
    }
    return new_matrix;
}


double **transpose(const double **matrix, size_t rows, size_t columns){
    double **new_matrix;
    size_t i, j;
    new_matrix = newMatrix(rows, columns);
    if(!new_matrix) return new_matrix;
    for(i = 0; i < columns; i++){
        for(j = 0; j < rows; j++){
            new_matrix[i][j] = matrix[j][i];
        }
    }
    return new_matrix;
}


double **matrixSum(const double **matrixA, const double **matrixB, size_t rows, size_t columns){
    double **new_matrix;
    size_t i, j;
    new_matrix = newMatrix(rows, columns);
    if(!new_matrix) return new_matrix;
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            new_matrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return new_matrix;
}


double **matrixScalar(const double **matrix, const double scalar, size_t rows, size_t columns){
    double **new_matrix;
    size_t i, j;
    new_matrix = newMatrix(rows, columns);
    if(!new_matrix) return new_matrix;
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            new_matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return new_matrix;
}


double **matrixProduct(const double **matrixA, const double **matrixB, size_t rows1, size_t columns1, size_t columns2){
    double **new_matrix;
    size_t i, j, p;
    new_matrix = newMatrix(rows1, columns2);
    if(!new_matrix) return new_matrix;
    for(i = 0; i < rows1; i++){
        for(j = 0; j < columns2; j++){
            for(p = 0; p < columns1; p++){
                new_matrix[i][j] += matrixA[i][p] * matrixB[p][j];
            }
        }
    }
    return new_matrix;
}
