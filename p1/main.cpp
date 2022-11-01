#include "algorithms.h"
#include "matrix_operations.h"

int main() {
	matrix_2d t1 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	matrix_2d t2 = {{2,2,2,2}, {4,4,3,3}, {6,1,2,4}, {9,8,1,2}};

	print_2d_matrix(classic_matrix_multiply(t1, t2));
    matrix_2d a,b,c,d;
	std::tie(a,b,c,d) = split_matrix(t1);

	print_2d_matrix(a);
	print_2d_matrix(b);
	print_2d_matrix(c);
	print_2d_matrix(d);
}