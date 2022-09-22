// Problem: Spanning Tree with Maximum Degree
// URL: https://codeforces.com/gym/310796/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
bool used[210000];
vector<int> g[210000];
vector<pair<int, int>> ans;

void dfs(int i){
    for(auto x:g[i]){
        if(!used[x]){
            ans.push_back(make_pair(i, x));
            used[x]=true;
            dfs(x);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int x, y;
    for(int i=1; i<=n; i++) used[i]=false;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int maxi=0, t=0;
    for(int i=1; i<=n; i++){
        if(g[i].size()>maxi){
            maxi=g[i].size();
            t=i;
        }
    }
    used[t]=true;
    for(auto x:g[t]){
        ans.push_back(make_pair(t,x));
        used[x]=true;
    }
    for(auto x:g[t]) dfs(x);
    for(auto x:ans) printf("%d %d\n", x.first, x.second);
    return 0;
}
