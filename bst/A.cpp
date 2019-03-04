#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

struct node {
    node *nx[2];
    int depth;
    int flag;
};

node *root;

LL total = 0;

node *create() {
    node *tmp = new node();
    tmp->nx[0] = tmp->nx[1] = NULL;
    tmp->depth = 0;
    tmp->flag = 0;
    return tmp;
}

string s;
int n,p;

void insert() {
    node *curr = root;
    for(int i = 0;i < s.size();i++) {
        int nx = s[i] - 'B';
        if(nx != 0) nx = 1;
        if(curr->nx[nx] == NULL) {
            curr->nx[nx] = create();
            curr->nx[nx]->depth = i + 1;
        }
        curr = curr->nx[nx];
    }
    curr->flag = 1;
}

void traverse(node *curr) {
    if(curr == NULL) return ;
    if(curr->flag) return ;
    if(curr->nx[0] == NULL) {
        int x = curr->depth;
        total += (1LL<<(n - x));
    }
    if(curr->nx[1] == NULL) {
        int x = curr->depth;
        total += (1LL<<(n - x));    
    }
    if(curr->nx[1]) traverse(curr->nx[1]);
    if(curr->nx[0]) traverse(curr->nx[0]);
}

void clear(node *curr) {
    if(curr->nx[0]) clear(curr->nx[0]);
    if(curr->nx[1]) clear(curr->nx[1]);
    delete(curr);
}

int main(){
    //desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int ntc;
    cin>>ntc;
    for(int tc = 1;tc <= ntc;tc++) {
        root = create();
        total = 0;
        cin>>n>>p;
        for(int i = 0;i < p;i++) {
            cin>>s;
            insert();
        }
        traverse(root);
        cout<<"Case #"<<tc<<": "<<total / 2<<endl;
        clear(root);
    }
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


