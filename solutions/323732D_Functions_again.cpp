// Problem: Functions again
// URL: https://codeforces.com/gym/323732/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[110000], b[110000], dp[110000][2];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<n; i++) b[i]=abs(a[i+1]-a[i]);
    dp[1][0]=b[1];
    for(int i=2; i<n; i++){
        dp[i][0]=max((ll)0, dp[i-1][1])+b[i];
        dp[i][1]=dp[i-1][0]-b[i];
    }
    ll ans=0;
    for(int i=1; i<n; i++){
        ans=max(ans, dp[i][0]);
    }
    printf("%lld\n", ans);
    return 0;
}
