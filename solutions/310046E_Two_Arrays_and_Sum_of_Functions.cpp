// Problem: Two Arrays and Sum of Functions
// URL: https://codeforces.com/gym/310046/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll a[210000], b[210000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] *= (ll)i * (n - i + 1);
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        result +=((a[i] % 998244353) * (b[n - i + 1] % 998244353))%998244353;
        result %= 998244353;
    }
    printf("%lld\n", result);
}