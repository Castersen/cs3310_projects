#include "algorithms.h"
#include "graph.h"
#include "utils.h"
#include <climits>

int main()
{
    // Dijkstra
    matrix_2d adjacency_matrix = 
    {
    //   0        1        2        3        4        5        6        7 
        {0,       2,       4,       INT_MAX, INT_MAX, 1,       INT_MAX, INT_MAX}, 
        {INT_MAX, 0,       1,       4,       5,       INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 3,       0,       2,       3,       INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0,       10,      INT_MAX, 1,       INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 1,       0,       INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1,       INT_MAX, INT_MAX, 0},
    };

    // Graph* graph = make_directed_graph(adjacency_matrix);
    // auto[distance_map, previous_map] =  dijkstras(*graph, *(graph->vertices->at(0)));

    // std::cout << "Ditance Map:\n--------------\n";
    // for(auto entry : distance_map) {
    //     std::cout << "ID: " << entry.first << " Distance: " << entry.second << std::endl;

    // }

    // std::cout << "\nPrevious Map:\n--------------\n";
    // for(auto entry : previous_map) {
    //     if((distance_map.find(entry.first))->second == INT_MAX and entry.second == 0) {
    //         std::cout << "ID: " << entry.first << " Previous: " << INT_MAX << std::endl;

    //     }
    //     std::cout << "ID: " << entry.first << " Previous: " << entry.second << std::endl;
    // }
    // std::cout << std::endl;

    // delete(graph);

    for(int i = 1; i < 10; ++i) {
        matrix_2d adj_mat = generate_dense_adjacency_matrix(i*10, 0, 100);
        Graph* graph = make_directed_graph(adj_mat);
        auto[distance_map, previous_map] =  dijkstras(*graph,*(graph->vertices->at(0)));

        std::cout << "Ditance Map:\n--------------\n";
        for(auto entry : distance_map) {
            std::cout << "ID: " << entry.first+1 << " Distance: " << entry.second << std::endl;

        }

        std::cout << "\nPrevious Map:\n--------------\n";
        for(auto entry : previous_map) {
            if((distance_map.find(entry.first))->second == INT_MAX and entry.second == 0) {
                std::cout << "ID: " << entry.first+1 << " Previous: " << INT_MAX << std::endl;
                continue;
            }
            std::cout << "ID: " << entry.first+1 << " Previous: " << entry.second+1 << std::endl;
        }
        std::cout << std::endl;

        delete(graph);
    }

    std::cout << "We are at the end\n";

    // // Floyd warshall
    // matrix_2d floyd_adjacency_matrix = 
    // {
    // //   1        2        3        4        5
    //     {0,       3,       8,       INT_MAX, -4     },
    //     {INT_MAX, 0,       INT_MAX, 1,       7      },
    //     {INT_MAX, 4,       0,       INT_MAX, INT_MAX},
    //     {2,       INT_MAX, -5,      0,       INT_MAX},
    //     {INT_MAX, INT_MAX, INT_MAX, 6,       0      },
    // };

    // graph = make_directed_graph(floyd_adjacency_matrix);
    // matrix_2d floyd_matrix = floyd_warshall(*graph);

    // for(int i = 0; i < floyd_matrix.size(); ++i) {
    //     for(int j = 0; j < floyd_matrix[i].size(); ++j) {
    //         std::cout << floyd_matrix[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // delete(graph);
}