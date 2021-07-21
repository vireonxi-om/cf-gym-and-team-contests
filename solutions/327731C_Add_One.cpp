// Problem: Add One
// URL: https://codeforces.com/gym/327731/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll dp[210000];

void solve(){
    scanf("%d%d", &n, &m);
    ll ans=0;
    while(n){
        int num=n%10;
        n/=10;
        ans+=dp[m+num];
        ans%=1000000007;
    }
    printf("%lld\n", ans);
}

int main(){
    for(int i=0; i<10; i++) dp[i]=1;
    for(int i=10; i<210000; i++){ dp[i]=dp[i-9]+dp[i-10]; dp[i]%=1000000007;}
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
