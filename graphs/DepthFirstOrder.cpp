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
    for (int i = 0; i < vertices; i++) {
	cout << i <<":";
	for (auto ss : graph.Adj(i))
	    cout << " " << ss;
	cout << endl;
    }
    DepthFirstOrder dfs(graph);
    cout<<"Reverse postorder: "<<endl;
    vector<int> l = dfs.ReversePost();
    for (int z = l.size() - 1; z >= 0; z--) {
	cout<<l.at(z)<<" ";
    }
    cout<<endl;
    return 0;
}
