#include"graph.h"

Graph::Graph(int V) {
    this->V = V;
    this->E = 0;
    this->adj = new Node*[V];
}
void Graph::addEdge(int v, int w) {
    adj[v] = new Node(w, adj[v]); // Add w to v's list
    E++;
}
vector<int> Graph::Adj(int v) {
    vector<int> *q = new vector<int>();
    for (Node *x = adj[v]; x != NULL; x = x->next) {
	q->push_back(x->edge);
    }
    return *q;
}
int Graph::Vertices() {
    return V;
}
int Graph::Edge() {
    return E;
}
Graph Graph::Reverse() {
    Graph reverse(V);
    for (int v = 0; v < V; v++) {
	for (auto w : Adj(v))
	    reverse.addEdge(w, v);
    }
    return reverse;
}
