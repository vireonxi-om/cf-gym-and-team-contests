// Problem: Gravity
// URL: https://codeforces.com/gym/101291/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char a[60][60];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%s", a[i]+1);
    for(int j=1; j<=m; j++){
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(a[i][j]=='o'){ cnt++; a[i][j]='.';}
            if(i==n || i<n && a[i+1][j]=='#'){
                for(int t=i; t>i-cnt; t--) a[t][j]='o';
                cnt=0;
                i++;
            }
        }
    }
    for(int i=1; i<=n; i++) printf("%s\n", a[i]+1);
    return 0;
}
