#include "algorithms.h"
#include "graph.h"
#include "utils.h"
#include <chrono>
#include <climits>
#include "math.h"

const int inner_iter = 4;
const int outer_iter = 5;
const int factor = 100;
int main()
{
        for(int i = 1; i < outer_iter; ++i) {
            /* ========================== Dijkstras sparse graph */
            matrix_2d dijkstras_sparse_adj = generate_sparse_adjacency_matrix(i*factor, 1, 100);
            Graph* dijkstras_sparse_graph = make_directed_graph(dijkstras_sparse_adj);

            /* ========================== Dijkstras dense graph */
            matrix_2d dijkstras_dense_adj = generate_dense_adjacency_matrix(i*factor, 1, 100);
            Graph* dijkstras_dense_graph = make_directed_graph(dijkstras_dense_adj);

            /* ========================== Floyd sparse graph */
            matrix_2d floyd_sparse_adj = generate_sparse_adjacency_matrix(i*factor, 1, 100);
            Graph* floyd_sparse_graph = make_directed_graph(floyd_sparse_adj);

            /* ========================== Floyd dense graph */
            matrix_2d floyd_dense_adj = generate_dense_adjacency_matrix(i*factor, -10, 100);
            Graph* floyd_dense_graph = make_directed_graph(floyd_dense_adj);

        std::cout << "Starting test run " << i << std::endl;
        std::cout << "-------------------------------" << std::endl;

        for(int j = 0; j < inner_iter; ++j) {
            /* ========================== Dijkstras sparse test */
            auto start = std::chrono::high_resolution_clock::now();
            dijkstras(*dijkstras_sparse_graph, *(dijkstras_sparse_graph->vertices->at(0)));
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Algo: Dijkstras Sparse " << "Size of Graph: " << i*factor
                        <<  " Time: " << duration.count() / pow(10,6) << " seconds" << std::endl;
        }

        for(int j = 0; j < inner_iter; ++j) {
            /* ========================== Dijkstras dense test */
            auto start = std::chrono::high_resolution_clock::now();
            dijkstras(*dijkstras_dense_graph, *(dijkstras_dense_graph->vertices->at(0)));
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Algo: Dijkstras Dense " << "Size of Graph: " << i*factor
                        <<  " Time: " << duration.count() / pow(10,6) << " seconds" << std::endl;
        }

        for(int j = 0; j < inner_iter; ++j) {
            /* ========================== Warshal Floyd sparse test */
            auto start = std::chrono::high_resolution_clock::now();
            floyd_warshall(*floyd_sparse_graph);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Algo: Floyd Sparse " << "Size of Graph: " << i*factor
                        <<  " Time: " << duration.count() / pow(10,6) << " seconds" << std::endl;
        }

        for(int j = 0; j < inner_iter; ++j) {
        /* ========================== Warshal Floyd dense test */
            auto start = std::chrono::high_resolution_clock::now();
            floyd_warshall(*floyd_dense_graph);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Algo: Floyd Dense " << "Size of Graph: " << i*factor
                        <<  " Time: " << duration.count() / pow(10,6) << " seconds" << std::endl;
        }

        std::cout << "Ending test run " << i << std::endl;

        delete(dijkstras_sparse_graph);
        delete(dijkstras_dense_graph);
        delete(floyd_sparse_graph);
        delete(floyd_dense_graph);
    }

    /* Sanity check matrices */
    // Dijkstra sanity check matrix
    // matrix_2d adjacency_matrix = 
    // {
    // //   0        1        2        3        4        5        6        7 
    //     {0,       2,       4,       INT_MAX, INT_MAX, 1,       INT_MAX, INT_MAX}, 
    //     {INT_MAX, 0,       1,       4,       5,       INT_MAX, INT_MAX, INT_MAX},
    //     {INT_MAX, 3,       0,       2,       3,       INT_MAX, INT_MAX, INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, 0,       10,      INT_MAX, 1,       INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, 1,       0,       INT_MAX, INT_MAX, INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1,       INT_MAX, INT_MAX, 0},
    // };

    // Floyd warshall sanity check matrix (slides)
    // matrix_2d floyd_adjacency_matrix = 
    // {
    // //   1        2        3        4        5
    //     {0,       3,       8,       INT_MAX, -4     },
    //     {INT_MAX, 0,       INT_MAX, 1,       7      },
    //     {INT_MAX, 4,       0,       INT_MAX, INT_MAX},
    //     {2,       INT_MAX, -5,      0,       INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, 6,       0      },
    // };

}