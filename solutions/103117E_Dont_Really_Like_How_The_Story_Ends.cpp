// Problem: Don't Really Like How The Story Ends
// URL: https://codeforces.com/gym/103117/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, u, v, ans;
set<int> g[110000];

int dfs(int a){
    int l=a;
    for(auto x: g[a]){
        if(x<=l) continue;
        for(int i=l+1; i<x; i++){
            if(i<=l){ i=l; continue;}
            l=dfs(i);
            ans++;
        }
        if(x<=l) continue;
        l=dfs(x);
    }
    return l;
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n+1; i++) g[i].clear();
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].insert(v);
        g[v].insert(u);
    }
    g[1].insert(n+1);
    ans=0;
    int l=dfs(1);
    if(l<n) ans+=n-l;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


