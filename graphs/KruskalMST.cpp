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
	Edge() {
	}
	int either() {
	    return v;
	}
	double Weight() {
	    return weight;
	}
	int other(int vertex) {
	    if (vertex == v)
		return w;
	    else
		return v;
	}
	void operator =(const Edge& that) {
	    this->weight = that.weight;
	    this->v = that.v;
	    this->w = that.w;
	}
	bool operator >(const Edge& that) {
	    if (this->weight <= that.weight)
		return 0;
	    else if (this->weight > that.weight)
		return 1;
	}
	void print() {
	    cout<<this->v<<"-"<<this->w<<" "<<this->weight;
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
	EdgeWeightedGraph(int V) {
	    this->V = V;
	    this->E = 0;
	    this->adj = new Node*[V];
	}
	void addEdge(Edge e) {
	    int v = e.either(), w = e.other(v);
	    adj[v] = new Node(e, adj[v]);
	    adj[w] = new Node(e, adj[w]);
	    E++;
	}
	vector<Edge> Adj(int v) {
	    vector<Edge> *q = new vector<Edge>();
	    for (Node *x = adj[v]; x != NULL; x = x->next) {
		q->push_back(x->edge);
	    }
	    return *q;
	}
	vector<Edge> edges() {
	    vector<Edge> *q = new vector<Edge>();
	    for (int v = 0; v < V; v++) {
		int selfLoops = 0;
		for (Edge e : Adj(v)) {
		    if (e.other(v) > v) {
			q->push_back(e);
		    } else if (e.other(v) == v) {
			if (selfLoops % 2 == 0)
			    q->push_back(e);
			selfLoops++;
		    }
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
	EdgeWeightedGraph Reverse() {
	    EdgeWeightedGraph reverse(V);
/*	    for (int v = 0; v < V; v++) {
		for (auto w : Adj(v))
		    reverse.addEdge(w, v);
	    }
*/	    return reverse;
	}
};

template <class Item>
class MinPQ
{
    private:
	Item *pq;
	int N;
	int sz;
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
	    return (pq[v] > pq[w]);
	}
	void exch(int i, int j) {
	    Item swap = pq[i];
	    pq[i] = pq[j];
	    pq[j] = swap;
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
	MinPQ() {
	    N = 0;
	    sz = 1;
	    pq = new Item[sz+1];
	}
	~MinPQ() {
	    delete pq;
	}
	void insert(Item v) {
	    if (N == sz-1) {
		resize(2 * sz);
	    }
	    pq[++N] = v;
	    swim(N);
	}
	Item delMin() {
	    Item min = pq[1];
	    exch(1, N--);
	    sink(1);
	    Item null;
	    pq[N+1] = null;
	    if ((N > 0) && (N == (sz-1)/4))
		resize(sz/2);
	    return min;
	}
	bool isEmpty() {
	    return (N == 0);
	}
	int size() {
	    return N;
	}
};

class UF
{
    private:
	int *id;
	int size;
    public:
	UF(int N) {
	    id = new int[N];
	    for (int i = 0; i < N; i++)
		id[i] = i;
	    size = N;
	}
	bool connected(int p, int q) {
	    return id[p] == id[q];
	}
	bool Union(int p, int q) {
	    int pid = id[p];
	    int qid = id[q];
	    for (int i = 0; i < size; i++)
		if (id[i] == pid) id[i] = qid;
	}
};

class KruskalMST {
    private:
	vector<Edge> mst;
	double weight = 0;
    public:
	KruskalMST(EdgeWeightedGraph G) {
	    MinPQ<Edge> pq;
	    for (Edge e : G.edges()) {
		pq.insert(e);
	    }
	    UF uf(G.Vertices());
	    while (!pq.isEmpty() && (mst.size() < (G.Vertices() - 1))) {
		Edge e = pq.delMin();
		int v = e.either(), w = e.other(v);
		if (!uf.connected(v, w)) {
		    uf.Union(v, w);
		    mst.push_back(e);
		    weight += e.Weight();
		}
	    }
	}
	vector<Edge> edges() {
	    return mst;
	}
	double Weight() {
	    return weight;
	}
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
	int v, w;
	double weight;
	s >> v;
	s >> w;
	s >> weight;
	Edge e(v, w, weight);
	graph.addEdge(e);
    }
    KruskalMST mst(graph);
    for (Edge e : mst.edges()) {
	e.print();
	cout<<endl;
    }
    cout<<mst.Weight()<<endl;
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
