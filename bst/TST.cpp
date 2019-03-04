#include<bits/stdc++.h>
using namespace std;

template <class Value>
class TST
{
    private:
	static const int R = 255;
	class Node {
	    public:
	    Value val;
	    unsigned char c;
	    Node *left, *mid, *right;
	    Node()
	    {
		this->val = -1;
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
	Node *put(Node *x, string key, Value val, int d)
	{
	    unsigned char c = charAt(key, d);
	    if (x == NULL) {
		x = new Node();
		x->c = c;
	    }
	    if (c < x->c) {
		x->left = put(x->left, key, val, d);
	    } else if (c > x->c) {
		x->right = put(x->right, key, val, d);
	    } else if (d < key.length() - 1) {
		x->mid = put(x->mid, key, val, d+1);
	    } else {
		x->val = val;
	    }
	    return x;
	}
	Node *get(Node *x, string key, int d)
	{
	    if (x == NULL)
		return NULL;
	    unsigned char c = charAt(key, d);
	    if (c < x->c)
		return get(x->left, key, d);
	    else if (c > x->c)
		return get(x->right, key, d);
	    else if (d < key.length() - 1)
		return get(x->mid, key, d+1);
	    else
		return x;
	}
	void collect(Node *x, string prefix, vector<string> *q)
	{
	    if (x == NULL) {
		return;
	    }
	    collect(x->left, prefix, q);
	    prefix += (x->c);
	    if (x->val != -1) {
		q->push_back(prefix);
	    }
	    collect(x->mid, prefix , q);
	    prefix = prefix.substr(0, prefix.size()-1);
	    collect(x->right, prefix , q);
	}
    public:
	TST()
	{
	    root = new Node();
	}
	void put(string key, Value val)
	{
	    root = put(root, key, val, 0);
	}
	bool contains(string key)
	{
	    return get(key) != NULL;
	}
	Value get(string key)
	{
	    Node *x = get(root, key, 0);
	    if (x == NULL)
		return -1;
	    return x->val;
	}
	vector<string> keys()
	{
	    vector<string> *q = new vector<string>();
	    collect(root, "", q);
	    return *q;
	}
	vector<string> keysWithPrefix(string prefix)
	{
	    vector<string> *q = new vector<string>();
	    Node *x = get(root, prefix, 0);
	    if (x == NULL)
		return *q;
	    if (x->val != -1)
		q->push_back(prefix);
	    collect(x->mid, prefix, q);
	    return *q;
	}
	vector<string> keysThatMatch(string s)
	{
	}
	string longestPrefixOf(string query)
	{
	    if (query.length() == 0)
		return NULL;
	    int length = 0;
	    Node *x = root;
	    int i = 0;
	    while (x != NULL && (i < query.length())) {
		unsigned char c = charAt(query, i);
		if (c < x->c)
		    x = x->left;
		else if (c > x->c)
		    x = x->right;
		else {
		    i++;
		    if (x->val != -1)
			length = i;
		    x = x->mid;
		}
	    }
	    return query.substr(0, length);
	}
};

int main(int argc, char *argv[]) {
    TST<int> st;
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
