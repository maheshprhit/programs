#include<bits/stdc++.h>
#include"SortArray.h"
using namespace std;

template <class Item>
bool SortArray<Item>::les(Item v, Item w)
{
    return (v < w);
}

template <class Item>
void SortArray<Item>::exch(Item a[], int i, int j)
{
    Item swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <class Item>
SortArray<Item>::SortArray()
{
    N = 0;
    sz = 1;
    s = new Item[sz];
}

template <class Item>
SortArray<Item>::~SortArray()
{
    delete s;
}

template <class Item>
void SortArray<Item>::add(Item item)
{
    if (N == sz) {
	resize(2 * sz);
    }
    s[N++] = item;
}

template <class Item>
void SortArray<Item>::resize(int capacity)
{
    Item *copy = new Item[capacity];
    sz = capacity;
    for (int i = 0; i < N; i++) {
	copy[i] = s[i];
    }
    s = copy;
}

template <class Item>
int SortArray<Item>::size()
{
    return sz;
}

template <class Item>
void SortArray<Item>::print()
{
    for (int i = 0; i < N; i++) {
	cout<<s[i]<<" ";
    }
    cout<<endl;
}

template <class Item>
void SortArray<Item>::selection_sort()
{
    for (int i = 0; i < N; i++) {
	int min = i;
	for (int j = i+1; j < N; j++) {
	    if (les(s[j], s[min])) {
		min = j;
	    }
	}
	exch(s, i , min);
    }
}

template <class Item>
void SortArray<Item>::insertion_sort()
{
    for (int i = 0; i < N; i++) {
	for (int j = i; j > 0; j--) {
	    if (les(s[j], s[j-1])) {
		exch(s, j , j-1);
	    } else {
		break;
	    }
	}
    }
}

template <class Item>
void SortArray<Item>::shell_sort()
{
    int h = 1;
    while (h < N/3) {
	h = 3*h + 1; //1, 4, 13, 40
    }
    while (h >= 1) {
	//h-sort the array
	for (int i = h; i < N; i++) {
	    for (int j = i; j >= h && les(s[j], s[j-h]); j-=h) {
		exch(s, j , j-h);
	    }
	}
	h = h/3;
    }
}

template <class Item>
void SortArray<Item>::knuth_shuffle()
{
    for (int i = 0; i < N; i++) {
	srand(time(0));
	int r = rand() % (i+1);
	exch(s, i , r);
    }
}

template <class Item>
void SortArray<Item>::merge(Item a[], Item aux[], int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++) {
	aux[k] = a[k];
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
	if (i > mid)
	    a[k] = aux[j++];
	else if (j > hi)
	    a[k] = aux[i++];
	else if (les(aux[j], aux[i]))
	    a[k] = aux[j++];
	else
	    a[k] = aux[i++];
    }
}

template <class Item>
void SortArray<Item>::sort(Item a[], Item aux[], int lo, int hi)
{
    if (hi <= lo)
	return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid+1, hi);
    // return if already sorted
    if (!les(a[mid+1], a[mid]))
	return;
    merge(a, aux, lo, mid, hi);
}

template <class Item>
void SortArray<Item>::merge_sort()
{
    Item *aux = new Item[N];
    sort(s, aux, 0, N-1);
}

template <class Item>
void SortArray<Item>::bottom_up_merge_sort()
{
    Item *aux = new Item[N];
    for (int z = 1; z < N; z = z+z)
	for (int lo = 0; lo < N - z; lo += z+z)
	    merge(s, aux, lo, lo+z-1, min(lo+z+z-1, N-1));
}

template <class Item>
int SortArray<Item>::partition(Item a[], int lo, int hi)
{
    int i = lo, j = hi+1;
    while (true) {
	// find item on left to swap
	while (les(a[++i], a[lo]))
	    if (i == hi)
		break;
	// find item on right to swap
	while (les(a[lo], a[--j]))
	    if (j == lo)
		break;
	// check if pointers cross
	if (i >= j)
	    break;
	// swap
	exch(a, i, j);
    }
    // swap with partitioning item
    exch(a, lo, j);
    // return index of item now known to be in place
    return j;
}

template <class Item>
void SortArray<Item>::sort(Item a[], int lo, int hi)
{
    if (hi <= lo)
	return;
    int j = partition(a, lo, hi);
    sort(a, lo, j-1);
    sort(a, j+1, hi);
}

template <class Item>
void SortArray<Item>::quick_sort()
{
    knuth_shuffle();
    sort(s, 0, N-1);
}

template <class Item>
void SortArray<Item>::_3way_sort(Item a[], int lo, int hi)
{
    if (hi <= lo)
	return;
    int lt = lo, gt = hi;
    Item v = a[lo];
    int i = lo;
    while (i <= gt) {
	if (a[i] < v)
	    exch(a, lt++, i++);
	else if (a[i] > v)
	    exch(a, i, gt--);
	else
	    i++;
    }
    _3way_sort(a, lo, lt-1);
    _3way_sort(a, gt+1, hi);
}

template <class Item>
void SortArray<Item>::_3way_quick_sort()
{
    knuth_shuffle();
    _3way_sort(s, 0, N-1);
}

template <class Item>
void SortArray<Item>::lsd_sort(int W)
{
    int R = 256;
    string *aux = new string[N];
    for (int d = W-1; d >= 0; d--) {
	int *count = new int[R+1];
	for (int i = 0; i < N; i++)
	    count[(s[i].at(d)-'A') + 1]++;
	for (int r = 0; r < R; r++)
	    count[r+1] += count[r];
	for (int i = 0; i < N; i++)
	    aux[count[s[i].at(d)-'A']++] = s[i];
	for (int i = 0; i < N; i++)
	    s[i] = aux[i];
    }
}

template <class Item>
void SortArray<Item>::msd_sort()
{
    string *aux = new string[N];
    priv_msd_sort(s, aux, 0, N-1, 0);
}

template <class Item>
int SortArray<Item>::charAt(string s, int d)
{
    if (d < s.length())
	return s.at(d)-'A';
    else
	return -1;
}

template <class Item>
void SortArray<Item>::priv_msd_sort(string *s, string *aux, int lo, int hi, int d)
{
    int R = 256;
    if (hi <= lo)
	return;
    int *count = new int[R+2];
    for (int i = lo; i <= hi; i++)
	count[charAt(s[i], d) + 2]++;
    for (int r = 0; r < R+1; r++)
	count[r+1] += count[r];
    for (int i = lo; i <= hi; i++)
	aux[count[charAt(s[i], d) + 1]++] = s[i];
    for (int i = lo; i <= hi; i++)
	s[i] = aux[i - lo];
    for (int r = 0; r < R; r++)
	priv_msd_sort(s, aux, lo+count[r], lo+count[r+1]-1, d+1);
}

template <class Item>
void SortArray<Item>::_3way_string_sort(Item a[], int lo, int hi, int d)
{
    if (hi <= lo)
	return;
    int lt = lo, gt = hi;
    int v = charAt(a[lo], d);
    int i = lo + 1;
    while (i <= gt) {
	int t = charAt(a[i], d);
	if (t < v)
	    exch(a, lt++, i++);
	else if (t > v)
	    exch(a, i, gt--);
	else
	    i++;
    }
    _3way_string_sort(a, lo, lt-1, d);
    if (v >= 0)
	_3way_string_sort(a, lt, gt, d+1);
    _3way_string_sort(a, gt+1, hi, d);
}

template <class Item>
void SortArray<Item>::_3way_string_sort()
{
    knuth_shuffle();
    _3way_string_sort(s, 0, N-1, 0);
}

template class SortArray<string>;
//template class SortArray<int>;
