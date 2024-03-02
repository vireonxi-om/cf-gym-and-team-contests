// Problem: Matching vs  Independent Set
// URL: https://codeforces.com/gym/319427/problem/D
// Rating: 2000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, a[310000];
vector<int> ed;

void solve(){
    scanf("%d%d", &n, &m);
    ed.clear();
    for(int i=1; i<=3*n; i++) a[i]=0;
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        if(a[u] || a[v]) continue;
        ed.push_back(i);
        a[u]=1; a[v]=1;
    }
    if(ed.size()>=n){
        printf("Matching\n");
        for(int i=0; i<n; i++) printf("%d ", ed[i]);
        printf("\n");
    }
    else{
        printf("IndSet\n");
        int now=0;
        for(int i=1; i<=3*n; i++){
            if(a[i]) continue;
            printf("%d ", i);
            now++;
            if(now==n) break;
        }
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}