// Problem: Marketing Scheme
// URL: https://codeforces.com/gym/301456/problem/J
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long L, H, a; 

void solve(void)
{
	scanf("%lld%lld", &L, &H);
	
	for(a=2*(H-L)-2;;a++){
		if(a/2>H-L)
		break;
	}
	if(a/2>L) printf("NO\n");
	else printf("YES\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
