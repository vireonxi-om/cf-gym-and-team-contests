// Problem: Linova and Kingdom
// URL: https://codeforces.com/gym/308172/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, dep[210000], siz[210000], r[210000];
vector<int> g[210000];

void dfs(int i, int pre){
    dep[i]=dep[pre]+1;
    siz[i]=1;
    for(auto u:g[i]){
        if(u!=pre){
            dfs(u, i);
            siz[i]+=siz[u];
        }
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++) r[i]=siz[i]-dep[i];
    sort(r+1, r+n+1);
    ll result=0;
    for(int i=n; i>k; i--) result+=r[i];
    printf("%lld\n", result);
    return 0;
}
