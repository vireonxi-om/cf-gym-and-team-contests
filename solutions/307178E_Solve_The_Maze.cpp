// Problem: Solve The Maze
// URL: https://codeforces.com/gym/307178/problem/E
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[60][60];

void mark(int i, int j){
    if(i<=n && i>=1 && j<=m && j>=1){
        if(a[i][j]==0){
            a[i][j]=2;
            mark(i+1, j); mark(i-1, j);
            mark(i, j+1); mark(i, j-1);
        }
    }
}

void solve(){
    vector<pair<int, int>> good;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) a[i][j]=0;
    }
    for(int i=1; i<=n; i++){
        getchar();
        for(int j=1; j<=m; j++){
            char ch;
            scanf("%c", &ch);
            if(ch=='#') a[i][j]=1;
            else if(ch=='B'){
                a[i][j]=1; a[i+1][j]=1; a[i-1][j]=1;
                a[i][j+1]=1; a[i][j-1]=1;
            }
            else if(ch=='G') good.push_back(make_pair(i, j));
        }
    }
    mark(n, m);
    bool can=true;
    for(auto [x, y]:good){
        if(a[x][y]!=2) can=false;
    }
    if(can) printf("Yes\n");
    else printf("No\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

