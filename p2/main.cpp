#include "algorithms.h"
#include "graph.h"

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

    std::tuple<std::vector<Vertice*>, std::vector<Edge* >, Vertice*> graph_tuple;
    graph_tuple = make_directed_graph(adjacency_matrix);
    auto[vertices, edges, starting_vertice] = graph_tuple;
    Graph graph = Graph(&edges, &vertices);

    std::tuple<hash_map, hash_map> dijkstras_output;
    dijkstras_output = dijkstras(graph, *starting_vertice);

    auto[distance_map, previous_map] = dijkstras_output;

    std::cout << "Ditance Map:\n--------------\n";
    for(auto entry : distance_map)
        std::cout << "ID: " << entry.first << " Distance: " << entry.second << std::endl;

    std::cout << "\nPrevious Map:\n--------------\n";
    for(auto entry : previous_map)
        std::cout << "ID: " << entry.first << " Previous: " << entry.second << std::endl;
    std::cout << std::endl;


    // Floyd warshall
    matrix_2d floyd_adjacency_matrix = 
    {
    //   1        2        3        4        5
        {0,       3,       8,       INT_MAX, -4     },
        {INT_MAX, 0,       INT_MAX, 1,       7      },
        {INT_MAX, 4,       0,       INT_MAX, INT_MAX},
        {2,       INT_MAX, -5,      0,       INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 6,       0      },
    };

    std::tuple<std::vector<Vertice*>, std::vector<Edge* >, Vertice*> floyd_graph_tuple;
    floyd_graph_tuple = make_directed_graph(floyd_adjacency_matrix);
    auto[v, e, s] = floyd_graph_tuple;
    Graph floyd_graph = Graph(&e, &v);

    matrix_2d floyd_matrix = floyd_warshall(floyd_graph);

    for(int i = 0; i < floyd_matrix.size(); ++i) {
        for(int j = 0; j < floyd_matrix[i].size(); ++j) {
            std::cout << floyd_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}