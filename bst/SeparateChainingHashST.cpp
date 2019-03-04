#include<bits/stdc++.h>
using namespace std;

template <class Key, class Value>
class SeparateChainingHashST
{
    private:
	class Node {
	    public:
	    Key key;
	    Value val;
	    Node *next;
	    Node(Key key, Value val, Node *next) {
		this->key = key;
		this->val = val;
		this->next = next;
	    }
	    Node() {
	    }
	};
	int M = 97;
	Node **st;
	int Hash(Key key) {
	    hash<Key> key_hash;
	    return (key_hash(key) & 0x7fffffff) % M;
	}
    public:
	SeparateChainingHashST() {
	    st = new Node*[M];
	}
	Value get(Key key) {
	    int i = Hash(key);
	    for (Node *x = st[i]; x != NULL; x = x->next)
		if (key == x->key)
		    return x->val;
	    return -1;
	}
	void put(Key key, Value val) {
	    int i = Hash(key);
	    for (Node *x = st[i]; x != NULL; x = x->next) {
		if (key == x->key) {
		    x->val = val;
		    return;
		}
	    }
	    st[i] = new Node(key, val, st[i]);
	}
	vector<Key> keys() {
	    vector<Key> *q = new vector<Key>();
	    for (int i = 0; i < M; i++) {
		for (Node *x = st[i]; x != NULL; x = x->next) {
		    cout<<x->key<<"->";
		    q->push_back(x->key);
		}
		cout<<endl;
	    }
	    return *q;
	}
};

int main(int argc, char *argv[]) {
    SeparateChainingHashST<string, int> hashST;
    string word;
    int count = 0;
    for (string line; getline(cin, line);) {
	stringstream s(line);
	while (s >> word) {
	    hashST.put(word, count++);
	}
	for (auto ss : hashST.keys())
	    cout<<ss<<" "<<hashST.get(ss)<<endl;
    }
    return 0;
}
