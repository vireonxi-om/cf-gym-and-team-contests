// Problem: Longest Simple Cycle
// URL: https://codeforces.com/gym/316836/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000], b[110000], c[110000], d[110000], l[110000];
ll sum[110000], m[110000];
vector<int> pos;

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) sum[i]=0;
    pos.clear();
    pos.push_back(1);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    for(int i=1; i<n; i++){
        l[i]=abs(b[i]-a[i]);
        if(l[i]==0) pos.push_back(i);
    }
    pos.push_back(n);
    for(int i=2; i<=n; i++) d[i]=c[i]-l[i-1]+1;
    auto it=pos.begin(), next=it+1;
    ll ans=0;
    while(next!=pos.end()){
        for(int i=(*it)+1; i<=(*next); i++) sum[i]=sum[i-1]+d[i];
        m[(*next)]=sum[(*next)];
        for(int i=(*next)-1; i>(*it); i--) m[i]=max(sum[i], m[i+1]);
        for(int i=(*it); i<(*next); i++){
            ans=max(ans, m[i+1]-sum[i]+2*l[i]);
        }
        it++; next++;
    }
    /*for(auto x:pos) printf("%d ", x); printf("\n");
    for(int i=1; i<=n; i++) printf("%d ", d[i]); printf("\n");
    for(int i=1; i<=n; i++) printf("%lld ", sum[i]); printf("\n");
    for(int i=1; i<=n; i++) printf("%lld ", m[i]); printf("\n");*/
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}