// Problem: Timofey and a tree
// URL: https://codeforces.com/gym/328082/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c[110000];
vector<int> g[110000];

bool check(int u, int v, int col){
    if(c[u]!=col) return false;
    bool yes=true;
    for(auto x:g[u]){
        if(x==v) continue;
        if(!check(x, u, col)) yes=false;
    }
    return yes;
}


int main(){
    scanf("%d", &n);
    int u, v;
    for(int i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    bool can=true;
    int ans=1;
    for(int i=1; i<=n; i++){
        for(auto x:g[i]){
            if(c[i]!=c[x]){
                can=false;
                u=i; v=x;
            }
        }
    }
    if(!can){
        bool yes=true, yes2=true;
        for(auto x:g[u]){
            if(!check(x, u, c[x])) yes=false;
        }
        for(auto x:g[v]){
            if(!check(x, v, c[x])) yes2=false;
        }
        if(yes){ can=true; ans=u;}
        else if(yes2){ can=true; ans=v;}
    }
    if(can) printf("YES\n%d\n", ans);
    else printf("NO\n");
    return 0;
}
