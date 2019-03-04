#include<string>
using namespace std;

class StackOfStrings {
    private:
	struct node {
	    string item;
	    node *next;
	};
	node *first;
    public:
	StackOfStrings() {
	    first = NULL;
	}
	void push(string item) {
	    node *oldfirst = first;
	    first = new node;
	    first->item = item;
	    first->next = oldfirst;
	}
	string pop() {
	    node *oldfirst = first;
	    string item = first->item;
	    first = first->next;
	    delete oldfirst;
	    return item;
	}
	bool isEmpty() {
	    return first == NULL;
	}
	int size();
};
