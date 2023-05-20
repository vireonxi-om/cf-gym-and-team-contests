// Problem: Boring Apartments
// URL: https://codeforces.com/gym/301456/problem/F
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, i, j;

void solve(void)
{
	scanf("%d", &n); i=n%10;
	if(n%10==n) j=1;
	else if(n%100==n) j=3;
	else if(n%1000==n) j=6;
	else j=10;
	printf("%d\n", 10*(i-1)+j);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
