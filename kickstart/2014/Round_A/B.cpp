#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define ULL unsigned long long
using namespace std;
ULL two[64];
void go1(int lv,ULL n,ULL& p, ULL& q){
    if(lv==0){
        p=q=1;
        return;
    }
    ULL p2,q2;
    go1(lv-1,n>>1,p2,q2);
    if(n%2==0){
        p=p2;
        q=p2+q2;
    }
    else{
        p=p2+q2;
        q=q2;
    }
}
ULL go2(ULL p,ULL q){
    if(p==1&&q==1)return 1;
    if(p<q){
        return go2(p,q-p)*2;
    }
    else{
        return go2(p-q,q)*2+1;
    }
}
int main(){
    two[0]=1;
    REPP(i,1,64)two[i]=two[i-1]*2;
    CASET{
        DRI(id);
        if(id==1){
            ULL n;
            scanf("%llu",&n);
            int lv=0;
            while(n>two[lv]){
                n-=two[lv++];
            }
            ULL p,q;
            go1(lv,n-1,p,q);
            printf("Case #%d: ",case_n++);
            printf("%llu %llu\n",p,q);
        }
        else{
            printf("Case #%d: ",case_n++);
            ULL p,q;
            scanf("%llu%llu",&p,&q);
            printf("%llu\n",go2(p,q));
        }
        
    }
    return 0;
}
