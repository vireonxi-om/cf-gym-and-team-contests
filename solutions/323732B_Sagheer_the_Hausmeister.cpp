// Problem: Sagheer, the Hausmeister
// URL: https://codeforces.com/gym/323732/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, zero[20], pos[20][2], cnt[20][2];
char s[20][110];


int main(){
    scanf("%d%d", &n, &m);
    for(int i=n; i>=1; i--){
        scanf("%s", &s[i]);
        for(int j=1; j<=m; j++) if(s[i][j]=='1'){ zero[i]=1; pos[i][0]=j; break;}
        for(int j=m; j>=1; j--) if(s[i][j]=='1'){ pos[i][1]=j; break;}
    }
    if(zero[1]){ cnt[1][0]=2*pos[1][1]; cnt[1][1]=m+1; }
    else{ cnt[1][0]=0; cnt[1][1]=0;}
    for(int i=2; i<n; i++){
        if(zero[i]){
            cnt[i][0]=min(2*pos[i][1]+cnt[i-1][0], cnt[i-1][1]+m+1);
            cnt[i][1]=min(cnt[i-1][0]+m+1, cnt[i-1][1]+2*(m+1-pos[i][0]));
        }
        else{
            cnt[i][0]=cnt[i-1][0];
            cnt[i][1]=cnt[i-1][1];
        }
        cnt[i][0]++; cnt[i][1]++;
    }
    int top=0, ans=0;
    for(int i=n; i>=1; i--) if(zero[i]){ top=i; break;}
    if(top==0) ans=0;
    else if(top==1) ans=pos[1][1];
    else{
        ans=min(cnt[top-1][0]+pos[top][1], cnt[top-1][1]+m+1-pos[top][0]);
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

