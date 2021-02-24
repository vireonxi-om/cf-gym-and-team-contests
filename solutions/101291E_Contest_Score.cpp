// Problem: Contest Score
// URL: https://codeforces.com/gym/101291/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[310];
priority_queue<ll> q;


int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=k; i++) q.push(-a[i]);
    int pos=k+1;
    ll ans=0, now=0;
    while(!q.empty()){
        ll num=-q.top();
        q.pop();
        now+=num;
        ans+=now;
        if(pos<=n){ q.push(-a[pos]); pos++;}
    }
    printf("%lld\n", ans);
    return 0;
}
