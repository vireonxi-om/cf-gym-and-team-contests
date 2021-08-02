// Problem: Grid-00100
// URL: https://codeforces.com/gym/306616/problem/J
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, a[310][310];

void solve(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) a[i][j]=0;
    int d=-1, s, t;
    bool finish=true;
    while(k>0){
        d++;
        for(s=1; s<=n; s++){
            if(k==0){
                finish=false;
                break;
            }
            int t=s-d;
            if(t<1) t+=n;
            a[s][t]=1;
            k--;
        }
    }
    int result;
    if(finish) result=0;
    else result=2;
    printf("%d\n", result);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) printf("%d", a[i][j]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}


