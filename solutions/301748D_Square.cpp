// Problem: Square
// URL: https://codeforces.com/gym/301748/problem/D
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long n, k;

void solve()
{
	scanf("%lld", &n);
	if(((n+1)%4)==0) k=n+1;
	else if(((n+1)%2)==0) k=2*n+1;
	else k=4*n+1;
	printf("%lld\n", k);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(;t>0;t--) solve();
	return 0;
}
