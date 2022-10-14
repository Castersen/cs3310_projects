#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix_2d;

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

void print_2d_matrix(matrix_2d m) {
	for(int i = 0; i < m.size(); ++i) {
		for(int j = 0; j < m[i].size(); ++j) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	matrix_2d t1 = {{2,1,3,4}, {4,4,4,5}, {5,5,5,5}, {6,6,6,6}};
	matrix_2d t2 = {{2,2,2,2}, {4,4,3,3}, {6,1,2,4}, {9,8,1,2}};

	print_2d_matrix(classic_matrix_multiply(t1, t2));
}
