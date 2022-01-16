// Problem: Really Big Numbers
// URL: https://codeforces.com/gym/323731/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll n, s;

ll func(ll a){
    ll result=0;
    while(a){
        result+=a%10;
        a/=10;
    }
    return result;
}

int main(){
    scanf("%lld%lld", &n, &s);
    ll r=n, l=s;
    ll ans=-1;
    while(l<r){
        ll mid=(l+r)/2;
        if(mid-func(mid)>=s){
            ans=mid;
            r=mid;
        }
        else l=mid+1;
    }
    if(l-func(l)>=s) ans=l;
    if(ans==-1) ans=0;
    else ans=n-ans+1;
    printf("%lld\n", ans);
    return 0;
}