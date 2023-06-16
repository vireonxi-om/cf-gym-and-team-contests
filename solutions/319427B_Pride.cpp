// Problem: Pride
// URL: https://codeforces.com/gym/319427/problem/B
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[2100];

int gcd(int a, int b){
    return b==0? a: gcd(b, a%b);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    bool can=false;
    int len=110000;
    int cnt=0, ans;
    for(int i=1; i<=n; i++){
        if(a[i]==1) cnt++;
    }
    if(cnt){
        can=true;
        ans=n-cnt;
    }
    else{
        for(int i=1; i<=n-1; i++){
            int now=a[i];
            int t=i+1;
            while(t<=n){
                now=gcd(now, a[t]);
                if(now==1){
                    can=true;
                    len=min(len, t-i-1);
                    break;
                }
                t++;
            }
        }
        ans=n+len;
    }
    if(!can) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
