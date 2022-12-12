#include <vector>
#include <random>
#include <chrono>
#include <climits>

int random_number_generator(int starting_range, int ending_range) {
    // Seed the random number generator
    std::default_random_engine generator ( std::random_device{}() );

    std::uniform_int_distribution <int>distribution (starting_range, ending_range); 
    return distribution(generator);
}

// Generate dense adjacency matrix
std::vector<std::vector<int>> generate_dense_adjacency_matrix(int dimension, int starting_range, int ending_range) {
    std::vector<std::vector<int>> adjacency_matrix(dimension, std::vector<int>(dimension));
    int temp_starting_range = starting_range;
    int max_neg_value;
    if(starting_range < 0) {
        max_neg_value = dimension * starting_range;
        temp_starting_range = (max_neg_value * -1) + 1;
    }

    ending_range = temp_starting_range + ending_range;

    for(int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            if(i == j) { 
                adjacency_matrix[i][j] = 0; 
                continue;
            }

            int neg_value = random_number_generator(0, 1);
            if(starting_range < 0 and neg_value) {
                adjacency_matrix[i][j] = random_number_generator(starting_range, -1);
                if(j < i && adjacency_matrix[i][j] < 0) {
                    adjacency_matrix[i][j] = (adjacency_matrix[i][j] * -1) + temp_starting_range;
                }
                continue;
            }
            if(starting_range < 0) {
                adjacency_matrix[i][j] = random_number_generator(temp_starting_range, ending_range);
                if(j < i && adjacency_matrix[i][j] < 0) {
                    adjacency_matrix[i][j] = (adjacency_matrix[i][j] * -1) + temp_starting_range;
                }
                continue;
            }

            adjacency_matrix[i][j] = random_number_generator(temp_starting_range, ending_range);
            if(j < i && adjacency_matrix[i][j] < 0) {
                adjacency_matrix[i][j] *= -1;
            }
        }
    }

    return adjacency_matrix;
}

// Generate sparse adjacency matrix
std::vector<std::vector<int>> generate_sparse_adjacency_matrix(int dimension, int starting_range, int ending_range) {
    std::vector<std::vector<int>> adjacency_matrix(dimension, std::vector<int>(dimension, INT_MAX));
    for(int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            if(i == j) { 
                adjacency_matrix[i][j] = 0; 
                if(j < dimension - 1)
                    adjacency_matrix[i][j + 1] = random_number_generator(starting_range, ending_range);
            }

        }
    }

    return adjacency_matrix;
}