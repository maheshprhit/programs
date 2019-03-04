#include<string>
#include<iterator>

using namespace std;

template <class Item>
class StackOfItemIterator {
    private:
	struct node {
	    Item item;
	    node *next;
	};
	node *first;
    public:
	StackOfItemIterator() {
	    first = NULL;
	}
	void push(Item item) {
	    node *oldfirst = first;
	    first = new node;
	    first->item = item;
	    first->next = oldfirst;
	}
	Item pop() {
	    node *oldfirst = first;
	    Item item = first->item;
	    first = first->next;
	    delete oldfirst;
	    return item;
	}
	bool isEmpty() {
	    return first == NULL;
	}
	int size();
};
