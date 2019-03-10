#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int distinct = 0;
    int words = 0;
    int minlen = stoi(argv[1]);
    map<string, int> st;
    string key;

    // compute frequence counts
    while (cin >> key) {
	if (key.length() < minlen)
	    continue;
	words++;
	if (st.count(key) > 0) {
	    st.at(key)++;
	} else {
	    st.insert({key, 1});
	    distinct++;
	}
    }

    // find a key with the highest frequence count
    string max = "";
    st.insert({max, 0});
    for (auto it : st) {
	if (it.second > st.at(max)) {
	    max = it.first;
	}
    }
    cout<<max<<" "<<st.at(max)<<endl;
    cout<<"distinct = "<<distinct<<endl;
    cout<<"words = "<<words<<endl;

    return 0;
}
