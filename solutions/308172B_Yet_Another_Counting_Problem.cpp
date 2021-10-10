// Problem: Yet Another Counting Problem
// URL: https://codeforces.com/gym/308172/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, l, r;
int q;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

void solve(){
    scanf("%lld%lld%d", &a, &b, &q);
    if(a<b) swap(a, b);
    ll num=a*b/gcd(a, b);
    for(int i=1; i<=q; i++){
        scanf("%lld %lld", &l, &r);
        ll result=0;
        ll x=l-l%num, y=r-r%num;
        if(x<y){
            ll t=(y-x-num)/num;
            result+=a*t;
            result+=min(a, r-y+1);
            result+=max(a-l%num, (ll)0);
        }
        if(x==y){
            if(a>r%num) result=r-l+1;
            else if(a>l%num) result=a-l%num;
        }
        result=r-l+1-result;
        printf("%lld \n", result);
    }
    printf("\n");
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
