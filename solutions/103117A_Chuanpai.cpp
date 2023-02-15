// Problem: Chuanpai
// URL: https://codeforces.com/gym/103117/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;

void solve(){
    scanf("%d", &k);
    int ans=0, j;
    for(int i=1; i<=k; i++){
        j=k-i;
        if(j>=i && i<=6 && j<=6) ans++;
        if(j<i) break;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


