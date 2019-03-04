#include"graph.h"

class DirectedEdge {
    private:
	int v, w;
	double weight;
    public:
	DirectedEdge(int v, int w, double weight) {
	    this->v = v;
	    this->w = w;
	    this->weight = weight;
	}
	DirectedEdge() {
	}
	int from() {
	    return v;
	}
	int to() {
	    return w;
	}
	double Weight() {
	    return weight;
	}
	void operator =(const DirectedEdge& that) {
	    this->weight = that.weight;
	    this->v = that.v;
	    this->w = that.w;
	}
	bool operator >(const DirectedEdge& that) {
	    if (this->weight <= that.weight)
		return 0;
	    else if (this->weight > that.weight)
		return 1;
	}
	bool operator !=(const DirectedEdge& that) {
	    if (this->weight != that.weight)
		return 1;
	    else
		return 0;
	}
	void print() {
	    cout<<this->v<<"->"<<this->w<<" "<<this->weight;
	}
};

template <class Item>
class IndexMinPQ
{
    private:
	int maxN;
	int *pq;
	int *qp;
	int N;
	int sz;
	Item *keys;
	void swim(int k) {
	    while (k > 1 && greater(k/2, k)) {
		exch(k, k/2);
		k = k/2;
	    }
	}
	void sink(int k) {
	    while (2*k <= N) {
		int j = 2*k;
		if (j < N && greater(j, j+1))
		    j++;
		if (!greater(k, j))
		    break;
		exch(k, j);
		k = j;
	    }
	}
	bool greater(int v, int w) {
	    return (keys[pq[v]] > keys[pq[w]]);
	}
	void exch(int i, int j) {
	    int swap = pq[i];
	    pq[i] = pq[j];
	    pq[j] = swap;
	    qp[pq[i]] = i;
	    qp[pq[j]] = j;
	}
	void resize(int capacity) {
	    Item *copy = new Item[capacity];
	    sz = capacity;
	    for (int i = 1; i <= N; i++) {
		copy[i] = pq[i];
	    }
	    pq = copy;
	}
    public:
	IndexMinPQ(int maxN) {
	    this->maxN = maxN;
	    N = 0;
	    sz = maxN;
	    keys = new Item[sz+1];
	    pq = new int[sz+1];
	    qp = new int[sz+1];
	    for (int i = 0; i <= maxN; i++)
		qp[i] = -1;
	}
	~IndexMinPQ() {
	    delete pq;
	}
	void insert(int i, Item v) {
	    N++;
	    qp[i] = N;
	    pq[N] = i;
	    keys[i] = v;
	    swim(N);
	}
	int delMin() {
	    int min = pq[1];
	    exch(1, N--);
	    sink(1);
	    Item null;
	    keys[min] = null;
	    qp[min] = -1;
	    pq[N+1] = -1;
	    return min;
	}
	bool isEmpty() {
	    return (N == 0);
	}
	int size() {
	    return N;
	}
	bool contains(int i) {
	    return qp[i] != -1;
	}
	void decreaseKey(int i, Item key) {
	    keys[i] = key;
	    swim(qp[i]);
	}
};

class EdgeWeightedDigraph
{
    private:
	class Node {
	    public:
	    DirectedEdge edge;
	    Node *next;
	    Node(DirectedEdge edge, Node *next) {
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
	EdgeWeightedDigraph(int V) {
	    this->V = V;
	    this->E = 0;
	    this->adj = new Node*[V];
	}
	void addEdge(DirectedEdge e) {
	    int v = e.from();
	    adj[v] = new Node(e, adj[v]);
	    E++;
	}
	vector<DirectedEdge> Adj(int v) {
	    vector<DirectedEdge> *q = new vector<DirectedEdge>();
	    for (Node *x = adj[v]; x != NULL; x = x->next) {
		q->push_back(x->edge);
	    }
	    return *q;
	}
	vector<DirectedEdge> edges() {
	    vector<DirectedEdge> *q = new vector<DirectedEdge>();
	    for (int v = 0; v < V; v++) {
		for (DirectedEdge e : Adj(v)) {
			q->push_back(e);
		}
	    }
	    return *q;
	}
	int Vertices() {
	    return V;
	}
	int Edges() {
	    return E;
	}
	EdgeWeightedDigraph Reverse() {
	    EdgeWeightedDigraph reverse(V);
/*	    for (int v = 0; v < V; v++) {
		for (auto w : Adj(v))
		    reverse.addEdge(w, v);
	    }
*/	    return reverse;
	}
};

class DijkstraSP {
    private:
	DirectedEdge *edgeTo;
	double *distTo;
	IndexMinPQ<double> *pq;
	void relax(DirectedEdge e) {
	    int v = e.from(), w = e.to();
	    if (distTo[w] > distTo[v] + e.Weight()) {
		distTo[w] = distTo[v] + e.Weight();
		edgeTo[w] = e;
		if (pq->contains(w))
		    pq->decreaseKey(w, distTo[w]);
		else
		    pq->insert(w, distTo[w]);
	    }
	}
    public:
	DijkstraSP(EdgeWeightedDigraph G, int s) {
	    edgeTo = new DirectedEdge[G.Vertices()];
	    distTo = new double[G.Vertices()];
	    pq = new IndexMinPQ<double>(G.Vertices());
	    for (int v = 0; v < G.Vertices(); v++) {
		distTo[v] = numeric_limits<double>::infinity();
	    }
	    distTo[s] = 0.0;
	    pq->insert(s, 0.0);
	    while (!pq->isEmpty()) {
		int v = pq->delMin();
		for (DirectedEdge e : G.Adj(v))
		    relax(e);
	    }
	}
	double DistTo(int v) {
	    return distTo[v];
	}
	bool hasPathTo(int v) {
	    return distTo[v] < numeric_limits<double>::infinity();
	}
	vector<DirectedEdge> PathTo(int v) {
	    vector<DirectedEdge> path;
	    if (!hasPathTo(v))
		return path;
	    DirectedEdge null;
	    for (DirectedEdge e = edgeTo[v]; e.Weight() != 0; e = edgeTo[e.from()])
		path.push_back(e);
	    return path;
	}
};

int main(int argc, char *argv[]) {
    string e, v;
    getline(cin, v);
    getline(cin, e);
    int edges, vertices;
    stringstream(v) >> vertices;
    stringstream(e) >> edges;

    EdgeWeightedDigraph graph(vertices);
    for (string line; getline(cin, line);) {
	stringstream s(line);
	int v, w;
	double weight;
	s >> v;
	s >> w;
	s >> weight;
	DirectedEdge e(v, w, weight);
	graph.addEdge(e);
    }
    int s = (int)(*argv[1]-'0');
    DijkstraSP sp(graph, s);
    for (int v = 0; v < graph.Vertices(); v++) {
	cout<<s<<" to "<<v<<": ("<<sp.DistTo(v)<<")  ";
	vector<DirectedEdge> l = sp.PathTo(v);
	for (int z = l.size() - 1; z >= 0; z--) {
	    l.at(z).print();
	    cout<<"  ";
	}
	cout<<endl;
    }
/*    for (int i = 0; i < vertices; i++) {
	cout << i <<": ";
	for (auto ss : graph.Adj(i)) {
	    ss.print();
	    cout<<"   ";
	}
	cout << endl;
    }
*/    return 0;
}
