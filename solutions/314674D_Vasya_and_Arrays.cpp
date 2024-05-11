// Problem: Vasya and Arrays
// URL: https://codeforces.com/gym/314674/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, result;
ll a[310000], b[310000];
map<ll, int> ans;

int main(){
    a[0]=0; b[0]=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        a[i]+=a[i-1]; ans[a[i]]++;
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++) {
        scanf("%lld", &b[i]);
        b[i]+=b[i-1]; ans[b[i]]++;
    }
    if(a[n]!=b[m]){ printf("-1\n"); return 0; }
    for(auto p:ans){
        if(p.second==2) result++;
    }
    printf("%d\n", result);
    return 0;
}