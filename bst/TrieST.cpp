#include<bits/stdc++.h>
using namespace std;

template <class Value>
class TrieST
{
    private:
	static const int R = 255;
	class Node {
	    public:
	    Value val;
	    Node **next;
	    Node() {
		this->val = -1;
		next = new Node*[R];
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
	    if (x == NULL)
		x = new Node();
	    if (d == key.length()) {
		x->val = val;
		return x;
	    }
	    unsigned char c = charAt(key, d);
	    x->next[c] = put(x->next[c], key, val, d+1);
	    return x;
	}
	Node *get(Node *x, string key, int d) {
	    if (x == NULL)
		return NULL;
	    if (d == key.length())
		return x;
	    unsigned char c = charAt(key, d);
	    return get(x->next[c], key, d+1);
	}
	void collect(Node *x, string prefix, vector<string> *q) {
	    if (x == NULL) {
		return;
	    }
	    if (x->val != -1) {
		q->push_back(prefix);
	    }
	    for (unsigned char c = 0; c < R; c++) {
		prefix += c;
		collect(x->next[c], prefix, q);
		prefix = prefix.substr(0, prefix.size()-1);
	    }
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
    TrieST<int> st;
    string word;
    int count = 0;
    for (string line; getline(cin, line);) {
	stringstream s(line);
	while (s >> word) {
	    st.put(word, count++);
	}
    }
    for (auto ss : st.keys()) {
	cout<<ss<<" "<<st.get(ss)<<endl;
    }
    cout<<"Strings with prefix sh:"<<endl;
    for (auto ss : st.keysWithPrefix("sh")) {
	cout<<ss<<" "<<st.get(ss)<<endl;
    }
    cout<<"Longest prefix of shellsort: "<<st.longestPrefixOf("shellsort")<<endl;
    return 0;
}
