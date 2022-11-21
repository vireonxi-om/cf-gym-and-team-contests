// Problem: Barbells
// URL: https://codeforces.com/gym/101291/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[20], b[20];
set<ll> p, ans;

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=m; i++) scanf("%lld", &b[i]);
    int t=1;
    for(int i=1; i<=m; i++) t*=3;
    for(int i=0; i<t; i++){
        ll cnt1=0, cnt2=0;
        int now=i, pos=1;
        while(now){
            if(now%3==1) cnt1+=b[pos];
            if(now%3==2) cnt2+=b[pos];
            pos++;
            now/=3;
        }
        if(cnt1==cnt2) p.insert(cnt1);
    }
    for(int i=1; i<=n; i++){
        for(auto x:p) ans.insert(a[i]+2*x);
    }
    for(auto x:ans) printf("%lld\n", x);
    printf("\n");
    return 0;
}
