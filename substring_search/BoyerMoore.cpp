#include<bits/stdc++.h>
using namespace std;
class BoyerMoore
{
    private:
	int R;
	int *right;
	string pat;
	int charAt(string s, int d)
	{
	    if (d < s.length())
		return s.at(d);
	    else
		return -1;
	}
    public:
	BoyerMoore(string pat)
	{
	    this->R = 256;
	    this->pat = pat;
	    right = new int[R];
	    for (int c = 0; c < R; c++)
		right[c] = -1;
	    for (int j = 0; j < pat.length(); j++)
		right[charAt(pat, j)] = j;
	}
	int search(string txt)
	{
	    int i, j;
	    int M = pat.length();
	    int N = txt.length();
	    int skip;
	    for (i = 0; i <= N-M; i+=skip) {
		skip = 0;
		for (j = M-1; j >= 0; j--) {
		    if (charAt(pat, j) != charAt(txt, i+j)) {
			skip = max(1, j - right[charAt(txt, i+j)]);
			break;
		    }
		}
		if (skip == 0)
		    return i;
	    }
	    return N;
	}
};

int main(int argc, char *argv[]) {
    string pat = argv[1];
    string txt = argv[2];
    BoyerMoore boyermoore(pat);
    int offset1a = boyermoore.search(txt);
    cout<<"offset1: "<<offset1a<<endl;
    cout<<"text   : "<<txt<<endl;
    cout<<"pattern: ";
    for (int i = 0; i < offset1a; i++)
	cout<<" ";
    cout<<pat<<endl;
    return 0;
}
