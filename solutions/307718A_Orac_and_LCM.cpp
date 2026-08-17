// Problem: Orac and LCM
// URL: https://codeforces.com/gym/307718/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[110000], pre[110000], suf[110000];

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    pre[1]=a[1]; suf[n]=a[n];
    for(int i=2; i<=n; i++) pre[i]=gcd(pre[i-1], a[i]);
    for(int i=n-1; i>=1; i--) suf[i]=gcd(suf[i+1], a[i]);
    ll ans=suf[2];
    for(int i=1; i<n-1; i++) ans=ans*gcd(pre[i], suf[i+2])/gcd(gcd(pre[i], suf[i+2]), ans);
    ans=ans*pre[n-1]/gcd(ans, pre[n-1]);
    printf("%lld\n", ans);
    return 0;
}
