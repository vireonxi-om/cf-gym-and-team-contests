// Problem: Ternary Sequence
// URL: https://codeforces.com/gym/299920/problem/H
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int i, a[3], b[3];
void solve(void)
{
	
	for (i=0; i<3; i++) scanf("%d", &a[i]);
	for (i=0; i<3; i++) scanf("%d", &b[i]);
	if(a[1]<=b[0] || b[2]<=a[0])
	printf("%d\n", 2*min(b[1], a[2]));
	else
	printf("%d\n", 2*(a[2]+a[0]-b[2]));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

