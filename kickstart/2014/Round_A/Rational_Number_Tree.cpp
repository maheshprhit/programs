#include<bits/stdc++.h>
using namespace std;

void get_p_q(unsigned long long int n, unsigned long long int &p, unsigned long long int &q)
{
    if (n == 1) {
	p = 1;
	q = 1;
	return;
    }
    get_p_q(n/2, p, q);
    if (n%2 == 0)
	q = p+q;
    else
	p = p+q;
}

void get_n(unsigned long long int p, unsigned long long int q, unsigned long long int &n)
{
    if (p > q) {
	p = p - q;
	get_n(p, q, n);
	n = (n * 2) + 1;
    } else if (p < q) {
	q = q - p;
	get_n(p, q, n);
	n = n * 2;
    } else if (p == q) {
	n = 1;
    }
}

int main(int argc, char *argv[]) {
    unsigned long long int t, id, n, p, q;
    cin >> t;
    for (unsigned long long int i = 1; i <= t; ++i) {
	cin >> id;
	if (id == 1) {
	    cin >> n;
	    get_p_q(n, p, q);
	    cout << "Case #" << i << ": " << p << " " << q << endl;
	} else if (id == 2) {
	    cin >> p >> q;
	    get_n(p, q, n);
	    cout << "Case #" << i << ": " << n << endl;
	}
    }
    return 0;
}
