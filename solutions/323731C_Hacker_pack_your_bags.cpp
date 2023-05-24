// Problem: Hacker, pack your bags!
// URL: https://codeforces.com/gym/323731/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, x;
ll ans=-1, cost[210000];
set<pair<int, pair<ll, int>>> a, b;

int main(){
    scanf("%d%d", &n, &x);
    int l, r;
    ll c;
    for(int i=1; i<=n; i++){
        scanf("%d%d%lld", &l, &r, &c);
        if(r-l+1>=x) continue;
        a.insert(make_pair(l, make_pair(c, r-l+1)));
        b.insert(make_pair(r, make_pair(c, r-l+1)));
    }
    auto ita=a.begin(), itb=b.begin();
    while(ita!=a.end() && (*ita).first<=(*itb).first) ita++;
    while(ita!=a.end()){
        while(itb!=b.end() && (*itb).first<(*ita).first){
            ll num=(*itb).second.first; int len=(*itb).second.second;
            if(cost[len]) cost[len]=min(cost[len], num);
            else cost[len]=num;
            itb++;
        }
        while(ita!=a.end() && (itb==b.end() || (*ita).first<=(*itb).first)){
            int len=(*ita).second.second;
            ll num=(*ita).second.first;
            if(cost[x-len]){
                if(ans!=-1) ans=min(ans, num+cost[x-len]);
                else ans=num+cost[x-len];
            }
            ita++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}