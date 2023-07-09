// Problem: Grammy and Jewelry
// URL: https://codeforces.com/gym/103055/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t, a[3100], ans[3100], dis[3100];
queue<int> q;
vector<int> g[3100];

void bfs(int u){
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto x:g[v]){
            if(dis[x] || x==1) continue;
            dis[x]=dis[v]+1;
            q.push(x);
        }
    }
}


int main(){
    scanf("%d%d%d", &n, &m, &t);
    for(int i=2; i<=n; i++) scanf("%d", &a[i]);
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i=2; i<=n; i++){
        if(dis[i]*2>t) continue;
        ans[dis[i]*2]=max(ans[dis[i]*2], a[i]);
    }
    for(int i=1; i<=t; i++) ans[i]=max(ans[i], ans[i-1]);
    for(int i=2; i<=t; i++){
        for(int j=1; j<=i; j++){
            ans[i]=max(ans[i], ans[j]+ans[i-j]);
        }
    }
    for(int i=1; i<=t; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
