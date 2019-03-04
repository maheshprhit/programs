#include<bits/stdc++.h>
using namespace std;

template <class Item>
class HeapSort
{
    private:
	Item *pq;
	int N;
	int sz;
	void sink(int k, int n);
	bool les(int v, int w);
	void exch(int i, int j);
	void resize(int capacity);
    public:
	HeapSort();
	~HeapSort();
	void add(Item v);
	void print();
	void sort();
};
