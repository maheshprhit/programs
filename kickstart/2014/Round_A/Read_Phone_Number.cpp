#include<bits/stdc++.h>
using namespace std;

void print_digit_and_freq(int digit, int freq);

int main(int argc, char *argv[]) {
    int T, N;
    string word;
    string line;
    getline(cin, line);
    stringstream s(line);
    s >> T;
    string k, k1, k2;
    int tCount = 0;
    for (; getline(cin, line);) {
	stringstream s(line);
    	s >> k;
    	s >> k1;
	string::size_type sz;
        cout<<"Case #"<<++tCount<<":";
	int digit, freq = 0;
	digit = k.at(0)-'0';
	int i = 0, j, l = 0, d = 0, p;
	k2 = k1;
	do {
	    j = abs(stoi(k2, &sz));
	    digit = k.at(d)-'0';
	    freq = 1;
	    for (i = d+1; i < d+j; i++) {
		if (digit == k.at(i)-'0') {
		    freq++;
		    continue;
		} else {
		    if (freq > 10) {
			for (int q = 0; q < freq; q++)
			    print_digit_and_freq(digit, 0);
		    } else {
    			print_digit_and_freq(digit, freq);
		    }
		    digit = k.at(i)-'0';
		    freq = 1;
		}
	    }
	    if (freq > 10) {
		for (int q = 0; q < freq; q++)
		    print_digit_and_freq(digit, 0);
	    } else {
		print_digit_and_freq(digit, freq);
	    }
    	    d += j;
	    k2 = k2.substr(sz);
	} while (k2 !="");
	cout<<endl;
    }
}

void print_digit_and_freq(int digit, int freq)
{
    switch (freq)
    {
    	case 2:
	    cout<<" double";
	    break;
	case 3:
	    cout<<" triple";
	    break;
	case 4:
	    cout<<" quadruple";
	    break;
	case 5:
	    cout<<" quintuple";
	    break;
	case 6:
	    cout<<" sextuple";
	    break;
	case 7:
	    cout<<" septuple";
	    break;
	case 8:
	    cout<<" octuple";
	    break;
	case 9:
	    cout<<" nonuple";
	    break;
	case 10:
	    cout<<" decuple";
	    break;
	default:
	    break;
    }
    switch (digit)
    {
	case 0:
	    cout<<" zero";
	    break;
	case 1:
	    cout<<" one";
	    break;
	case 2:
	    cout<<" two";
	    break;
	case 3:
	    cout<<" three";
	    break;
	case 4:
	    cout<<" four";
	    break;
	case 5:
	    cout<<" five";
	    break;
	case 6:
	    cout<<" six";
	    break;
	case 7:
	    cout<<" seven";
	    break;
	case 8:
	    cout<<" eight";
	    break;
	case 9:
	    cout<<" nine";
	    break;
	default:
	    break;
    }
}
