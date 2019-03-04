#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"QueueOfStrings.cpp"
//#include"QueueUsingArray.cpp"
//#include"QueueUsingResizingArray.cpp"
using namespace std;

int main() {
	string str;
	ifstream inFile;

	inFile.open("tobe.txt");
	if (!inFile) {
		cout << "Unable to open file.";
		exit(1); // terminate with error
	}
	QueueOfStrings *listQueue = new QueueOfStrings();
//	QueueUsingResizingArray *arrayQueue = new QueueUsingResizingArray();
	while (inFile >> str) {
		if (str == "-") {
			cout<<listQueue->dequeue()<<" ";
//			cout<<arrayQueue->dequeue()<<" ";
		}
		else {
			listQueue->enqueue(str);
//			arrayQueue->enqueue(str);
		}
	}
	cout<<"\n";
	inFile.close();
	return 0;
}
