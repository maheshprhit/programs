#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
    	int n, m, x = 0, y = 0;
    	vector<int> input_array, even_array, odd_array;
	cin >> n;
    	for (unsigned int j = 1; j <= n; ++j) {
	    cin >> m;
	    input_array.push_back(m);
	    if (abs(m) % 2 == 0) {
		even_array.push_back(m);
	    } else {
		odd_array.push_back(m);
	    }
	}
	x = y = 0;
	sort(even_array.begin(), even_array.end());
	sort(odd_array.begin(), odd_array.end());
	reverse(even_array.begin(), even_array.end());
	cout << "Case #" << i << ":";
    	for (unsigned int j = 0; j < n; ++j) {
	    if (input_array[j] % 2 == 0) {
		cout << " " << even_array[x++];
	    } else {
		cout << " " << odd_array[y++];
	    }
	}
	cout<<endl;
    }
    return 0;
}
