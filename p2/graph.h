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

    ~Vertice();
};

struct Edge
{
    Edge(int weight, Vertice* start_vertice, Vertice* end_vertice);

    int weight;
    Vertice* start_vertice;
    Vertice* end_vertice;

    ~Edge();
};

struct Graph
{
    Graph();
    Graph(std::vector<Edge*>* edges, std::vector<Vertice*>* vertices);

    int get_weight(Vertice* start, Vertice* end);

    std::vector<Edge*>* edges;
    std::vector<Vertice*>* vertices;

    ~Graph();
};

Graph* make_directed_graph(matrix_2d& adjacency_matrix);

#endif