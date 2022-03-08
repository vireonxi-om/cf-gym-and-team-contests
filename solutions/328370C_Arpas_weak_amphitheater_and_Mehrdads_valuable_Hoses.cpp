// Problem: Arpa's weak amphitheater and Mehrdad's valuable Hoses
// URL: https://codeforces.com/gym/328370/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, maxw, m, w[1100], b[1100], yes[1100], dp[1100][1100];
vector<int> g[1100], id[1100];
int cnt=1;

void dfs(int u, int v){
    yes[u]=1;
    id[cnt].push_back(u);
    for(auto x:g[u]){
        if(x==v || yes[x]) continue;
        dfs(x, u);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &maxw);
    for(int i=1; i<=n; i++) scanf("%d", &w[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(yes[i]==0){ dfs(i, 0); cnt++;}
    }
    cnt--;
    for(int i=1; i<=cnt; i++){
        for(int j=0; j<=maxw; j++) dp[i][j]=dp[i-1][j];
        for(int j=0; j<=maxw; j++){
            int sumw=0, sumb=0;
            for(auto x: id[i]){
                sumw+=w[x]; sumb+=b[x];
                if(j+w[x]>maxw) continue;
                dp[i][j+w[x]]=max(dp[i][j+w[x]], dp[i-1][j]+b[x]);
            }
            if(j+sumw>maxw) continue;
            dp[i][j+sumw]=max(dp[i][j+sumw], dp[i-1][j]+sumb);
        }
    }
    int ans=0;
    for(int i=1; i<=maxw; i++) ans=max(ans, dp[cnt][i]);
    printf("%d\n", ans);
    return 0;
}
