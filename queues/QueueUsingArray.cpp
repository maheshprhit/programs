#include<string>
using namespace std;

class QueueUsingArray {
    private:
	string *s;
	int N;
    public:
	QueueUsingArray(int capacity) {
	    s = new string[capacity];
	    N = 0;
	}
	~QueueUsingArray() {
	    delete s;
	}
	void push(string item) {
	    s[N++] = item;
	}
	string pop() {
	    string item = s[--N];
	    s[N] = "";
	    return item;
	}
	bool isEmpty() {
	    return N == 0;
	}
	int size();
};
