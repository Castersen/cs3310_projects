#include "algorithms.h"
#include "matrix_operations.h"
#include <iostream>
#include <chrono>
#include <string>
#include "math.h"

int main() {
	// Sanity check
	// matrix_2d t1 = {{2,0,-1,6}, {3,7,8,0}, {-5,1,6,-2}, {8,0,1,7}};
	// matrix_2d t2 = {{0,1,6,3}, {-2,8,7,1}, {2,0,-1,0}, {9,1,6,-2}};

	matrix_2d t1, t2;
	int matrix_power = 2;

	for(int i = 1; i <= 1; ++i) {
		std::tie(t1, t2) = generate_random_matrices(pow(matrix_power, i));
		int number = pow(2, std::ceil(std::log(pow(matrix_power,i))/std::log(2)));
		pad_matrices_till_square(t1, t2);

	    auto start = std::chrono::high_resolution_clock::now();
		print_2d_matrix(classic_matrix_multiply(t1, t2));
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Classic Matrix Multiply " << "Number: " << number
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;

	    start = std::chrono::high_resolution_clock::now();
		print_2d_matrix(naive_divide_and_conquer(t1, t2));
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Naive Divide and Conquer Matrix Multiply " << "Number: " << number
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;

	    start = std::chrono::high_resolution_clock::now();
		print_2d_matrix(strassen_multiply(t1.size(), t1, t2));
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Strassen Matrix Multiply " << "Number: " << number
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;
		std::cout << "\n\n";
	}
}