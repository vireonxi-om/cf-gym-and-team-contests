// Problem: Mortal Kombat Tower
// URL: https://codeforces.com/gym/305901/problem/E
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[210000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int p=0, cnt=0;
    a[n+1]=0;
    if(a[1]==1) p++;
    for(int i=2; i<=n+1; i++){
        if(a[i]==0 && a[i-1]==1){
            p+=cnt/3;
            cnt=0;
        }
        else if(a[i]==1) cnt++;
    }
    printf("%d\n", p);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

