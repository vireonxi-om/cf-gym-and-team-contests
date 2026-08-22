// Problem: Game On Leaves
// URL: https://codeforces.com/gym/307178/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, ck[1100];

void solve(){
    scanf("%d%d", &n, &x);
    int cnt=0;
    for(int i=1; i<=n; i++) ck[i]=0;
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a==x) ck[b]=1;
        if(b==x) ck[a]=1;
    }
    for(int i=1; i<=n; i++) if(ck[i]==1) cnt++;
    if(cnt==0 || cnt==1) printf("Ayush\n");
    else if((n-2)%2==1) printf("Ashish\n");
    else printf("Ayush\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
// maintenance note (2): small formatting cleanup on this file — 2026-08-22
