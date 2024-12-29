// Problem: Islands
// URL: https://codeforces.com/gym/101291/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, b[60][60], cnt=0;
char a[60][60];
vector<pair<int, int>> l;
queue<pair<int, int>> q;

void bfs(int x, int y){
    q.push(make_pair(x, y));
    b[x][y]=1;
    while(!q.empty()){
        int s=q.front().first, t=q.front().second;
        q.pop();
        for(int i=max(1, s-1); i<=min(n, s+1); i++){
            if(b[i][t]) continue;
            if(a[i][t]=='W') continue;
            q.push(make_pair(i, t));
            b[i][t]=1;
        }
        for(int i=max(1, t-1); i<=min(m, t+1); i++){
            if(b[s][i]) continue;
            if(a[s][i]=='W') continue;
            q.push(make_pair(s, i));
            b[s][i]=1;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%s", a[i]+1);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(a[i][j]=='L') l.push_back(make_pair(i, j));
    for(auto x:l){
        if(b[x.first][x.second]) continue;
        cnt++;
        bfs(x.first, x.second);
    }
    printf("%d\n", cnt);
    return 0;
}
