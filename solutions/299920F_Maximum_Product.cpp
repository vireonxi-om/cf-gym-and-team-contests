// Problem: Maximum Product
// URL: https://codeforces.com/gym/299920/problem/F
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[110000], product, now;

void solve(void)
{
    memset(a,0,110000);
    product=-1e18;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1,a+n+1);
    for(int i=0;i<3;i++){
        now=1;
        for(int j=0;j<=2*i;j++) now*=a[n-j];
        for(int j=1;j<5-2*i;j++) now*=a[j];
        product= max(product,now);
    }
    printf("%lld\n", product);

}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

