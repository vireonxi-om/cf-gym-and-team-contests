// Problem: Add on a Tree
// URL: https://codeforces.com/gym/310046/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<int> g[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool can=true;
    for(int i=1; i<=n; i++){
        if(g[i].size()==2) can=false;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
