#include <iostream>
#include <tuple>
#include "matrix_operations.h"

void print_2d_matrix(matrix_2d m) {
    int N = m.size();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

matrix_2d slice_2d_matrix(matrix_2d m, int x0, int x1, int y0, int y1) {
    matrix_2d result;
    std::vector<int> temp;

    for( ; y0 < y1; ++y0 ) {
        for(int col = x0; col < x1; ++col) {
            temp.push_back(m[y0][col]);
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

matrix_2d add_2d_matrix(matrix_2d m1, matrix_2d m2) {
    matrix_2d result;
    std::vector<int> temp;
    int N = m1.size();

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            temp.push_back(m1[j][i] + m2[j][i]);
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

matrix_2d subtract_2d_matrix(matrix_2d m1, matrix_2d m2) {
    matrix_2d result;
    std::vector<int> temp;
    int N = m1.size();

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            temp.push_back(m1[j][i] - m2[j][i]);
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

// Used to divide the matrix into 4 submatrices
std::tuple<matrix_2d, matrix_2d, matrix_2d, matrix_2d> split_matrix(matrix_2d m) {
    int N = m.size();
    matrix_2d q1 = slice_2d_matrix(m, 0, N/2, 0, N/2);
    matrix_2d q2 = slice_2d_matrix(m, N/2, N, 0, N/2);
    matrix_2d q3 = slice_2d_matrix(m, 0, N/2, N/2, N);
    matrix_2d q4 = slice_2d_matrix(m, N/2, N, N/2, N);

    return std::make_tuple(q1, q2, q3, q4);
}

matrix_2d fill_matrix_with_zeroes(int size) {
    matrix_2d result;
    std::vector<int> temp;

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            temp.push_back(0);
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

void merge_2d_matrix(matrix_2d& z, matrix_2d m, int x0, int x1, int y0, int y1) {
    for(int j = 0; y0 < y1; ++y0, ++j)
        for(int col = x0, k = 0; col < x1; ++col, ++k)
            z[y0][col] = m[j][k];
}

matrix_2d combine_matrix(matrix_2d m1, matrix_2d m2, matrix_2d m3, matrix_2d m4) {
    matrix_2d combined = fill_matrix_with_zeroes(m1.size() * 2);
    int N = combined.size();

    merge_2d_matrix(combined, m1, 0, N/2, 0, N/2);
    merge_2d_matrix(combined, m2, N/2, N, 0, N/2);
    merge_2d_matrix(combined, m3, 0, N/2, N/2, N);
    merge_2d_matrix(combined, m4, N/2, N, N/2, N);

    return combined;
}