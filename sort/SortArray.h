#include<bits/stdc++.h>
using namespace std;

template <class Item>
class SortArray
{
    private:
	Item *s;
	int N;
	int sz;
	bool les(Item v, Item w);
	void exch(Item a[], int i, int j);
	void sort(Item a[], Item aux[], int lo, int hi);
	void merge(Item a[], Item aux[], int lo, int mid, int hi);
	int partition(Item a[], int lo, int hi);
	void sort(Item a[], int lo, int hi);
	void _3way_sort(Item a[], int lo, int hi);
	void priv_msd_sort(string *s, string *aux, int lo, int hi, int d);
	int charAt(string s, int d);
	void _3way_string_sort(Item a[], int lo, int hi, int d);
    public:
	SortArray();
	~SortArray();
	void add(Item item);
	void resize(int capacity);
	int size();
	void print();
	void selection_sort();
	void insertion_sort();
	void shell_sort();
	void knuth_shuffle();
	void merge_sort();
	void bottom_up_merge_sort();
	void quick_sort();
	void _3way_quick_sort();
	void lsd_sort(int W);
	void msd_sort();
	void _3way_string_sort();
};
