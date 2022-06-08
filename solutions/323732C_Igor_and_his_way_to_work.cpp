// Problem: Igor and his way to work
// URL: https://codeforces.com/gym/323732/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char s[1100][1100];

bool check(int x1, int y1, int x2, int y2){
    bool can=true, yes=false;
    if(x1==x2){
        can=true;
        for(int j=min(y1, y2); j<=max(y1, y2); j++) if(s[x1][j]=='*') can=false;
        if(can) yes=true;
    }
    if(y1==y2){
        can=true;
        for(int i=min(x1, x2); i<=max(x1, x2); i++) if(s[i][y1]=='*') can=false;
        if(can) yes=true;
    }
    return yes;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%s", &s[i]);

    int sx, sy, su, sd, sl, sr, tx, ty, tu, td, tl, tr;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]=='S') { sx=i; sy=j;}
            if(s[i][j]=='T') { tx=i; ty=j;}
        }
    }

    int i, j;
    for(i=sx; i>=0; i--) if(s[i][sy]=='*') break;
    i++; su=i;
    for(i=sx; i<n; i++) if(s[i][sy]=='*') break;
    i--; sd=i;
    for(i=tx; i>=0; i--) if(s[i][ty]=='*') break;
    i++; tu=i;
    for(i=tx; i<n; i++) if(s[i][ty]=='*') break;
    i--; td=i;
    for(j=sy; j>=0; j--) if(s[sx][j]=='*') break;
    j++; sl=j;
    for(j=sy; j<m; j++) if(s[sx][j]=='*') break;
    j--; sr=j;
    for(j=ty; j>=0; j--) if(s[tx][j]=='*') break;
    j++; tl=j;
    for(j=ty; j<m; j++) if(s[tx][j]=='*') break;
    j--; tr=j;

    bool yes=false;
    int up=max(su, tu), down=min(sd, td), left=max(sl, tl), right=min(sr, tr);
    for(int i=up; i<=down; i++){
        if(check(i, sy, i, ty)) yes=true;
    }
    for(int j=left; j<=right; j++){
        if(check(sx, j, tx, j)) yes=true;
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}

