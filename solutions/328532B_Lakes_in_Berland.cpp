// Problem: Lakes in Berland
// URL: https://codeforces.com/gym/328532/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, num=1, now, yes[60][60], o[3000];
char s[60][60];
set<pair<int, int>> l[3000], cnt;

void dfs(int ux, int uy){
    yes[ux][uy]=num;
    l[num].insert(make_pair(ux, uy));
    now++;
    for(int i=max(1, ux-1); i<=min(n, ux+1); i++){
        if(s[i][uy]=='.' && yes[i][uy]==0) dfs(i, uy);
    }
    for(int i=max(1, uy-1); i<=min(m, uy+1); i++){
        if(s[ux][i]=='.' && yes[ux][i]==0) dfs(ux, i);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) scanf("%s", s[i]+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i][j]=='.' && yes[i][j]==0){
                now=0;
                dfs(i, j);
                cnt.insert(make_pair(now, num));
                num++;
            }
        }
    }
    num--;
    for(int i=1; i<=n; i++){
        o[yes[i][1]]=1; o[yes[i][m]]=1;
    }
    for(int j=1; j<=m; j++){
        o[yes[1][j]]=1; o[yes[n][j]]=1;
    }
    k=num-k;
    for(int i=1; i<=num; i++) if(o[i]) k--;
    int tot=0;
    while(k){
        int t=(*cnt.begin()).first, id=(*cnt.begin()).second;
        cnt.erase(cnt.begin());
        if(o[id]) continue;
        k--; tot+=t;
        for(auto x:l[id]) s[x.first][x.second]='*';
    }
    printf("%d\n", tot);
    for(int i=1; i<=n; i++) printf("%s\n", s[i]+1);
    return 0;
}