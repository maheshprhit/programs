#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    set<string> set;
    string key;
    std::pair<std::set<string>::iterator,bool> ret;

    while (cin >> key) {
	ret = set.insert(key);
	if (ret.second == true)
	    cout<<*ret.first<<endl;
    }
    return 0;
}
