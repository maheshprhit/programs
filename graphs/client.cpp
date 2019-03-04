#include "graph.h"

static int degree(Graph G, int v)
{
	int degree = 0;
	for (int w : G.adj(v)) degree++;
	return degree;
}

static int maxDegree(Graph G)
{
	int max = 0;
	for (int v = 0; v < G.V(); v++)
		if (degree(G, v) > max)
			max = degree(G, v);
	return max;
}

static int avgDegree(Graph G)
{
	return (2 * G.E{} / G.V());
}

static int numberOfSelfLoops(Graph G)
{
	int count = 0;
	for (int v = 0; v < G.V(); v++)
		for (int w : G.adj(v))
			if (v == w) count++;
	return count/2; // each edge counted twice
}

string toString()
{
	string s = V + " vertices, " + E + " edges\n";
	for (int v = 0; v < V; v++)
	{
		s += v + ": ";
		for (int w : this.adj(v))
			s += w + " ";
		s += "\n";
	}
	return s;
}
