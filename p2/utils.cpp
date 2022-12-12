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

int random_number_generator_with_exclusion(int starting_range, int ending_range, std::vector<int> values_to_exclude) {
    // Seed the random number generator
    std::default_random_engine generator ( std::random_device{}() );
    std::uniform_int_distribution <int>distribution (starting_range, ending_range); 

    bool stop = false;
    int value;
    while(!stop) {
        value = distribution(generator);

        stop = true;
        for(int value_to_exclude : values_to_exclude)
            if(value_to_exclude == value) {
                stop = false;
                break;
            }
    }

    return value;
}

// Generate dense adjacency matrix
std::vector<std::vector<int>> generate_dense_adjacency_matrix(int dimension, int starting_range, int ending_range) {
    std::vector<std::vector<int>> adjacency_matrix(dimension, std::vector<int>(dimension));
    for(int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            if(i == j) { 
                adjacency_matrix[i][j] = 0; 
                continue;
            }

            adjacency_matrix[i][j] = random_number_generator(starting_range, ending_range);
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
                adjacency_matrix[i][j + 1] = random_number_generator(starting_range, ending_range);
                adjacency_matrix[i][random_number_generator_with_exclusion(0, dimension, {j, j+1})] = 
                    random_number_generator(starting_range, ending_range);
            }

        }
    }

    return adjacency_matrix;
}