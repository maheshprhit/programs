#include<string>
using namespace std;

class QueueOfStrings {
    private:
	struct node {
	    string item;
	    node *next;
	};
	node *first, *last;
    public:
	QueueOfStrings() {
	    first = NULL;
	    last = NULL;
	}
	bool isEmpty() {
	    return first == NULL;
	}
	void enqueue(string item) {
	    node *oldlast = last;
	    last = new node;
	    last->item = item;
	    last->next = NULL;
	    if (isEmpty())
		first = last;
	    else
		oldlast->next = last;
	}
	string dequeue() {
	    node *oldfirst = first;
	    string item = first->item;
	    first = first->next;
	    if (isEmpty())
		last = NULL;
	    delete oldfirst;
	    return item;
	}
	int size();
};
