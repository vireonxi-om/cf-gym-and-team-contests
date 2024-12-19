// Problem: Riana and the Blind Date
// URL: https://codeforces.com/gym/102556/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, d[40];

int main(){
    scanf("%lld%lld", &a, &b);
    ll tot=b-a+1; tot%=104206969;
    ll u=b, l=a;
    while(u%4) u--;
    while(l%4) l++;
    ll four=(u-l)/4+1;
    u=b, l=a;
    while(u%100) u--;
    while(l%100) l++;
    ll hund=(u-l)/100+1;
    u=b, l=a;
    while(u%400) u--;
    while(l%400) l++;
    ll fh=(u-l)/400+1;
    ll leap=four-hund+fh; leap%=104206969;
    ll ans=((tot*542274/3)%104206969)+leap*229;
    ans%=104206969;
    printf("%lld\n", ans);
    return 0;
}

