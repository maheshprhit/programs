#include<bits/stdc++.h>
using namespace std;
class BruteForceSubstringSearch
{
    private:
	int charAt(string s, int d)
	{
	    if (d < s.length())
		return s.at(d);
	    else
		return -1;
	}
    public:
	BruteForceSubstringSearch()
	{
	}
	int search1(string pat, string txt)
	{
	    int M = pat.length();
	    int N = txt.length();
	    for (int i = 0; i <= (N-M); i++) {
		int j;
		for (j = 0; j < M; j++) {
		    if (charAt(txt, i+j) != charAt(pat, j))
			break;
		}
		if (j == M) {
		    return i;
		}
	    }
	    return N;
	}
	int search2(string pat, string txt)
	{
	    int i, j;
	    int M = pat.length();
	    int N = txt.length();
	    for (i = 0, j = 0; i < N && j < M; i++) {
		if (charAt(txt, i) == charAt(pat, j)) {
		    j++;
		} else {
		    i -= j;
		    j = 0;
		}
	    }
	    if (j == M) {
		return i - M;
	    } else {
		return N;
	    }
	}
};

int main(int argc, char *argv[]) {
    BruteForceSubstringSearch bfs;
    string pat = argv[1];
    string txt = argv[2];
    int offset1a = bfs.search1(pat, txt);
    cout<<"offset1: "<<offset1a<<endl;
    cout<<"text   : "<<txt<<endl;
    cout<<"pattern: ";
    for (int i = 0; i < offset1a; i++)
	cout<<" ";
    cout<<pat<<endl;
    int offset2a = bfs.search2(pat, txt);
    cout<<"offset2: "<<offset2a<<endl;
    cout<<"text   : "<<txt<<endl;
    cout<<"pattern: ";
    for (int i = 0; i < offset1a; i++)
	cout<<" ";
    cout<<pat<<endl;
    return 0;
}
