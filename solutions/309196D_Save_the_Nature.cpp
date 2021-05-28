// Problem: Save the Nature
// URL: https://codeforces.com/gym/309196/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p[210000], x, y;
ll k, a, b, suf[210000];

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {scanf("%d", &p[i]); p[i]/=100;}
    sort(p+1, p+n+1);
    suf[n+1]=0;
    for(int i=0; i<n; i++) suf[n-i]=p[n-i]+suf[n-i+1];
    scanf("%d%lld%d%lld%lld", &x, &a, &y, &b, &k);
    if(x<y){ swap(x, y); swap(a, b);}
    int result=-1;
    ll sum=0, lcm=a*b/gcd(a, b);
    for(int i=1; i<=n; i++){
        sum=0;
        int numa=i/a, numb=i/b, num=i/lcm;
        sum+=(suf[n-num+1]-suf[n+1])*(x+y);
        sum+=(suf[n-numa+1]-suf[n-num+1])*x;
        sum+=(suf[n-numa-numb+num+1]-suf[n-numa+1])*y;
        if(sum>=k){ result=i; break;}
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
