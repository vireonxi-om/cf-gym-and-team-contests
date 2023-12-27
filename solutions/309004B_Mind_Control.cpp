// Problem: Mind Control
// URL: https://codeforces.com/gym/309004/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[3600], maxi[3600];

void solve(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=m; i++) maxi[i]=max(a[i], a[i+n-m]);
    int result=0;
    for(int i=1; i<=min(k+1, m); i++){
        int now=2*1e9;
        for(int j=i; j<i+max(m-k, 1); j++){
            now=min(now, maxi[j]);
        }
        result=max(result, now);
    }
    if(m==1) printf("%d\n", max(a[1], a[n]));
    else printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}