#include"graph.h"

class Edge {
    private:
	int v, w;
	double weight;
    public:
	Edge(int v, int w, double weight) {
	    this->v = v;
	    this->w = w;
	    this->weight = weight;
	}
	int either() {
	    return v;
	}
	int other(int vertex) {
	    if (vertex == v)
		return w;
	    else
		return v;
	}
	int compareTo(Edge that) {
	    if (this->weight < that.weight)
		return -1;
	    else if (this->weight > that.weight)
		return 1;
	    else
		return 0;
	}
};

class EdgeWeightedGraph
{
    private:
	class Node {
	    public:
	    Edge edge;
	    Node *next;
	    Node(Edge edge, Node *next) {
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
	Graph(int V) {
	    this->V = V;
	    this->E = 0;
	    this->adj = new Node*[V];
	}
	void addEdge(Edge e) {
	    int v = e.either(), w = e.other();
	    adj[v] = new Node(e, adj[v]);
	    adj[w] = new Node(e, adj[v]);
	    E++;
	}
	vector<Edge> Adj(int v) {
	    vector<Edge> *q = new vector<Edge>();
	    for (Node *x = adj[v]; x != NULL; x = x->next) {
		q->push_back(x->edge);
	    }
	    return *q;
	}
	int Vertices() {
	    return V;
	}
	int Edge() {
	    return E;
	}
	Graph Reverse() {
	    Graph reverse(V);
	    for (int v = 0; v < V; v++) {
		for (auto w : Adj(v))
		    reverse.addEdge(w, v);
	    }
	    return reverse;
	}
};

class MST {
    public:
	MST(EdgeWeightedGraph G);
	vector<Edge> edges();
	double weight();
};

int main(int argc, char *argv[]) {
    string e, v;
    getline(cin, v);
    getline(cin, e);
    int edges, vertices;
    stringstream(v) >> vertices;
    stringstream(e) >> edges;

    EdgeWeightedGraph graph(vertices);
    for (string line; getline(cin, line);) {
	stringstream s(line);
	int v, w, weight;
	s >> v;
	s >> w;
	s >> weight;
	Edge e(v, w, weight);
	graph.addEdge(e);
    }
    MST mst(G);
/*    for (int i = 0; i < vertices; i++) {
	cout << i <<":";
	for (auto ss : graph.Adj(i))
	    cout << " " << ss;
	cout << endl;
    }
  */  return 0;
}
