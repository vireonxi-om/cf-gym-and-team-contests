// Problem: Barrels
// URL: https://codeforces.com/gym/301456/problem/H
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int i, n, k; 
long long sum, a[210000];

void solve(void)
{
	memset(a, 0, sizeof(a)); sum=0;
	scanf("%d%d",&n, &k);
	for(i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1,a+1+n);
	for(i=0;i<=k;i++) sum+=a[n-i];
	printf("%lld\n",sum);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
