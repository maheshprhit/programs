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
#include<sstream>
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
using namespace std;
#define SIZE 1000
char s1[SIZE],s2[SIZE];
char ten[10][16]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char name[11][16]={"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
int main(){
    CASET{
        scanf("%s%s",s1,s2);
        for(int i=0;s2[i];i++){
            if(s2[i]=='-')s2[i]=' ';
        }
        stringstream ss(s2);
        vector<int>d;
        int tmp;
        while(ss>>tmp){
            d.PB(tmp);
        }
        printf("Case #%d:",case_n++);
        int now=0;
        REP(i,SZ(d)){
            vector<int>e;
            REP(j,d[i])e.PB(s1[now+j]-'0');
            now+=d[i];
            for(int j=0,k;j<SZ(e);j=k){
                for(k=j+1;k<SZ(e)&&e[k]==e[j];k++);
                if(k-j<2||k-j>10){
                    REP(it,k-j)printf(" %s",ten[e[j]]);
                }
                else{
                    printf(" %s %s",name[k-j],ten[e[j]]);
                }
            }
        }
        puts("");
    }
    return 0;
}
