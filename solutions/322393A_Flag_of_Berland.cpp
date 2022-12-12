// Problem: Flag of Berland
// URL: https://codeforces.com/gym/322393/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m;
char s[110][110];


int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%s", s[i]+1);
    }
    bool v=true, h=true;
    for(int j=1; j<=m; j++){
        for(int i=1; i<=n; i++){
            if(s[i][j]!=s[1][j]) v=false;
        }
    }
    if(v){
        int t=1;
        while(s[1][t+1]==s[1][1]) t++;
        //printf("v: %d\n", t);
        if(t*3!=m) v=false;
        if(v && s[1][1]==s[1][t+1]) v=false;
        if(v && s[1][1]==s[1][2*t+1]) v=false;
        if(v && s[1][t+1]==s[1][2*t+1]) v=false;
        if(v) for(int j=t+1; j<=2*t; j++){
                if(s[1][j]!=s[1][t+1]) v=false;
            }
        if(v) for(int j=2*t+1; j<=m; j++){
                if(s[1][j]!=s[1][t*2+1]) v=false;
            }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i][j]!=s[i][1]) h=false;
        }
    }
    if(h){
        int t=1;
        while(s[t+1][1]==s[1][1]) t++;
        //printf("h: %d\n", t);
        if(t*3!=n) h=false;
        if(h && s[1][1]==s[t+1][1]) h=false;
        if(h && s[1][1]==s[2*t+1][1]) h=false;
        if(h && s[t+1][1]==s[2*t+1][1]) h=false;
        if(h) for(int j=t+1; j<=2*t; j++){
                if(s[j][1]!=s[t+1][1]) h=false;
            }
        if(h) for(int j=2*t+1; j<=n; j++){
                if(s[j][1]!=s[t*2+1][1]) h=false;
            }
    }
    if(v||h) printf("YES\n");
    else printf("NO\n");
    return 0;
}
