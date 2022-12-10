#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <tuple>
#include <iostream>

struct Vertice;
struct Edge;
struct Graph;

typedef std::vector<std::vector<int>> matrix_2d;

struct Vertice {
    Vertice();
    Vertice(int id);

    int id;
    static int number_of_vertices;
    std::vector<std::tuple<Vertice*, int*>> neighbors;
};

struct Edge
{
    Edge(int weight, Vertice* start_vertice, Vertice* end_vertice);

    int weight;
    Vertice* start_vertice;
    Vertice* end_vertice;
};

struct Graph
{
    Graph();
    Graph(std::vector<Edge*>* edges, std::vector<Vertice*>* vertices);

    int get_weight(Vertice* start, Vertice* end);

    std::vector<Edge*>* edges;
    std::vector<Vertice*>* vertices;
};

std::tuple<std::vector<Vertice*>, std::vector<Edge* >, Vertice*> make_directed_graph(matrix_2d& adjacency_matrix);

#endif