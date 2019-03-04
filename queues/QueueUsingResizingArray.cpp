#include<string>
#include<iostream>
using namespace std;

class QueueUsingResizingArray {
    private:
	string *s;
	int N;
	int sz;
    public:
	QueueUsingResizingArray() {
	    N = 0;
	    sz = 1;
	    s = new string[sz];
	}
	~QueueUsingResizingArray() {
	    delete s;
	}
	void push(string item) {
	    if (N == sz) {
		resize(2 * sz);
	    }
	    s[N++] = item;
	}
	string pop() {
	    string item = s[--N];
	    s[N] = "";
	    if ((N > 0) && (N == sz/4))
		resize(sz/2);
	    return item;
	}
	bool isEmpty() {
	    return N == 0;
	}
	int size();
	void resize(int capacity)
	{
	    string *copy = new string[capacity];
	    sz = capacity;
	    for (int i = 0; i < N; i++) {
		copy[i] = s[i];
	    }
	    s = copy;
	}
};
