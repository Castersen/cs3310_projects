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

	for(int i = 1; i <= 15; ++i) {
		std::tie(t1, t2) = generate_random_matrix(pow(2, i));
		pad_2d_matrix(t1);
		pad_2d_matrix(t2);

	    auto start = std::chrono::high_resolution_clock::now();
		classic_matrix_multiply(t1, t2);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Classic Matrix Multiply " << "Number: " << pow(2,i)
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;

	    start = std::chrono::high_resolution_clock::now();
		naive_divide_and_conquer(t1, t2);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Naive Divide and Conquer Matrix Multiply " << "Number: " << pow(2,i)
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;

	    start = std::chrono::high_resolution_clock::now();
		strassen_multiply(t1.size(), t1, t2);
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Algo: Strassen Matrix Multiply " << "Number: " << pow(2,i)
					 <<  " Time: " << duration.count() << " microseconds" << std::endl;
		std::cout << "\n\n";
	}
}