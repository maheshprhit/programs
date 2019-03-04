#include<bits/stdc++.h>
using namespace std;
class KMP
{
    private:
	int R;
	int **dfa;
	string pat;
	int charAt(string s, int d)
	{
	    if (d < s.length())
		return s.at(d);
	    else
		return -1;
	}
    public:
	KMP(string pat)
	{
	    this->R = 256;
	    this->pat = pat;
	    int M = pat.length();
	    dfa = new int*[R];
	    for (int i = 0; i < R; i++)
		dfa[i] = new int[M];
	    dfa[charAt(pat, 0)][0] = 1;
	    for (int X = 0, j = 1; j < M; j++) {
		for (int c = 0; c < R; c++)
		    dfa[c][j] = dfa[c][X];
		dfa[charAt(pat, j)][j] = j + 1;
		X = dfa[charAt(pat, j)][X];
	    }
	}
	int search(string txt)
	{
	    int i, j;
	    int M = pat.length();
	    int N = txt.length();
	    for (i = 0, j = 0; i < N && j < M; i++) {
		j = dfa[charAt(txt, i)][j];
	    }
	    if (j == M) {
		return i - M;
	    } else {
		return N;
	    }
	}
};

int main(int argc, char *argv[]) {
    string pat = argv[1];
    string txt = argv[2];
    KMP kmp(pat);
    int offset1a = kmp.search(txt);
    cout<<"offset1: "<<offset1a<<endl;
    cout<<"text   : "<<txt<<endl;
    cout<<"pattern: ";
    for (int i = 0; i < offset1a; i++)
	cout<<" ";
    cout<<pat<<endl;
    return 0;
}
