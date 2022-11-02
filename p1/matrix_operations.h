
#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include <vector>
#include <tuple>

typedef std::vector<std::vector<int>> matrix_2d;

void print_2d_matrix(matrix_2d m);
void pad_2d_matrix(matrix_2d& m);
matrix_2d slice_2d_matrix(matrix_2d m, int x0, int x1, int y0, int y1);
matrix_2d add_2d_matrix(matrix_2d m1, matrix_2d m2);
matrix_2d subtract_2d_matrix(matrix_2d m1, matrix_2d m2);
std::vector<int> fill_array_with_zeroes(int size);
matrix_2d fill_matrix_with_zeroes(int size);
std::tuple<matrix_2d, matrix_2d, matrix_2d, matrix_2d> split_matrix(matrix_2d m);
std::vector<int> add_1d_array(std::vector<int> a1, std::vector<int> a2);
matrix_2d combine_matrix(matrix_2d m1, matrix_2d m2, matrix_2d m3, matrix_2d m4);

# endif
