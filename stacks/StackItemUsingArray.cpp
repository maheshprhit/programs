#include<string>
using namespace std;

template <class Item>
class StackItemUsingArray {
    private:
	Item *s;
	int N;
    public:
	StackItemUsingArray(int capacity) {
	    s = new Item[capacity];
	    N = 0;
	}
	~StackItemUsingArray() {
	    delete s;
	}
	void push(Item item) {
	    s[N++] = item;
	}
	Item pop() {
	    Item item = s[--N];
	    s[N] = "";
	    return item;
	}
	bool isEmpty() {
	    return N == 0;
	}
	int size();
};
