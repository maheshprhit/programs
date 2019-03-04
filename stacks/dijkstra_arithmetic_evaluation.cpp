#include<iostream>
#include"StackOfItem.cpp"
using namespace std;

int main() {
	char c;
	StackOfItem<char> *ops = new StackOfItem<char>();
	StackOfItem<int> *vals = new StackOfItem<int>();
	while (cin.peek() != '\n') {
	    cin.get(c);
	    if (c == '(') {
	    } else if (c == '+') {
		ops->push(c);
            } else if (c == '-') {
		ops->push(c);
	    } else if (c == '*') {
		ops->push(c);
	    } else if (c == ')') {
		char op = ops->pop();
		if (op == '+') {
		    vals->push(vals->pop() + vals->pop());
		} else if (op == '-') {
		    vals->push(vals->pop() - vals->pop());
		} else if (op == '*') {
		    vals->push(vals->pop() * vals->pop());
		}
	    } else {
		vals->push(c - '0');
	    }
	}
	cout <<"Result = "<<vals->pop()<<endl;
	return 0;
}
