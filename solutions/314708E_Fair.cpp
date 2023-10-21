// Problem: Fair
// URL: https://codeforces.com/gym/314708/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, k, s, a[110000], d[110000][110], vis[110000];
vector<int> col[110], g[110000];

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        col[a[i]].push_back(i);
    }
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=k; i++){
        queue<int> q;
        for(int i=1; i<=n; i++) vis[i]=0;
        for(auto x:col[i]) {q.push(x); vis[x]=1;}
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(auto x:g[t]){
                if(vis[x]==0){
                    d[x][i]=d[t][i]+1;
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        int ans=0;
        sort(d[i]+1, d[i]+k+1);
        for(int j=1; j<=s; j++) ans+=d[i][j];
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}