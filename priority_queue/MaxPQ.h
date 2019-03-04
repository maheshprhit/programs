#include<bits/stdc++.h>
using namespace std;

template <class Item>
class MaxPQ
{
    private:
	Item *pq;
	int N;
	int sz;
	void swim(int k);
	void sink(int k);
	bool les(int v, int w);
	void exch(int i, int j);
	void resize(int capacity);
    public:
	MaxPQ();
	~MaxPQ();
	void insert(Item v);
	void add(Item v);
	Item delMax();
	bool isEmpty();
	int size();
};
