#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
	class Node {
	    public:
	    int edge;
	    Node *next;
	    Node(int edge, Node *next) {
		this->edge = edge;
		this->next = next;
	    }
	    Node() {
	    }
	};
	int V; // number of vertices
	int E; // number of edges
	Node **adj; //adjacency lists
    public:
	Graph(int V);
	void addEdge(int v, int w);
	vector<int> Adj(int v);
	int Vertices();
	int Edge();
	Graph Reverse();
};
