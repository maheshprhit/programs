#include<bits/stdc++.h>
using namespace std;

static bool RED = true;
static bool BLACK = false;

template <class Key, class Value>
class BST
{
    private:
	class Node {
	    public:
	    Key key;
	    Value val;
	    Node *left, *right;
	    bool color;
	    int count;
	    Node(Key key, Value val, int count) {
		this->key = key;
		this->val = val;
		this->count = count;
	    }
	};
	Node *root;
	Node *put(Node *x, Key key, Value val) {
	    if (x == NULL)
		return new Node(key, val, 1);
	    if (key < x->key)
		x->left = put(x->left, key, val);
	    else if (key > x->key)
		x->right = put(x->right, key, val);
	    else
		x->val = val;
	    if (isRed(x->right) && !isRed(x->left))
		x = rotateLeft(x);
	    if (isRed(x->left) && isRed(x->left->left))
		x = rotateRight(x);
	    if (isRed(x->left) && isRed(x->right))
		flipColors(x);
	    x->count = 1 + size(x->left) + size(x->right);
	    return x;
	}
	void inorder(Node *x, vector<Key> *q) {
	    if (x == NULL)
		return;
	    inorder(x->left, q);
	    q->push_back(x->key);
	    inorder(x->right, q);
	}
	Node *floor(Node *x, Key key) {
	    if (x == NULL)
		return NULL;
	    if (key == x->key)
		return x;
	    if (key < x->key)
		return floor(x->left, key);
	    Node *t = floor(x->right, key);
	    if (t != NULL)
		return t;
	    else
		return x;
	}
	int size(Node *x) {
	    if (x == NULL)
		return 0;
	    return x->count;
	}
	int rank(Key key, Node *x) {
	    if (x == NULL)
		return 0;
	    if (key < x->key)
		return rank(key, x->left);
	    else if (key > x->key)
		return 1 + size(x->left) + rank(key, x->right);
	    else
		return size(x->left);
	}
	Node *deleteMin(Node *x) {
	    if (x->left == NULL)
		return x->right;
	    x->left = deleteMin(x->left);
	    x->count = 1 + size(x->left) + size(x->right);
	    return x;
	}
	Node *min(Node *x) {
	    if (x->left == NULL)
		return x;
	    else
		return min(x->left);
	}
	Node *Delete(Node *x, Key key) {
	    if (x == NULL)
		return NULL;
	    if (key < x->key)
		x->left = Delete(x->left, key);
	    else if (key > x->key)
		x->right = Delete(x->right, key);
	    else {
		if (x->right == NULL)
		    return x->left;
		if (x->left == NULL)
		    return x->right;
		Node *t = x;
		x = min(t->right);
		x->right = deleteMin(t->right);
		x->left = t->left;
	    }
	    x->count = size(x->left) + size(x->right) + 1;
	    return x;
	}
	bool isRed(Node *x) {
	    if (x == NULL)
		return false;
	    return x->color == RED;
	}
	Node *rotateLeft(Node *h) {
	    Node *x = h->right;
	    h->right = x->left;
	    x->left = h;
	    x->color = h->color;
	    h->color = RED;
	    return x;
	}
	Node *rotateRight(Node *h) {
	    Node *x = h->left;
	    h->left = x->right;
	    x->right = h;
	    x->color = h->color;
	    h->color = RED;
	    return x;
	}
	void flipColors(Node *h) {
	    h->color = RED;
	    h->left->color = BLACK;
	    h->right->color = BLACK;
	}
    public:
	void put(Key key, Value val) {
	    root = put(root, key, val);
	}
	Value get(Key key) {
	    Node *x = root;
	    while (x != NULL) {
		if (key < x->key)
		    x = x->left;
		else if (key > x->key)
		    x = x->right;
		else
		    return x->val;
	    }
	    return -1;
	}
	vector<Key> keys() {
	    vector<Key> *q = new vector<Key>();;
	    inorder(root, q);
	    return *q;
	}
	Key floor(Key key) {
	    Node *x = floor(root, key);
	    if (x == NULL)
		return NULL;
	    return x->key;
	}
	int size() {
	    return size(root);
	}
	int rank(Key key) {
	    return rank(key, root);
	}
	void deleteMin() {
	    if (!isRed(root->left) && !isRed(root->right))
		root->color = RED;
	    root = deleteMin(root);
	    if (!isEmpty())
		root->color = BLACK;
	}
	Key min() {
	    return min(root)->key;
	}
	void Delete(Key key) {
	    root = Delete(root, key);
	}
	bool isEmpty() {
	    return root == NULL;
	}
};

int main(int argc, char *argv[]) {
    BST<string, int> *bst = new BST<string, int>();
    string word;
    int count = 0;
    for (string line; getline(cin, line);) {
	stringstream s(line);
	while (s >> word) {
	    bst->put(word, count++);
	}
	for (auto ss : bst->keys())
	    cout<<ss<<" "<<bst->get(ss)<<endl;
/*	cout<<"Floor N: "<<bst->floor("N")<<endl;
	cout<<"Rank N: "<<bst->rank("N")<<endl;
	cout<<"Deleted A"<<endl;
	bst->Delete("A");
	for (auto ss : bst->keys())
	    cout<<ss<<" "<<bst->get(ss)<<endl;
	cout<<"Deleted E"<<endl;
	bst->Delete("E");
	for (auto ss : bst->keys())
	    cout<<ss<<" "<<bst->get(ss)<<endl;
	cout<<"Deleted minimum"<<endl;
	bst->deleteMin();
	for (auto ss : bst->keys())
	    cout<<ss<<" "<<bst->get(ss)<<endl;
*/    }
    return 0;
}
