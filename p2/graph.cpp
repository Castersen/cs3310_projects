#include <vector>
#include <tuple>
#include <iostream>
#include "graph.h"

typedef std::vector<std::vector<int>> matrix_2d;

// Vertice
Vertice::Vertice() {
    this->id = number_of_vertices++;
}

Vertice::Vertice(int id) {
    this->id = id;
    number_of_vertices++;
}

Vertice::~Vertice() {}

int Vertice::number_of_vertices = 0;

// Edge 
Edge::Edge(int weight, Vertice* start_vertice, Vertice* end_vertice) {
    this->weight = weight;
    this->start_vertice = start_vertice;
    this->end_vertice = end_vertice;

    start_vertice->neighbors.push_back(std::make_tuple(end_vertice, &(this->weight)));
}

Edge::~Edge() {}

// Graph
Graph::Graph() {};
Graph::Graph(std::vector<Edge*>* edges, std::vector<Vertice*>* vertices) {
        this->edges = edges;
        this->vertices = vertices;
}

Graph::~Graph() {
    for(Vertice* vertice : *vertices) {
        delete(vertice);
    }

    for(Edge* edge : *edges) {
        delete(edge);
    }

    delete(edges);
    delete(vertices);
}

int Graph::get_weight(Vertice* start, Vertice* end) {
        for(Edge* edge : *(this->edges)) {
            if(edge->start_vertice->id == start->id && 
                edge->end_vertice->id == end->id)
            return edge->weight;
        }

        return INT_MAX;
}

// Helper that takes adjacency matrix and returns vertices, edges, and starting vertice
Graph* make_directed_graph(matrix_2d& adjacency_matrix)
{
    std::vector<Vertice* >* vertices = new std::vector<Vertice*>;
    std::vector<Edge* >* final_edges = new std::vector<Edge*>;

    for(int i = 0; i < adjacency_matrix.size(); ++i) {
        vertices->push_back(new Vertice(i));
        for(int j = 0; j < adjacency_matrix[i].size(); ++j) {
            if(adjacency_matrix[i][j] == INT_MAX || adjacency_matrix[i][j] == 0) continue;

            Vertice* end_vertice = nullptr;
            for(Vertice* each_vertice : *vertices)
                if(each_vertice->id == j)
                    end_vertice = each_vertice;

            end_vertice = (end_vertice == nullptr) ? new Vertice(j) : end_vertice;
            final_edges->push_back(new Edge(adjacency_matrix[i][j], vertices->at(i), end_vertice));
        }
    }

    return new Graph(final_edges, vertices);
}