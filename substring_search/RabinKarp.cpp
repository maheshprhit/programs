#include<bits/stdc++.h>
using namespace std;
class RabinKarp
{
    private:
	int R;
	string pat;
	long patHash;
	int m;
	long q;
	long RM;
	int charAt(string s, int d)
	{
	    if (d < s.length())
		return s.at(d);
	    else
		return -1;
	}
	long hash(string key, int m)
	{
	    long h = 0;
	    for (int j = 0; j < m; j++)
		h = (R * h + charAt(key, j)) % q;
	    return h;
	}
	bool check(string txt, int i)
	{
	    for (int j = 0; i < m; j++)
		if (charAt(pat, j) != charAt(txt, i+j))
		    return false;
	    return true;
	}
	long longRandomPrime()
	{
	    return rand();
	}
    public:
	RabinKarp(string pat)
	{
	    this->R = 256;
	    this->pat = pat;
	    this->m = pat.length();
//	    this->q = longRandomPrime();
	    this->q = 997;
	    RM = 1;
	    for (int i = 1; i < m-1; i++)
		RM = (R * RM) % q;
	    patHash = hash(pat, m);
	}
	int search(string txt)
	{
	    int n = txt.length();
	    if (n < m)
		return n;
	    long txtHash = hash(txt, m);
	    if ((patHash == txtHash) && check(txt, 0))
		return 0;
	    for (int i = m; i < n; i++) {
		txtHash = (txtHash + q - ((RM*charAt(txt, i-m)) % q)) % q;
		txtHash = (txtHash*R + charAt(txt, i)) % q;
		int offset = i - m + 1;
		if ((patHash == txtHash) && check(txt, offset))
		    return offset;
	    }
	    return n;
	}
};

int main(int argc, char *argv[]) {
    string pat = argv[1];
    string txt = argv[2];
    RabinKarp rk(pat);
    int offset1a = rk.search(txt);
    cout<<"offset1: "<<offset1a<<endl;
    cout<<"text   : "<<txt<<endl;
    cout<<"pattern: ";
    for (int i = 0; i < offset1a; i++)
	cout<<" ";
    cout<<pat<<endl;
    return 0;
}
