#include<bits/stdc++.h>
#include"HeapSort.h"
using namespace std;

template <class Item>
bool HeapSort<Item>::les(int v, int w)
{
    return (pq[v-1] < pq[w-1]);
}

template <class Item>
void HeapSort<Item>::exch(int i, int j)
{
    Item swap = pq[i-1];
    pq[i-1] = pq[j-1];
    pq[j-1] = swap;
}

template <class Item>
HeapSort<Item>::HeapSort()
{
    N = 0;
    sz = 1;
    pq = new Item[sz];
}

template <class Item>
HeapSort<Item>::~HeapSort()
{
    delete pq;
}

template <class Item>
void HeapSort<Item>::sink(int k, int n)
{
    while (2*k <= n) {
	int j = 2*k;
	if (j < n && les(j, j+1))
	    j++;
	if (!les(k, j))
	    break;
	exch(k, j);
	k = j;
    }
}

template <class Item>
void HeapSort<Item>::add(Item x)
{
    if (N == sz) {
	resize(2 * sz);
    }
    pq[N++] = x;
}

template <class Item>
void HeapSort<Item>::resize(int capacity)
{
    Item *copy = new Item[capacity];
    sz = capacity;
    for (int i = 0; i < N; i++) {
	copy[i] = pq[i];
    }
    pq = copy;
}

template <class Item>
void HeapSort<Item>::print()
{
    for (int i = 0; i < N; i++) {
	cout<<pq[i]<<" ";
    }
    cout<<endl;
}

template <class Item>
void HeapSort<Item>::sort()
{
    int n = N;
    for (int k = n/2; k >= 1; k--) {
	sink(k, n);
    }
    while (n > 1) {
	exch(1, n--);
	sink(1, n);
    }
}

int main(int argc, char *argv[]) {
    string word;
    int count;
    for (string line; getline(cin, line);) {
	HeapSort<string> *ptr = new HeapSort<string>();
	stringstream s(line);
	while (s >> word) {
	    ptr->add(word);
	}
	cout<<"Original array: ";
	ptr->print();
	cout<<"Sorted array  : ";
	ptr->sort();
	ptr->print();
    }
    return 0;
}
