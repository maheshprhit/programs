#include<bits/stdc++.h>
using namespace std;

template <class Item>
class MaxPQ
{
    private:
	Node root;
	class Node {
	    Key key;
	    Value val;
	    Node left, right;
	    int size;
	    Node(Key key, Value val, int size) {
		this.key = key;
		this.val = val;
		this.size = size;
	    }
	};
    public:
	MaxPQ();
	~MaxPQ();
	void insert(Item v);
	void add(Item v);
	Item delMax();
	bool isEmpty();
	int size();
};
