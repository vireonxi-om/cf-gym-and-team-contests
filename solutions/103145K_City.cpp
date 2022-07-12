// Problem: City
// URL: https://codeforces.com/gym/103145/problem/K
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q, fa[210000];
ll sz[210000], ans[210000];
vector<pair<pair<int, int>, pair<int, int>>> a;

int findfa(int u){
    return fa[u]==u? u: fa[u]=findfa(fa[u]);
}

void solve(){
    a.clear();
    scanf("%d%d%d", &n, &m, &q);
    int u, v, num;
    for(int i=1; i<=m; i++){
        sz[i]=1; fa[i]=i;
    }
    for(int i=1; i<=m; i++){
        scanf("%d%d%d", &u, &v, &num);
        a.push_back(make_pair(make_pair(num,1), make_pair(u, v)));
    }
    for(int i=1; i<=q; i++){
        scanf("%d", &num);
        a.push_back(make_pair(make_pair(num,0), make_pair(i, 0)));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int tot=a.size();
    ll now=0;
    for(int i=0; i<tot; i++){
        if(a[i].first.second==1){
            u=a[i].second.first; v=a[i].second.second;
            int fu=findfa(u), fv=findfa(v);
            if(fu!=fv){
                now-=(sz[fu])*(sz[fu]-1)/2;
                now-=(sz[fv])*(sz[fv]-1)/2;
                fa[fv]=fu;
                sz[fu]+=sz[fv];
                now+=(sz[fu])*(sz[fu]-1)/2;
            }
        }
        else{
            ans[a[i].second.first]=now;
        }
    }
    for(int i=1; i<=q; i++) printf("%lld\n", ans[i]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

