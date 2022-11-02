#include "algorithms.h"

// Standard Matrix Multiply O(n^3)
matrix_2d classic_matrix_multiply(matrix_2d m1, matrix_2d m2) {
	matrix_2d result = fill_matrix_with_zeroes(m1.size());
	int N = m1.size();

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			for(int k = 0; k < N; ++k)
				result[i][j] += m1[i][k] * m2[k][j];

	return result;
}

matrix_2d naive_divide_and_conquer(matrix_2d m1, matrix_2d m2) {
	matrix_2d C = fill_matrix_with_zeroes(m1.size());
	int N = m1.size();

	if(N == 1) {
		C[0][0] = m1[0][0] * m2[0][0];
		return C;
	} else {
		matrix_2d A11,A12,A21,A22,
				  B11,B12,B21,B22;

		std::tie(A11,A12,A21,A22) = split_matrix(m1);
		std::tie(B11,B12,B21,B22) = split_matrix(m2);

		matrix_2d C11 = add_2d_matrix(naive_divide_and_conquer(A11,B11),
									  naive_divide_and_conquer(A12,B21));

		matrix_2d C12 = add_2d_matrix(naive_divide_and_conquer(A11,B12),
									  naive_divide_and_conquer(A12,B22));

		matrix_2d C21 = add_2d_matrix(naive_divide_and_conquer(A21,B11),
									  naive_divide_and_conquer(A22,B21));

		matrix_2d C22 = add_2d_matrix(naive_divide_and_conquer(A21,B12),
									  naive_divide_and_conquer(A22,B22));

		C = combine_matrix(C11, C12, C21, C22);
	}

	return C;
}