#include<bits/stdc++.h>
using namespace std;

int vector_to_int(vector<int> x)
{
    int y = 0;
    for (int i = x.size(); i >=0; i--) {
	y += x[x.size()-i]*pow(10, i-1);
    }
    return y;
}

int les(vector<int> x)
{
    int i;
    for (i = 0; i < x.size(); i++)
	if ((x[i] % 2) != 0) {
	    x[i] -= 1;
	    break;
	}
    for (int j = i+1; j < x.size(); j++)
	x[j] = 8;
    return vector_to_int(x);
}

int more(vector<int> x)
{
    int i;
    for (i = 0; i < x.size(); i++)
	if ((x[i] % 2) != 0) {
	    x[i] += 1;
	    if (x[i] == 10)
		x[i] = 0;
	    break;
	}
    for (int j = i+1; j < x.size(); j++)
	x[j] = 0;
    int k = i;
    while ((x[k] == 0) && (k > 0)) {
	k -= 1;
	x[k] += 2;
    }
    int s = 0;
    if (x[0] == 0) {
	s = 2 * pow(10, x.size());
    }

    return s+vector_to_int(x);
}

int evened_number(string N)
{
    vector<int> a;
    for (int i = 0; i < N.length(); i++) {
	a.push_back(N.at(i) - '0');
    }
    int x = vector_to_int(a);
    int M, P, X, Y;
    X = les(a);
    Y = more(a);
    M = x - X;
    P = Y - x;
    return min(M, P);
}

int main(int argc, char *argv[]) {
    int T, N;
    string word;
    string line;
    getline(cin, line);
    stringstream s(line);
    s >> T;
    string k;
    int tCount = 0;
    for (; getline(cin, line);) {
	stringstream s(line);
    	s >> k;
	int count = evened_number(k);
        cout<<"Case #"<<++tCount<<": "<<count<<endl;
    }
    return 0;
}
