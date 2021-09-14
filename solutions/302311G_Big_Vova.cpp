// Problem: Big Vova
// URL: https://codeforces.com/gym/302311/problem/G
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[1100], b[1100], c[1100], *p1;

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}

void solve()
{
	memset(c, 1, sizeof(c));
	int L=-1;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(L<a[i]){
			L=a[i]; p1=&a[i];
		}
	}
	b[1]=*p1; c[p1-a]=0;
	int m, maxi=b[1];
	for(int i=2; i<=n; i++){
		m=0;
		for(int j=1; j<=n; j++){
			if(c[j]!=0 && gcd(maxi, a[j])>m){
				m=gcd(maxi, a[j]);
			    p1=&a[j];
			}
		}
		maxi=m; b[i]=*p1; c[p1-a]=0;
	}
	for(int i=1; i<=n; i++) printf("%d ", b[i]);
	printf("\n");
	
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
} 

