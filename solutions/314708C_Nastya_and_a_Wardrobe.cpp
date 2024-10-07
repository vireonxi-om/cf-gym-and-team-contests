// Problem: Nastya and a Wardrobe
// URL: https://codeforces.com/gym/314708/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll M=1000000007;
ll x, k;

ll power(ll t){
    ll result=1, y=2;
    while(t){
        if(t%2){
            t--;
            result*=y;
            result%=M;
        }
        t/=2;
        y=(y*y)%M;
    }
    return result%M;
}

int main(){
    scanf("%lld%lld", &x, &k);
    if(x==0) {printf("0\n"); return 0;}
    ll num=power(k);
    x%=M;
    ll ans=x*num*2-num+1+M;
    ans%=M;
    printf("%lld\n", ans);
    return 0;
}
