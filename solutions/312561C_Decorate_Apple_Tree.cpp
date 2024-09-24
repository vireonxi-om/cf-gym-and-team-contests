// Problem: Decorate Apple Tree
// URL: https://codeforces.com/gym/312561/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, sz[110000], num[110000];
vector<int> g[110000];

void dfs(int u, int v){
    if(g[u].size()==1){ sz[u]=1; sz[1]++; return;}
    for(auto x:g[u]){
        if(x!=v){
            dfs(x, u);
            sz[u]+=sz[x];
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        int num;
        scanf("%d", &num);
        g[i].push_back(num);
        g[num].push_back(i);
    }
    for(auto x:g[1]) dfs(x, 1);
    sort(sz+1, sz+n+1);
    if(n==1) sz[1]=1;
    for(int i=1; i<=n; i++) printf("%d ", sz[i]);
    printf("\n");
}

