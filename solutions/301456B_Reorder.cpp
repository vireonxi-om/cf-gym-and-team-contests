// Problem: Reorder
// URL: https://codeforces.com/gym/301456/problem/B
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int m, n, result, a;

void solve(void)
{
	result=0;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &a);
		result+=a;
	} 
	if(m==result)
	printf("YES\n");
	else
	printf("NO\n");
	
	
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
