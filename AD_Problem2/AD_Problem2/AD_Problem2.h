// Graph ADT class specification of a directed graph
// abstracting adjacency list representation
#pragma once
#include <list>
#include <iostream>
#include <queue>

using namespace std;

class Graph {

private:
	int V;    // No. of vertices

	// Pointer to an array containing
	// adjacency lists
	list<int> *adj;


public:
	Graph(int V);   // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// function to check if there is an edge in graph
	bool isEdge(int v, int w);

	// function to get number of nodes
	int getNumNodes();

	// A utility function to print the adjacency list
	// representation of graph
	void printGraph();

};

void TraverseGraph(Graph g, int startNode);
bool isNodeInQueue(queue<int> q, int n);
queue<int> findConnections(Graph g, int n);
void printQueue(queue<int> q);

