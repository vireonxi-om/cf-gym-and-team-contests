// Problem: Circle of Monsters
// URL: https://codeforces.com/gym/308172/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[310000], b[310000], c[310000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld%lld", &a[i], &b[i]);
    }
    ll sum=0;
    for(int i=2; i<=n; i++){
        c[i]=max((ll)0, a[i]-b[i-1]);
        sum+=c[i];
    }
    c[1]=max((ll)0, a[1]-b[n]); sum+=c[1];
    ll result=1e18;
    for(int i=1; i<=n; i++) result=min(result, a[i]-c[i]+sum);
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

