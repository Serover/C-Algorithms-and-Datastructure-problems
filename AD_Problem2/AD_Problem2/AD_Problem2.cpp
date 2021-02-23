//============================================================================
// Name        : Graph.cpp
// Author      : Yacine Atif
// Description : Graph ADT implementation using an
//               array of lists from STL 
//============================================================================

// Graph ADT class specification of a directed graph
// abstracting adjacency list representation

#include "pch.h"
#include "AD_Problem2.h"

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); // Add w to v’s list.

}


bool Graph::isEdge(int v, int w) {

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (w == *i) return (true);

	return (false);

}


int Graph::getNumNodes() {

	return V;

}

void Graph::printGraph() {

	for (int v = 0; v < V; ++v)
	{
		std::cout << "\n Adjacency list of vertex "
			<< v << "\n head ";

		//loop over adj[v] range
		for (auto x : adj[v])
			std::cout << "-> " << x;

		printf("\n");
	}

}


// Driver code
int main() {

	// Create a graph

	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(3, 4);
	g.addEdge(2, 5);

	g.printGraph();

	cout << "\n Is Edge (2.0) in the graph ?  ";
	if (g.isEdge(2, 0))
		printf("Yes\n");
	else
		printf("No\n");
	

	TraverseGraph(g, 0);

	return 0;
}

void TraverseGraph(Graph g, int startNode)
{
	queue<int> *openQueue = new queue<int>; //Nodes to be traversed.
	queue<int> *closedQueue = new queue<int>; //Traversed nodes.
	queue<int> *friends = new queue<int>;
	queue<int> *blackQueue = new queue<int>; //Adversaries/Blacklist.
	queue<int> connections; //Queue of current node connections (edges).
	bool friendFlag = false;
	
	openQueue->push(startNode);
	friends->push(openQueue->front());

	while (!openQueue->empty())
	{
		//Acquire all connecting nodes from current node.
		connections = findConnections(g, openQueue->front());
		while (!connections.empty())
		{
			//OpenQueue.front = current node to be traversed.
			//Connections.front = next node from current node.
			if (!isNodeInQueue(*closedQueue, connections.front())
				&& !isNodeInQueue(*openQueue, connections.front()))
			{
				//If the current node is a friend, the next node = adversary.
				if (isNodeInQueue(*friends, openQueue->front()))
					friendFlag = false;
				else
					friendFlag = true;

				openQueue->push(connections.front());

				if (friendFlag && !isNodeInQueue(*blackQueue, connections.front()))
					friends->push(connections.front());
				else if (!friendFlag)
					blackQueue->push(connections.front()); 
			}
			connections.pop();
		}
		
		closedQueue->push(openQueue->front());
		openQueue->pop();
	}
	printQueue(*friends);
}

bool isNodeInQueue(queue<int> q, int n)
{
	queue<int> temp = q;
	
	while (!temp.empty())
	{
		if (temp.front() == n)
			return true;
		else
			temp.pop();
	}
	return false;
}

queue<int> findConnections(Graph g, int n)
{
	queue<int> *connections = new queue<int>;

	for (int i = 0; i < g.getNumNodes(); i++)
	{
		if(g.isEdge(n, i))
			connections->push(i);
	}

	return (*connections);
}

void printQueue(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}

	printf("\n");
}