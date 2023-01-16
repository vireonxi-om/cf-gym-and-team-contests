// Problem: Fair Distribution
// URL: https://codeforces.com/gym/103055/problem/F
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, l, r;


void solve(){
    scanf("%d%d", &n, &m);
    if(m%n==0){printf("0\n"); return;}
    if(m<n){ printf("%d\n", n-m); return;}
    k=m/n+1;
    int ans=1e9;
    for(; k<=m; ){
        l=(m+k-1)/k;
        ans=min(ans, n-l+l*k-m);
        if(l==1) break;
        k=(m+l-2)/(l-1);
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

