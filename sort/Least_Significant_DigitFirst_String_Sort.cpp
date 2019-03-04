#include<bits/stdc++.h>
using namespace std;

class LSD {
    public:
	void sort(string a, int W) {
	    int R = 256;
	    int N = a.length();
	    string aux;
	    for (int d = W-1; d >= 0; d--) {
		int count[R+1];
		for (int i = 0; i < N; i++)
		    count 



int main(int argc, char *argv[]) {
    int word;
    int count;
    for (string line; getline(cin, line);) {
	SortArray<int> *ptr = new SortArray<int>();
	stringstream s(line);
	while (s >> word) {
	    ptr->add(word);
	}
    }
}
