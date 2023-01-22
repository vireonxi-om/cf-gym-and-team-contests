// Problem: Sum in the tree
// URL: https://codeforces.com/gym/310798/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, fa[110000];
ll a[110000], s[110000];
vector<int> g[110000];

int main(){
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        int now;
        scanf("%d", &now);
        g[now].push_back(i);
        fa[i]=now;
    }
    for(int i=1; i<=n; i++) scanf("%lld", &s[i]);
    bool can=true;
    for(int i=1; i<=n; i++){
        if(s[i]==-1){
            if(!g[i].empty()){
                ll mini=2e17, fav=s[fa[i]];
                for(auto x:g[i]) mini=min(mini, s[x]);
                if(mini<fav) {can=false; break;}
                a[i]=mini-fav;
                s[i]=mini;
                for(auto x:g[i]) a[x]=s[x]-mini;
            }
            else a[i]=0;
        }
    }
    a[1]=s[1];
    ll sum=0;
    for(int i=1; i<=n; i++) sum+=a[i];
    if(can) printf("%lld\n", sum);
    else printf("-1\n");
}
