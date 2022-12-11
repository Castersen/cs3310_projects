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

#endif