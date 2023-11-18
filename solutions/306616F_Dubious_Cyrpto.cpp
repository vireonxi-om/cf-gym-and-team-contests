// Problem: Dubious Cyrpto
// URL: https://codeforces.com/gym/306616/problem/F
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, r, n;
ll m, a, b, c;

ll maxl(ll a, ll b){
    return (a>b)?a:b;
}

void solve(){
    scanf("%d%d%lld", &l, &r, &m);
    ll u=m+r-l, d=maxl(1, m+l-r), bc;
    ll t=u-d;
    for(int i=l; i<=r; i++){
        if(u%i<=t){
            a=i;
            bc=m-u+u%i;
            break;
        }
    }
    if(bc>=0){
        c=l;
        b=c+bc;
    }
    else{
        b=l;
        c=b-bc;
    }
    printf("%lld %lld %lld\n", a, b, c);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

