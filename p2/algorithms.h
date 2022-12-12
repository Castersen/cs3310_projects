#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <tuple>
#include<unordered_map>
#include <iostream>
#include "graph.h"

typedef std::unordered_map<int, int> hash_map;

template<typename T>
void set_value(T key, T value, std::unordered_map<T, T>& map);

template<typename T>
T get_value(const T& key, std::unordered_map<T,T>& map);

Vertice* get_vertice(hash_map& visited_map, hash_map& distance_map, std::vector<Vertice*>& vertices);
void relax(Vertice* u, Vertice* v, hash_map& distance_map, hash_map& previous_map, Graph& g);

std::tuple<hash_map, hash_map> dijkstras(Graph& directed_graph, Vertice& starting_vertice);

std::tuple<matrix_2d, matrix_2d> floyd_warshall(Graph& directed_graph);

void print_direction_output(matrix_2d floyd_previous_matrix);
void print_shortest_path(int p1, int p2, matrix_2d floyd_p_matrix);

#endif