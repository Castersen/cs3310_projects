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

	if(N == 2) {
		C[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
		C[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
		C[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
		C[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
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

/*
* Will multiply two matricies together using the Strassen method.
* n: The size of the 2d array.
* A: The first matrix to multiply.
* B: The second matrix to multiply.
*/
matrix_2d strassen_multiply(int n, matrix_2d A, matrix_2d B){
	matrix_2d result = fill_matrix_with_zeroes(A.size());
	if(n == 2) {
		result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
		result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
		result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
		result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
		return result;
	}
   matrix_2d A11, A12, A21, A22,
				 B11, B12, B21, B22;
	std::tie(A11, A12, A21, A22) = split_matrix(A);
	std::tie(B11, B12, B21, B22) = split_matrix(B);
	matrix_2d P1 = strassen_multiply(n/2, A11, subtract_2d_matrix(B12, B22));
	matrix_2d P2 = strassen_multiply(n/2, add_2d_matrix(A11, A12), B22);
	matrix_2d P3 = strassen_multiply(n/2, add_2d_matrix(A21, A22), B11);
	matrix_2d P4 = strassen_multiply(n/2, A22, subtract_2d_matrix(B21, B11));
	matrix_2d P5 = strassen_multiply(n/2, add_2d_matrix(A11, A22), add_2d_matrix(B11, B22));
	matrix_2d P6 = strassen_multiply(n/2, subtract_2d_matrix(A12 , A22), add_2d_matrix(B21, B22));
	matrix_2d P7 = strassen_multiply(n/2, subtract_2d_matrix(A11, A21), add_2d_matrix(B11, B12));

	matrix_2d C11 = add_2d_matrix(subtract_2d_matrix(P4, P2), add_2d_matrix(P5, P6));
	matrix_2d C12 = add_2d_matrix(P1, P2);
	matrix_2d C21 = add_2d_matrix(P3, P4);
	matrix_2d C22 = add_2d_matrix(subtract_2d_matrix(P1, P3), subtract_2d_matrix(P5, P7));

	matrix_2d C = combine_matrix(C11, C12, C21, C22);
	return C;
}