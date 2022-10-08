// Problem: Producing Snow
// URL: https://codeforces.com/gym/318001/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll v[110000], t[110000];
multiset<ll> a;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &v[i]);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &t[i]);
        t[i]+=t[i-1];
    }
    multiset<ll>::iterator last, now;
    int pre=0;
    for(int i=1; i<=n; i++){
        a.insert(v[i]+t[i-1]);
        last=a.lower_bound(t[i-1]);
        now=a.lower_bound(t[i]);
        ll ans=0;
        while(last!=now){
            ans+=(*last)-t[i-1];
            pre++;
            last++;
        }
        ans+=(i-pre)*(t[i]-t[i-1]);
        printf("%lld ", ans);
    }
    return 0;
}
