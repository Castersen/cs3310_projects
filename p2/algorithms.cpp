#include <unordered_map>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include "graph.h"
#include <climits>

typedef std::unordered_map<int, int> hash_map;

template<typename T>
void set_value(T key, T value, std::unordered_map<T, T>& map);

template<typename T>
T get_value(const T& key, std::unordered_map<T,T>& map);

Vertice* get_vertice(hash_map& visited_map, hash_map& distance_map, std::vector<Vertice*>& vertices);
void relax(Vertice* u, Vertice* v, hash_map& distance_map, hash_map& previous_map, Graph& g);
void print_direction_output(matrix_2d floyd_previous_matrix);
void print_shortest_path(int p1, int p2, matrix_2d floyd_p_matrix);

// Dijkstras algorithm
std::tuple<hash_map, hash_map> dijkstras(Graph& directed_graph, Vertice& starting_vertice) {
    hash_map distance_map;
    hash_map previous_map;
    hash_map marked_map;

    // Initialization step
    for(Vertice* each_vertice : *(directed_graph.vertices)) {
        int vertice_id = each_vertice->id;

        distance_map.insert(std::make_pair(vertice_id, directed_graph.get_weight(&starting_vertice, each_vertice)));
        previous_map.insert(std::make_pair(vertice_id, starting_vertice.id));
        marked_map.insert(std::make_pair(vertice_id, 0));
    }

    set_value(starting_vertice.id, 1, marked_map);
    set_value(starting_vertice.id, 0, distance_map);

    for(int i = 0; i < directed_graph.vertices->size() - 1; ++i) {
        // u is the vertice that has the minimum distance, and has been unvisited
        Vertice* u = get_vertice(marked_map, distance_map, *directed_graph.vertices);
        // No way to reach this vertice from starting vertice
        if(u == nullptr) continue;
        set_value(u->id, 1, marked_map);


        for(std::tuple<Vertice*, int*> v : u->neighbors) {
            Vertice* vertice = std::get<0>(v);
            if(get_value(vertice->id, marked_map) == 0)
                relax(u, vertice, distance_map, previous_map, directed_graph);
        }
    }

    return std::tie(distance_map, previous_map);
}

// Helper to find the next vertice in dijkstra
Vertice* get_vertice(hash_map& visited_map, hash_map& distance_map, std::vector<Vertice*>& vertices) {
    int minimum = INT_MAX;
    Vertice* u = nullptr;

    for(Vertice* v : vertices) {
        int distance = get_value(v->id, distance_map);
        if(get_value(v->id, visited_map) == 0 and distance < minimum) {
            minimum = distance;
            u = v;
        }
    }

    return u;
}

void relax(Vertice* u, Vertice* v, hash_map& distance_map, hash_map& previous_map, Graph& directed_graph) {
    int u_distance = get_value(u->id, distance_map);
    int v_distance = get_value(v->id, distance_map);
    int u_v_weight = directed_graph.get_weight(u, v);

    if(v_distance > u_distance + u_v_weight) {
        set_value(v->id, u_distance + u_v_weight, distance_map);
        set_value(v->id, u->id, previous_map);
    }
}

// Floyd warshall algorithm
std::tuple<matrix_2d, matrix_2d> floyd_warshall(Graph& directed_graph) {
    int n = directed_graph.vertices->size();
    matrix_2d d(n, std::vector<int>(n)), previous_d(n, std::vector<int>(n));
    matrix_2d p(n, std::vector<int>(n)), previous_p(n, std::vector<int>(n));

    for(int u = 0; u < n; ++u) {
        for(int v = 0; v < n; ++v) {
            if(u == v) {
                p[u][v] = -1;
                continue;
            }
            int j = directed_graph.get_weight(directed_graph.vertices->at(u), directed_graph.vertices->at(v));
            // TODO fix this
            if(j == INT_MAX) {
                p[u][v] = -1;
                j = 99999;
            } else {
                p[u][v] = u + 1;
            }
            d[u][v] = j;
        }
    }
    previous_p = p;
    previous_d = d;

    for(int k = 0; k < n; ++k) {
        for(int u = 0; u < n; ++u) {
            for(int v = 0; v < n; ++v) {
                d[u][v] = std::min(previous_d[u][v], (previous_d[u][k] + previous_d[k][v]));
                if(previous_d[u][v] <= previous_d[u][k] + previous_d[k][v]) {
                    p[u][v] = previous_p[u][v];
                }
                else {
                    p[u][v] = previous_p[k][v];
                }

            }
        }
        previous_p = p;
        previous_d = d;
    }

    return std::tie(d, p);
}

// Helpers for performing lookups in the hash map
template<typename T>
void set_value(T key, T value, std::unordered_map<T, T>& map) {
    auto found_item = map.find(key);
    if(found_item == map.end()) 
        throw std::out_of_range("Unable to find item in map");

    found_item->second = value;
}

template<typename T>
T get_value(const T& key, std::unordered_map<T,T>& map) {
    auto found_item = map.find(key);
    if(found_item == map.end())
        throw std::out_of_range("Unable to find item in map");

    return found_item->second;
}

void print_direction_output(matrix_2d floyd_previous_matrix) {
    for(int i = 0; i < floyd_previous_matrix.size(); ++i) {
        for(int j = 0; j < floyd_previous_matrix.size(); ++j) {
            if(floyd_previous_matrix[i][j] != -1) {
                print_shortest_path(i, j, floyd_previous_matrix);
            }
        }
    }
}

void print_shortest_path(int p1, int p2, matrix_2d floyd_p_matrix) {
    std::vector<int> path;
    path.push_back(p2+1);
    int next_val = p2;

    while(true) {
        if(floyd_p_matrix[p1][next_val] == -1) {
            break;
        }

        path.push_back(floyd_p_matrix[p1][next_val]);
        next_val = (floyd_p_matrix[p1][next_val]) - 1;
    }

    // Printing the output
    for(int i = path.size()-1; i >= 0; i--) {
        if(i == 0) {
            std::cout << path.at(i);
            continue;
        }
        std::cout << path.at(i) << "->";
    }
    std::cout << std::endl;

}