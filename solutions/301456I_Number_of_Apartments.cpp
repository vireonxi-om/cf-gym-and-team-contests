// Problem: Number of Apartments
// URL: https://codeforces.com/gym/301456/problem/I
// Rating: 900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n; 

void solve(void)
{
	scanf("%d", &n);
	if(n%5==0) printf("%d %d %d\n", 0, n/5, 0);
	else if((n%5==1)&& n>5) printf("%d %d %d\n", 2, (n-6)/5, 0);
	else if((n%5==2)&& n>5) printf("%d %d %d\n", 0, (n-7)/5, 1);
	else if(n%5==3) printf("%d %d %d\n", 1, (n-3)/5, 0);
	else if((n%5==4)&& n>5) printf("%d %d %d\n", 3, (n-9)/5, 0);
	else printf("%d\n", -1);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
