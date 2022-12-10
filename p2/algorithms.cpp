#include <unordered_map>
#include <vector>
#include <tuple>
#include <iostream>
#include "graph.h"

typedef std::unordered_map<int, int> hash_map;

template<typename T>
void set_value(T key, T value, std::unordered_map<T, T>& map);

template<typename T>
T get_value(const T& key, std::unordered_map<T,T>& map);

Vertice* get_vertice(hash_map& visited_map, hash_map& distance_map, std::vector<Vertice*>& vertices);
void relax(Vertice* u, Vertice* v, hash_map& distance_map, hash_map& previous_map, Graph& g);

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
        if(u == nullptr) continue;
        set_value(u->id, 1, marked_map);

        // No way to reach this vertice from starting vertice

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