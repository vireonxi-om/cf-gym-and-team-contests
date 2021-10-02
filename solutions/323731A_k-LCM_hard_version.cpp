// Problem: k-LCM (hard version)
// URL: https://codeforces.com/gym/323731/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k;

void solve(){
    scanf("%d%d", &n, &k);
    int now=n;
    for(int i=1; i<=k-3; i++){ printf("1 "); now--;}
    if(now%4==0){
        printf("%d %d %d\n", now/4, now/4, now/2);
    }
    else if(now%2==0){
        now-=2;
        printf("2 %d %d\n", now/2, now/2);
    }
    else{
        printf("1 %d %d\n", now/2, now/2);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}