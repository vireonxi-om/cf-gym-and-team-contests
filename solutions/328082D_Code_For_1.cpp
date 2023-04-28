// Problem: Code For 1
// URL: https://codeforces.com/gym/328082/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[60];
ll n, l, r, val[60];

ll power(ll a, ll b){
    if(b==0) return 1;
    ll temp=power(a, b/2);
    temp=temp*temp;
    if(b%2) temp*=a;
    return temp;
}

ll func(int pos, ll s, ll t, ll x, ll y){
    if(x==s && y==t) return val[pos];
    ll mid=(s+t)/2;
    if(mid<x) return func(pos+1, mid+1, t, x, y);
    else if(mid>y) return func(pos+1, s, mid-1, x, y);
    else return func(pos+1, s, mid-1, x, mid-1)+func(pos+1, mid+1, t, mid+1, y)+p[pos];
}

int main(){
    scanf("%lld%lld%lld", &n, &l, &r);
    ll num=n; int pos=0, cnt=0;
    val[0]=n;
    while(num){
        p[pos++]=num%2;
        val[pos]=(num-num%2)/2;
        cnt++;
        num/=2;
    }
    ll tot=power(2, cnt)-1;
    ll ans;
    if(n) ans=func(0, 1, tot, l, r);
    else ans=0;
    printf("%lld\n", ans);
    return 0;
}
