// Problem: Socks
// URL: https://codeforces.com/gym/328479/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, c[210000], yes[210000];
vector<int> g[210000];
set<pair<int, int>> s;

void dfs(int u, int v){
    auto it=s.lower_bound(make_pair(c[u], 0));
    if(it==s.end() || (*it).first!=c[u]) s.insert(make_pair(c[u], 1));
    else{
        int num=(*it).second;
        s.erase(it);
        s.insert(make_pair(c[u], num+1));
    }
    yes[u]=1;
    for(auto x: g[u]){
        if(x==v || yes[x]==1) continue;
        dfs(x, u);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0, now, sum;
    for(int i=1; i<=n; i++){
        if(!yes[i]){
            s.clear();
            dfs(i, 0);
            now=0; sum=0;
            for(auto x: s){ now=max(now, x.second); sum+=x.second;}
            ans+=(sum-now);
        }
    }
    printf("%d\n", ans);
    return 0;
}

