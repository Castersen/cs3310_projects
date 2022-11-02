#include <iostream>
#include <tuple>
#include "math.h"
#include <cstdlib>
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

void pad_matrices_till_square(matrix_2d& m1, matrix_2d& m2) {
    // If both are already square matrices of the same size no need to pad
    if((m1.size() == m2.size()) and (m1[0].size() == m2[0].size())
        and (pow(2,std::floor(std::log(m1.size()*m1[0].size())/std::log(2))) 
                == m1.size()*m1[0].size())) 
    {
            return;
    }
    int m1_largest_side = std::max(m1.size(), m1[0].size());
    int m2_largest_side = std::max(m2.size(), m2[0].size());
    int largest_side = std::max(m1_largest_side, m2_largest_side);

    // used to determine the next closest power of 2, idea
    // 2^n = 12 -> nln(2) = ln(12) -> n = ln(12)/ln(2) n = 3.54
    // now if we take the ceiling we know the next closest power of 2
    // is 2^4 = 16, so that is our padding constant
    int padding_constant = pow(2, std::ceil(std::log(largest_side)/std::log(2)));

    // pad columns with 0s
    std::vector<int> m1_pad_col(padding_constant-m1[0].size());
    std::vector<int> m2_pad_col(padding_constant-m2[0].size());
    for(int i = 0; i < m1.size(); ++i)
        m1[i].insert(m1[i].end(), m1_pad_col.begin(), m1_pad_col.end());
    for(int i = 0; i < m2.size(); ++i)
        m2[i].insert(m2[i].end(), m2_pad_col.begin(), m2_pad_col.end());

    // pad rows with 0s
    std::vector<int> row_pad(largest_side);
    int m1_number_of_rows_to_add = padding_constant - m1.size();
    int m2_number_of_rows_to_add = padding_constant - m2.size();
    for(int i = 0; i < m1_number_of_rows_to_add; ++i)
        m1.push_back(row_pad);
    for(int i = 0; i < m2_number_of_rows_to_add; ++i)
        m2.push_back(row_pad);
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
    matrix_2d result = fill_matrix_with_zeroes(m1.size());
    int N = m1.size();

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            result[i][j] = m1[i][j] + m2[i][j];

    return result;
}

matrix_2d subtract_2d_matrix(matrix_2d m1, matrix_2d m2) {
    matrix_2d result = fill_matrix_with_zeroes(m1.size());
    int N = m1.size();

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            result[i][j] = m1[i][j] - m2[i][j];

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

std::vector<int> fill_array_with_zeroes(int size) {
    std::vector<int> result(size);
    return result;
}

matrix_2d fill_matrix_with_zeroes(int size) {
    matrix_2d result(size, std::vector<int>(size));
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

std::tuple<matrix_2d, matrix_2d> generate_random_matrices(int size) {
    matrix_2d m1 = fill_matrix_with_zeroes(size);
    matrix_2d m2 = fill_matrix_with_zeroes(size);

    srand((unsigned) time(NULL));

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            m1[i][j] = 50 - rand() % 150;
            m2[i][j] = 50 - rand() % 150;
        }
    }

    return std::make_tuple(m1, m2);
}