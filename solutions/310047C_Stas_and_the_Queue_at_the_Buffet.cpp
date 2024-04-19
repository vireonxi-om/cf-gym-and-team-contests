// Problem: Stas and the Queue at the Buffet
// URL: https://codeforces.com/gym/310047/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000], b[110000];

int main(){
    scanf("%d", &n);
    ll sum=0, sum2=0;
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        b[i] -= a[i];
        sum += a[i];
    }
    sort(b+1, b+n+1);
    for(int i=1; i<=n; i++){
        sum2+=(ll)b[i]*(n-i);
    }
    sum*=(n-1);
    sum+=sum2;
    printf("%lld\n", sum);
    return 0;
}

