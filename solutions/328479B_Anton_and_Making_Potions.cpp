// Problem: Anton and Making Potions
// URL: https://codeforces.com/gym/328479/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, k;
ll n, x, s, fa[210000], fb[210000], sc[210000], sd[210000];


int main(){
    scanf("%lld%d%d%lld%lld", &n, &m, &k, &x, &s);
    for(int i=1; i<=m; i++) scanf("%lld", &fa[i]);
    for(int i=1; i<=m; i++) scanf("%lld", &fb[i]);
    for(int i=1; i<=k; i++) scanf("%lld", &sc[i]);
    for(int i=1; i<=k; i++) scanf("%lld", &sd[i]);
    ll ans=x*n;
    fa[0]=x;
    for(int i=0; i<=m; i++){
        if(fb[i]>s) continue;
        ll num=n;
        auto it=upper_bound(sd+1, sd+k+1, s-fb[i]);
        if(it>sd+1){ it--; num-=sc[it-sd];}
        ans=min(ans, fa[i]*num);
    }
    printf("%lld\n", ans);
    return 0;
}

