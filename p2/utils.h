#ifndef UTILS_H
#define UTILS_H

#include <vector>

int random_number_generator(int starting_range, int ending_range);
int random_number_generator_with_exclusion(int starting_range, int ending_range, std::vector<int> values_to_exclude);
std::vector<std::vector<int>> generate_dense_adjacency_matrix(int dimension, int starting_range, int ending_range);
std::vector<std::vector<int>> generate_sparse_adjacency_matrix(int dimension, int starting_range, int ending_range);

#endif