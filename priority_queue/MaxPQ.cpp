#include<bits/stdc++.h>
#include"MaxPQ.h"
using namespace std;

template <class Item>
bool MaxPQ<Item>::les(int v, int w)
{
    return (pq[v] < pq[w]);
}

template <class Item>
void MaxPQ<Item>::exch(int i, int j)
{
    Item swap = pq[i];
    pq[i] = pq[j];
    pq[j] = swap;
}

template <class Item>
MaxPQ<Item>::MaxPQ()
{
    N = 0;
    sz = 1;
    pq = new Item[sz+1];
}

template <class Item>
MaxPQ<Item>::~MaxPQ()
{
    delete pq;
}

template <class Item>
void MaxPQ<Item>::swim(int k)
{
    while (k > 1 && les(k/2, k)) {
	exch(k, k/2);
	k = k/2;
    }
}

template <class Item>
void MaxPQ<Item>::sink(int k)
{
    while (2*k <= N) {
	int j = 2*k;
	if (j < N && les(j, j-1))
	    j++;
	if (!les(k, j))
	    break;
	exch(k, j);
	k = j;
    }
}

template <class Item>
void MaxPQ<Item>::insert(Item x)
{
    if (N == sz-1) {
	resize(2 * sz);
    }
    pq[++N] = x;
    swim(N);
}

template <class Item>
void MaxPQ<Item>::resize(int capacity)
{
    Item *copy = new Item[capacity];
    sz = capacity;
    for (int i = 1; i <= N; i++) {
	copy[i] = pq[i];
    }
    pq = copy;
}

template <class Item>
int MaxPQ<Item>::size()
{
    return N;
}

template <class Item>
bool MaxPQ<Item>::isEmpty()
{
    return (N == 0);
}

template <class Item>
Item MaxPQ<Item>::delMax()
{
    Item max = pq[1];
    exch(1, N--);
    sink(1);
    pq[N+1] = "\0";
    if ((N > 0) && (N == (sz-1)/4))
	resize(sz/2);
    return max;
}

int main(int argc, char *argv[]) {
    string word;
    int count;
    for (string line; getline(cin, line);) {
	MaxPQ<string> *pq = new MaxPQ<string>();
	stringstream s(line);
	while (s >> word) {
	    if (word != "-")
		pq->insert(word);
	    else if (!pq->isEmpty())
		cout<<pq->delMax()<<" ";
	}
	cout<<"("<<pq->size()<<" left on pq)"<<endl;
    }
    return 0;
}
