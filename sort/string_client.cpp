#include<bits/stdc++.h>
#include"SortArray.h"
using namespace std;

int main(int argc, char *argv[]) {
    string word;
    int count;
    for (string line; getline(cin, line);) {
	SortArray<string> *ptr = new SortArray<string>();
	stringstream s(line);
	while (s >> word) {
	    ptr->add(word);
	}
	cout<<"Original array: ";
	ptr->print();
/*	cout<<"Selection sort: ";
	ptr->selection_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"Insertion sort: ";
	ptr->insertion_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"Shell sort    : ";
	ptr->shell_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"Merge sort    : ";
	ptr->merge_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"Bottom up MS  : ";
	ptr->bottom_up_merge_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"Quick sort    : ";
	ptr->quick_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"3Way Quicksort: ";
	ptr->_3way_quick_sort();
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"LSD Quicksort: ";
	ptr->lsd_sort(word.length());
	ptr->print();
	cout<<"Shuffled array: ";
	ptr->knuth_shuffle();
	ptr->print();
	cout<<"MSD Quicksort: ";
	ptr->msd_sort();
	ptr->print();
*/	cout<<"3 way string sort: ";
	ptr->_3way_string_sort();
	ptr->print();
    }
    return 0;
}
