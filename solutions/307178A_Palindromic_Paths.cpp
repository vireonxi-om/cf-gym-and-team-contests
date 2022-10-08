// Problem: Palindromic Paths
// URL: https://codeforces.com/gym/307178/problem/A
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[40][40];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) scanf("%d", &a[i][j]);
    }
    int result=0;
    for(int k=0; k<(n+m-1)/2; k++){
        int cnt=0, cnt1=0;
        for(int i=1; i<=n; i++){
            if(2+k-i>0 && 2+k-i<=m){
                cnt++;
                if(a[i][2+k-i]==1) cnt1++;
            }
            if(n+m-k-i>0 && n+m-k-i<=m){
                cnt++;
                if(a[i][n+m-k-i]==1) cnt1++;
            }
        }
        result+=min(cnt-cnt1, cnt1);
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
