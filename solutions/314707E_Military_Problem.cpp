// Problem: Military Problem
// URL: https://codeforces.com/gym/314707/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, pos=1, ans[210000], id[210000], sz[210000];
vector<int> g[210000];

void dfs(int u, int v){
    ans[pos]=u; id[u]=pos; pos++;
    for(auto x:g[u]){
        if(x!=v){
            dfs(x, u);
            sz[u]+=sz[x];
        }
    }
}

int main(){
    scanf("%d%d", &n, &q);
    int num;
    for(int i=2; i<=n; i++){
        scanf("%d", &num);
        g[num].push_back(i);
        g[i].push_back(num);
    }
    for(int i=1; i<=n; i++) sz[i]=1;
    dfs(1,0);
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        if(sz[x]<y) printf("-1\n");
        else printf("%d\n", ans[id[x]+y-1]);
    }
    return 0;
}