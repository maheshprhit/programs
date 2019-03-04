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
	bool operator !=(const Edge& that) {
	    if (this->weight != that.weight)
		return 1;
	    else
		return 0;
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

class PrimMST {
    private:
	bool *marked;
	double *distTo;
	Edge *edgeTo;
	int length;
	IndexMinPQ<double> *pq;
	void prim(EdgeWeightedGraph G, int s) {
	    distTo[s] = 0.0;
	    pq->insert(s, distTo[s]);
	    while (!pq->isEmpty()) {
		int v = pq->delMin();
		scan(G, v);
	    }
	}
	void scan(EdgeWeightedGraph G, int v) {
	    marked[v] = true;
	    for (Edge e : G.Adj(v)) {
		int w = e.other(v);
		if (marked[w])
		    continue;
		if (e.Weight() < distTo[w]) {
		    distTo[w] = e.Weight();
		    edgeTo[w] = e;
		    if (pq->contains(w))
			pq->decreaseKey(w, distTo[w]);
		    else
			pq->insert(w, distTo[w]);
		}
	    }
	}
    public:
	PrimMST(EdgeWeightedGraph G) {
	    length = G.Vertices();
	    edgeTo = new Edge[G.Vertices()];
	    distTo = new double[G.Vertices()];
	    marked = new bool[G.Vertices()];
	    pq = new IndexMinPQ<double>(G.Vertices());
	    for (int v = 0; v < G.Vertices(); v++) {
		distTo[v] = numeric_limits<double>::infinity();
	    }
	    for (int v = 0; v < G.Vertices(); v++) {
		if (!marked[v])
		    prim(G, v);
	    }
	}
	vector<Edge> edges() {
	    vector<Edge> mst;
	    for (int v = 0; v < length; v++) {
		Edge e = edgeTo[v];
		Edge null;
		if (e != null) {
		    mst.push_back(e);
		}
	    }
	    return mst;
	}
	double Weight() {
	    double weight;
	    for (Edge e : edges())
		weight += e.Weight();
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
    PrimMST mst(graph);
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
