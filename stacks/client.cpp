#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"StackOfStrings.cpp"
#include"StackOfItem.cpp"
#include"StackUsingArray.cpp"
#include"StackItemUsingArray.cpp"
#include"StackUsingResizingArray.cpp"
using namespace std;

int main() {
	string str;
	ifstream inFile;

	inFile.open("tobe.txt");
	if (!inFile) {
		cout << "Unable to open file.";
		exit(1); // terminate with error
	}
	StackOfStrings *listStack = new StackOfStrings();
	StackOfItem<string> *listItemStack = new StackOfItem<string>();
	StackOfItem<int> *listIntStack = new StackOfItem<int>();
	StackItemUsingArray<string> *arrayItemStack = new StackItemUsingArray<string>(10);
	StackUsingResizingArray *arrayStack = new StackUsingResizingArray();
	while (inFile >> str) {
		if (str == "-") {
			cout<<listStack->pop()<<" ";
			cout<<listItemStack->pop()<<" ";
			cout<<arrayStack->pop()<<" ";
			cout<<arrayItemStack->pop()<<" ";
		}
		else {
			listStack->push(str);
			listItemStack->push(str);
			arrayStack->push(str);
			arrayItemStack->push(str);
		}
	}
	cout<<"\n";
	inFile.close();
	listIntStack->push(10);
	listIntStack->push(11);
	cout<<listIntStack->pop()<<" ";
	cout<<listIntStack->pop()<<" ";
	return 0;
}
