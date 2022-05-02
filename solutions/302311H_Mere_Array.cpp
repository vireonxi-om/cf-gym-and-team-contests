// Problem: Mere Array
// URL: https://codeforces.com/gym/302311/problem/H
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m, a[110000], b[110000];

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}

void solve()
{
	scanf("%d", &n); m=1000000000;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[i]=a[i];
		m=min(a[i], m);
	}
	sort(b+1,b+n+1);
	int can=1;
	for(int i=1; i<=n; i++){
		if(b[i]!=a[i]){
			if(gcd(m, a[i])!=m || gcd(m, b[i])!=m)
		    can=0;
		}
	}
	if(can) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
} 
