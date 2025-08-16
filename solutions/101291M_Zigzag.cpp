// Problem: Zigzag
// URL: https://codeforces.com/gym/101291/problem/M
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[60], dp[60][60][2];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=0; i<=n; i++) for(int j=1; j<=n; j++){ dp[i][j][0]=0; dp[i][j][1]=100;}
    for(int i=0; i<=n; i++){ dp[i][0][0]=100; dp[i][0][1]=0;}
    for(int i=1; i<=n; i++){
        for(int len=1; len<=n; len++){
            if(dp[i-1][len-1][0]>a[i]){
                dp[i][len][1]=min(dp[i][len][1], a[i]);
            }
            if(dp[i-1][len-1][1]<a[i]){
                dp[i][len][0]=max(dp[i][len][0], a[i]);
            }
            dp[i][len][0]=max(dp[i-1][len][0], dp[i][len][0]);
            dp[i][len][1]=min(dp[i-1][len][1], dp[i][len][1]);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(dp[n][i][0]<100 && dp[n][i][0]>0){
            ans=max(ans, i);
        }
        if(dp[n][i][1]<100 && dp[n][i][1]>0){
            ans=max(ans, i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
