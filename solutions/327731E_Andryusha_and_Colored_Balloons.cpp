// Problem: Andryusha and Colored Balloons
// URL: https://codeforces.com/gym/327731/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m=0, col[210000];
vector<int> g[210000];

void dfs(int u, int v){
    if(g[u].size()==1) return;
    int c=col[u]+1; if(c>m) c=1;
    for(auto x:g[u]){
        if(x==v) continue;
        if(c==col[v]) {
            c++;
            if(c>m) c=1;
        }
        col[x]=c;
        c++; if(c>m) c=1;
        dfs(x, u);
    }
}

int main(){
    scanf("%d", &n);
    int x, y;
    for(int i=1; i<n; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<=n; i++) m=max(m, (int)g[i].size());
    m++;
    col[1]=1;
    g[1].push_back(0);
    dfs(1, 0);
    printf("%d\n", m);
    for(int i=1; i<=n; i++) printf("%d ", col[i]);
    printf("\n");
    return 0;
}
