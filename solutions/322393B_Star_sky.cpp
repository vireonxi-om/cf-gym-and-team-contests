// Problem: Star sky
// URL: https://codeforces.com/gym/322393/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, c, pre[110][110][15];


int main(){
    scanf("%d%d%d", &n, &q, &c);
    int x, y, s;
    int t, x1, y1, x2, y2;
    for(int t=1; t<=n; t++){
        scanf("%d%d%d", &x, &y, &s);
        for(int i=0; i<=c; i++){
            int now=s+i;
            now%=(c+1);
            pre[x][y][i]+=now;
        }
    }
    for(int k=0; k<=c; k++){
        for(int i=1; i<=100; i++){
            for(int j=1; j<=100; j++){
                pre[i][j][k]+=pre[i-1][j][k]+pre[i][j-1][k]-pre[i-1][j-1][k];
            }
        }
    }
    while(q--){
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int now=t%(c+1);
        int ans=pre[x2][y2][now]+pre[x1-1][y1-1][now]-pre[x1-1][y2][now]-pre[x2][y1-1][now];
        printf("%d\n", ans);
    }
    return 0;
}
