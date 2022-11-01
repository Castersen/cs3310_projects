#include "algorithms.h"

// Standard Matrix Multiply O(n^3)
matrix_2d classic_matrix_multiply(matrix_2d m1, matrix_2d m2) {
	matrix_2d result;
	std::vector<int> temp;
	int acc = 0, N = m1.size();

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k) {
				acc += m1[i][k] * m2[k][j];
			}
			temp.push_back(acc);
			acc = 0;
		}
		result.push_back(temp);
		temp.clear();
	}

	return result;
}