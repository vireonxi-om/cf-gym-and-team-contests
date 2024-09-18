// Problem: Alyona and the Tree
// URL: https://codeforces.com/gym/329293/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, yes[110000];
ll a[110000], dis[110000], m[110000];
vector<pair<int, ll>> g[110000];

void dfs(int u, ll w, int v){
    dis[u]=dis[v]+w;
    m[u]=min(m[v], dis[u]);
    if(yes[v]) yes[u]=1;
    if(a[u]<dis[u]-m[v]) yes[u]=1;
    if(g[u].size()==1) return;
    for(auto x: g[u]){
        if(x.first==v) continue;
        dfs(x.first, x.second, u);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    int u; ll w;
    for(int i=1; i<n; i++){
        scanf("%d%lld", &u, &w);
        g[i+1].push_back(make_pair(u, w));
        g[u].push_back(make_pair(i+1, w));
    }
    g[1].push_back(make_pair(0, 0));
    dfs(1, 0, 0);
    int cnt=0;
    //for(int i=1; i<=n; i++) printf("%lld ", dis[i]); printf("\n");
    //for(int i=1; i<=n; i++) printf("%lld ", m[i]); printf("\n");
    //for(int i=1; i<=n; i++) printf("%d ", yes[i]); printf("\n");
    for(int i=1; i<=n; i++) if(yes[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}