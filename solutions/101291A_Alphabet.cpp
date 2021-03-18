// Problem: Alphabet
// URL: https://codeforces.com/gym/101291/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[60][30];
char s[60];

int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    for(int i=1; i<=n; i++) for(int j=1; j<=26; j++) dp[i][j]=2e9;
    for(int i=1; i<=26; i++) dp[0][i]=i;
    for(int i=1; i<=n; i++){
        int now=s[i]-'a'+1;
        dp[i][now]=dp[i-1][now-1];
        for(int j=1; j<=26; j++){
            dp[i][j]=min(min(dp[i][j], dp[i-1][j]), min(dp[i-1][j-1], dp[i][j-1])+1);
        }
    }
    printf("%d\n", dp[n][26]);
    return 0;
}
