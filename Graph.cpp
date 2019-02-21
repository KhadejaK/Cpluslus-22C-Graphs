//============================================================================
// Name        : Graph.cpp
// Author      : Khadeja Khalid & Tiffany Tran
// Version     : Tuesday, March 6, 2018
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
#include "List.h"
#include "Graph.h"
#include <vector>
#include <iomanip>

//*************** Constructors and Destructors *******************************

//initializes an empty graph to have n vertices
Graph::Graph(int n)
{
	vertices = n;
	edges = 0;

	for(int i = 0; i <= n; i++)
	{
		color.push_back('W');
		distance.push_back(-1);
		parent.push_back(0);
		adj.push_back(List<int>());
	}

}

//*************** Access Functions *******************************************

//returns the number of edges in the graph
int Graph::getNumEdges() const
{
	return edges;
}

//returns the number of vertices in the graph
int Graph::getNumVertices() const
{
	return vertices;
}

//returns whether the graph is empty (no vertices)
bool Graph::isEmpty() const
{
	return (vertices == 0);
}

//Pre: v <= numVertices
//Returns the value of the distance[v]
int Graph::getDistance(int v) const
{
	assert(v <= vertices);
	return distance.at(v);
}

//Pre: v <= numVertices
//Returns the value of the parent[v]
int Graph::getParent(int v) const
{
	assert(v <= vertices);
	return parent.at(v);
}

//Pre: v <= numVertices
//Returns the value of color[v]
char Graph::getColor(int v) const
{
	assert(v <= vertices);
	return color.at(v);
}

//*************** Manipulation Procedures **************************************

//inserts vertex v into the adjacency list of vertex u (i.e. inserts v into the list at index u)
//and inserts u into v.
void Graph::addEdge(int u, int v)
{

	if(adj[u].isEmpty() || adj[u].linearSearch(v) == -1)
		adj[u].insertLast(v);

	if(adj[v].isEmpty() || adj[v].linearSearch(u) == -1) //Check for self loops / already exists, no need to adj again
		adj[v].insertLast(u);

	edges++;
}

//*************** Additional Operations ****************************************

//Prints the adjacency list of each vertex in the graph,
//vertex: <space separated list of adjacent vertices>
//Prints to the console or to an output file given the ostream parameter
void Graph::printGraph(ostream& out)
{
	for (int i = 1; i <= getNumVertices(); i++) //0 is dummy location
	{
		out << i << ": ";
		adj[i].printList(out);
	}
}

//Prints the current values in the parallel vectors after executing BFS
//Prints to the console or to an output file given the ostream parameter
//First prints the heading:
//v <tab> c <tab> p <tab> d <tab>
//Then, prints out this information for each vertex in the graph
//Note that this function is intended purely to help you debug your code
void Graph::printBFS(ostream& out)
{
	out << left << setw(5) << "v"
			<< setw(5) << "c"
			<< setw(5) << "p"
			<< setw(5) << "d" << endl;

	for (int i = 1; i <= getNumVertices(); i++) //0 is dummy location
	{
		out << left << setw(5) << i
				<< setw(5) << color[i]
				<< setw(5) << parent[i]
				<< setw(5) << distance[i] << endl;
	}

}

//Performs breath first search on this Graph give a source vertex
//pre: at least one vertex must exist
//pre: source is a vertex in the graph
void Graph::BFS(int source)
{
	assert (!isEmpty());
	assert (0 < source && source <= getNumVertices());

	List<int> queue;

	for (int i = 1; i <= getNumVertices(); i++)
	{
		color[i] = 'W';
		distance[i] = -1;
		parent[i] = 0;
	}

	color[source] = 'G';
	distance[source] = 0;

	queue.insertLast(source);

	while (!queue.isEmpty())
	{
		int x = queue.getFirst();
		queue.removeFirst();

		adj[x].startIterator();
		while(!adj[x].offEnd())
		{
			int y = adj[x].getIterator();
			if (color[y] == 'W')
			{
				color[y] = 'G';
				distance[y] = distance[x] + 1;
				parent[y] = x;
				queue.insertLast(y);
			}
			adj[x].advanceIterator();
		}
		color[x] = 'B';
	}
}

//Prints the path from the source to the destination vertex
//Prints to the console or to an output file given the ostream parameter
void Graph::printPath(int source, int destination, ostream& out)
{
	if (destination == source)
		out << source;
	else if (parent[destination] == 0)
		out << "No path from " << source << " to " << destination << " exists" << endl;
	else
	{
		printPath(source, parent[destination], out);
		out << " - " << destination;
	}

}
