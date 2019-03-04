#include<bits/stdc++.h>
using namespace std;
static unsigned long long int total;
static unsigned long long int T, N, P;
template <class Value>
class TrieST
{
    private:
	static const int R = 2;
	class Node {
	    public:
	    Value val;
	    unsigned long long int depth;
	    Node **next;
	    Node() {
		this->val = -1;
		this->depth = 0;
		next = new Node*[R];
		next[0] = NULL;
		next[1] = NULL;
	    }
	};
	Node *root;
	unsigned char charAt(string s, int d)
	{
	    if (d < s.length())
		return s.at(d);
	    else
		return -1;
	}
	Node *put(Node *x, string key, Value val, int d) {
	    if ((x == NULL)) {
		x = new Node();
		x->depth = d;
	    }
	    if (d == key.length()) {
		x->val = val;
		return x;
	    }
	    int c = (charAt(key, d) == 'B') ? 0 : 1;
	    x->next[c] = put(x->next[c], key, val, d+1);
	    return x;
	}
	Node *get(Node *x, string key, int d) {
	    if (x == NULL)
		return NULL;
	    if (d == key.length())
		return x;
	    int c = (charAt(key, d) == 'B') ? 0 : 1;
	    return get(x->next[c], key, d+1);
	}
	void collect(Node *x, string prefix, vector<string> *q) {
	    if (x == NULL) {
		return;
	    }
	    if (x->val != -1) {
		q->push_back(prefix);
		return;
	    }
	    if (((x->next[0] == NULL) || (x->next[1] == NULL))){
	        total += (1ULL << (N -1ULL - (x->depth)));
	    }
    	    prefix += 'B';
	    collect(x->next[0], prefix, q);
	    prefix = prefix.substr(0, prefix.size()-1);
	    prefix += 'R';
	    collect(x->next[1], prefix, q);
	    prefix = prefix.substr(0, prefix.size()-1);
	}
	int search(Node *x, string query, int d, int length) {
	    if (x == NULL)
		return length;
	    if (x->val != -1)
		length = d;
	    if (d == query.length())
		return length;
	    unsigned char c = charAt(query, d);
	    return search(x->next[c], query, d+1, length);
	}
    public:
	TrieST()
	{
	    root = new Node();
	}
	void put(string key, Value val) {
	    root = put(root, key, val, 0);
	}
	bool contains(string key) {
	    return get(key) != NULL;
	}
	Value get(string key) {
	    Node *x = get(root, key, 0);
	    if (x == NULL)
		return -1;
	    return x->val;
	}
	vector<string> keys() {
	    vector<string> *q = new vector<string>();
	    collect(root, "", q);
	    return *q;
	}
	vector<string> keysWithPrefix(string prefix)
	{
	    vector<string> *q = new vector<string>();
	    Node *x = get(root, prefix, 0);
	    collect(x, prefix, q);
	    return *q;
	}
	string longestPrefixOf(string query)
	{
	    int length = search(root, query, 0, 0);
	    return query.substr(0, length);
	}
};

int main(int argc, char *argv[]) {
    string word;
    string line;
    getline(cin, line);
    stringstream s(line);
    s >> T;
    int tCount = 0;
    for (; getline(cin, line);) {
	stringstream s(line);
    	s >> N;
    	s >> P;
	TrieST<int> st;
	int count = 0;
	total = 0;
    	for (int i = 0; i < P; i++) {
	    getline(cin, line);
	    st.put(line, count++);
	}
	st.keys();
        cout<<"Case #"<<++tCount<<": "<<total<<endl;
    }
    return 0;
}
