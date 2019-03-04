#include"graph.h"

class DepthFirstOrder
{
    private:
	bool *marked;
	vector<int> reversePost;
	void dfs(Graph G, int v) {
	    marked[v] = true;
	    for (int w : G.Adj(v))
		if (!marked[w]) {
		    dfs(G, w);
		}
	    reversePost.push_back(v);
	}
    public:
	DepthFirstOrder(Graph G) {
	    marked = new bool[G.Vertices()];
	    for (int v = 0; v < G.Vertices(); v++)
		if (!marked[v])
		    dfs(G, v);
	}
	bool hasPathTo(int v) {
	    return marked[v];
	}
	vector<int> ReversePost() {
	    return reversePost;
	}
};

class KosarajuSharirSCC
{
    private:
	bool *marked;
	int *edgeTo;
	int cnt;
	int *Id;
	void cc(Graph G, int v) {
	    marked[v] = true;
	    Id[v] = cnt;
	    for (int w : G.Adj(v))
		if (!marked[w]) {
		    cc(G, w);
		    edgeTo[w] = v;
		}
	}
    public:
	KosarajuSharirSCC(Graph G) {
	    cnt = 0;
	    Id = new int[G.Vertices()];
	    marked = new bool[G.Vertices()];
	    edgeTo = new int[G.Vertices()];
	    DepthFirstOrder DFS(G.Reverse());
	    vector<int> l = DFS.ReversePost();
	    for (int z = l.size() - 1; z >= 0; z--) {
		if (!marked[l.at(z)]) {
		    cc(G, l.at(z));
		    cnt++;
		}
	    }
	}
	int id(int v) {
	    return Id[v];
	}
	int count() {
	    return cnt;
	}
	bool connected(int v, int w) {
	    return id(v) == id(w);
	}
};

int main(int argc, char *argv[]) {
    string e, v;
    getline(cin, v);
    getline(cin, e);
    int edges, vertices;
    stringstream(v) >> vertices;
    stringstream(e) >> edges;

    Graph graph(vertices);
    for (string line; getline(cin, line);) {
	stringstream s(line);
	int v, w;
	s >> v;
	s >> w;
	graph.addEdge(v, w);
    }
/*    for (int i = 0; i < vertices; i++) {
	cout << i <<":";
	for (auto ss : graph.Adj(i))
	    cout << " " << ss;
	cout << endl;
    }
  */  KosarajuSharirSCC CC(graph);
    cout<<"Number of connected components: "<<CC.count()<<endl;
    vector<int> components[CC.count()];
    for (int v = 0; v < graph.Vertices(); v++) {
	components[CC.id(v)].push_back(v);
    }
    for (int i = 0; i < CC.count(); i++) {
	for (auto v : components[i]) {
	    cout<<v<<" ";
	}
	cout<<endl;
    }
    return 0;
}
