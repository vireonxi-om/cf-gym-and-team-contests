// Problem: Kuro and Walking Route
// URL: https://codeforces.com/gym/316836/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, x, y, d[310000], sz[310000];
vector<int> g[310000];

void dfs(int u, int v){
    sz[u]=1;
    for(auto t:g[u]){
        if(t!=v){
            dfs(t, u);
            sz[u]+=sz[t];
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &x, &y);
    int u, v;
    for(int i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x, 0);
    int szy=sz[y];
    for(int i=1; i<=n; i++) sz[i]=0;
    dfs(y, 0);
    int szx=sz[x];
    ll ans=(ll)n*(n-1)-(ll)szx*szy;
    printf("%lld\n", ans);
}
