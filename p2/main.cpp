#include "algorithms.h"
#include "graph.h"

int main()
{
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

}