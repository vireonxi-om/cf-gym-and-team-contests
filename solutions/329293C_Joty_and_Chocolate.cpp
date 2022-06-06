// Problem: Joty and Chocolate
// URL: https://codeforces.com/gym/329293/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b, p, q;

ll gcd(ll x, ll y){
    return y==0? x: gcd(y, x%y);
}

int main(){
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &p, &q);
    if(p>q){ swap(p, q); swap(a, b);}
    ll lcm=a*b/gcd(a, b);
    int num1=n/a, num2=n/b, num3=n/lcm;
    ll ans=q*num2+p*(num1-num3);
    printf("%lld\n", ans);
    return 0;
}