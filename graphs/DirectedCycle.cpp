#include"graph.h"

class DirectedCycle
{
    private:
	bool *marked;
	int *edgeTo;
	bool *onStack;
	vector<int> cycle;
	void dfs(Graph G, int v) {
	    marked[v] = true;
	    onStack[v] = true;
	    for (int w : G.Adj(v)) {
		if (cycle.empty() == 0)
		    return;
		else if (!marked[w]) {
		    edgeTo[w] = v;
		    dfs(G, w);
		}
		else if (onStack[w]) {
		    for (int x = v; x != w; x = edgeTo[x]) {
			cycle.push_back(x);
		    }
		    cycle.push_back(w);
		    cycle.push_back(v);
		}
	    }
	    onStack[v] = false;
	}
    public:
	DirectedCycle(Graph G) {
	    marked = new bool[G.Vertices()];
	    onStack = new bool[G.Vertices()];
	    edgeTo = new int[G.Vertices()];
	    for (int v = 0; v < G.Vertices(); v++)
		if (!marked[v] && (cycle.empty() != 0))
		    dfs(G, v);
	}
	bool hasCycle() {
	    return cycle.empty() == 0;
	}
	vector<int> Cycle() {
	    return cycle;
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
    DirectedCycle finder(graph);
    if (finder.hasCycle()) {
	cout<<"Directed cycle: ";
	for (auto v : finder.Cycle())
	    cout<<v<<" ";
	cout<<endl;
    } else {
	cout<<"No directed cycle"<<endl;
    }
    return 0;
}
