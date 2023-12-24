// Problem: New Year and Permutation
// URL: https://codeforces.com/gym/309004/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, fac[260000];
int main()
{
    scanf("%lld%lld", &n, &m);
    fac[0]=1;
    for(int i=1;i<=n;++i) {fac[i]=fac[i-1]*i; fac[i]%=m;}
    ll ans=0;
    for(int i=1;i<=n;++i) {
        ans += ((fac[i] * fac[n - i]) % m) * ((n - i + 1) * (n - i + 1) % m);
        ans %= m;
    }
    printf("%lld\n", ans%m);
    return 0;
}
