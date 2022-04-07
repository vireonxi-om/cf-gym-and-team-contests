// Problem: Hard problem
// URL: https://codeforces.com/gym/328644/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll c[110000], dp[110000][2];
vector<char> s[2][110000];
char a[110000];

bool yes(int i, int t1, int t2){
    int now=0;
    bool can=true;
    while(s[t1][i][now]!='\0' && s[t2][i-1][now]!='\0'){
        if(s[t1][i][now]<s[t2][i-1][now]){ can=false; break;}
        else if(s[t1][i][now]>s[t2][i-1][now]) break;
        now++;
    }
    if(s[t1][i][now]=='\0' && s[t2][i-1][now]!='\0') can=false;
    return can;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
    char ch;
    scanf("%c", &ch);
    for(int i=1; i<=n; i++){
        while(1){
            scanf("%c", &ch);
            if(ch=='\n') break;
            s[0][i].push_back(ch); s[1][i].push_back(ch);
        }
        reverse(s[1][i].begin(), s[1][i].end());
        s[0][i].push_back('\0'); s[1][i].push_back('\0');
        dp[i][0]=1e18; dp[i][1]=1e18;
    }
    dp[1][0]=0; dp[1][1]=c[1];
    for(int i=2; i<=n; i++){
        if(yes(i, 0, 0)) dp[i][0]=min(dp[i][0], dp[i-1][0]);
        if(yes(i, 0, 1)) dp[i][0]=min(dp[i][0], dp[i-1][1]);
        if(yes(i, 1, 0)) dp[i][1]=min(dp[i][1], dp[i-1][0]+c[i]);
        if(yes(i, 1, 1)) dp[i][1]=min(dp[i][1], dp[i-1][1]+c[i]);
    }
    /*
    for(int i=1; i<=n; i++){
        int now=0;
        while(s[0][i][now]!='\0') printf("%c", s[0][i][now++]);
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        int now=0;
        while(s[1][i][now]!='\0') printf("%c", s[1][i][now++]);
        printf("\n");
    } */
    ll ans=min(dp[n][0], dp[n][1]);
    if(ans<1e17) printf("%lld\n", ans);
    else printf("-1\n");
    return 0;
}
