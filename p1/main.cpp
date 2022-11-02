#include "algorithms.h"
#include "matrix_operations.h"
#include <iostream>
#include "math.h"

int main() {
	// Sanity check
	// matrix_2d t1 = {{2,0,-1,6}, {3,7,8,0}, {-5,1,6,-2}, {8,0,1,7}};
	// matrix_2d t2 = {{0,1,6,3}, {-2,8,7,1}, {2,0,-1,0}, {9,1,6,-2}};

	matrix_2d t1, t2;
	for(int i = 1; i <= 10; ++i) {
		std::tie(t1, t2) = generate_random_matrix(pow(2, i));
		pad_2d_matrix(t1);
		pad_2d_matrix(t2);

		std::cout << "Classic Matrix Multiply\n";
		print_2d_matrix(classic_matrix_multiply(t1, t2));
		std::cout << std::endl;

		std::cout << "Naive Divide and Conquer Matrix Multiply\n";
		print_2d_matrix(naive_divide_and_conquer(t1, t2));
		std::cout << std::endl;

		std::cout << "Strassen Matrix Multiply\n";
		print_2d_matrix(strassen_multiply(t1.size(), t1, t2));
		std::cout << std::endl;
	}
}