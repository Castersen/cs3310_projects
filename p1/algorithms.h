
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "matrix_operations.h"

matrix_2d classic_matrix_multiply(matrix_2d m1, matrix_2d m2);
matrix_2d naive_divide_and_conquer(matrix_2d m1, matrix_2d m2);
matrix_2d strassen_multiply(int n, matrix_2d m1, matrix_2d m2);

#endif