#include"graph.h"

class BreadthFirstPaths
{
    private:
	bool *marked;
	int *edgeTo;
	int *distTo;
	int s;
	void bfs(Graph G, int v) {
	    queue<int> q;
	    q.push(v);
	    marked[v] = true;
	    while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int w : G.Adj(x))
		    if (!marked[w]) {
			q.push(w);
			marked[w] = true;
			edgeTo[w] = x;
		    }
	    }
	}
    public:
	BreadthFirstPaths(Graph G, int s) {
	    this->s = s;
	    marked = new bool[G.Vertices()];
	    edgeTo = new int[G.Vertices()];
	    distTo = new int[G.Vertices()];
	    bfs(G, s);
	}
	bool hasPathTo(int v) {
	    return marked[v];
	}
	vector<int> pathTo(int v) {
	    if (!hasPathTo(v))
		return vector<int>();
	    vector<int> path;
	    for (int x = v; x != s; x = edgeTo[x]) {
		path.push_back(x);
	    }
	    path.push_back(s);
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
    int s = (int)(*argv[1]-'0');
    BreadthFirstPaths bfs(graph, s);
    for (int v = 0; v < graph.Vertices(); v++) {
	if (bfs.hasPathTo(v)) {
	    cout<<s<<" to "<<v<<": ";
	    vector<int> l = bfs.pathTo(v);
	    for (int z = l.size() - 1; z >= 0; z--) {
		if (l.at(z) == s)
		    cout<<l.at(z);
		else
		    cout<<"-"<<l.at(z);
	    }
	    cout<<endl;
	} else {
	    cout<<s<<" to "<<v<<" not connected."<<endl;
	}
    }
    return 0;
}
