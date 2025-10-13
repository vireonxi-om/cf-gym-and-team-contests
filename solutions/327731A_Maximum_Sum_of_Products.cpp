// Problem: Maximum Sum of Products
// URL: https://codeforces.com/gym/327731/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[5100], b[5100], now[5100];


int main(){
    scanf("%d", &n);
    ll sum=0;
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++){scanf("%lld", &b[i]); sum+=b[i]*a[i];}
    ll ans=sum;
    for(int pos=2; pos<n; pos++){
        ll m=0;
        int t=min(pos-1, n-pos);
        for(int i=1; i<=t; i++){
            now[i]=(a[pos-i]-a[pos+i])*(b[pos+i]-b[pos-i]);
            now[i]+=now[i-1];
            m=max(m, now[i]);
        }
        ans=max(ans, sum+m);
    }
    for(int pos=1; pos<n; pos++){
        ll m=0;
        int t=min(pos-1, n-pos-1);
        for(int i=0; i<=t; i++){
            now[i]=(a[pos-i]-a[pos+1+i])*(b[pos+1+i]-b[pos-i]);
            if(i) now[i]+=now[i-1];
            m=max(m, now[i]);
        }
        ans=max(ans, sum+m);
    }
    printf("%lld\n", ans);
    return 0;
}
