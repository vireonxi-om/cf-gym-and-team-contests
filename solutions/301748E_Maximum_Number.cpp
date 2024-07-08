// Problem: Maximum Number
// URL: https://codeforces.com/gym/301748/problem/E
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[51000];

int main()
{
	scanf("%d", &n);
	int k=n/2;
	for(int i=1; i<=k; i++) a[i]=1;
	if(n%2==1) a[1]=7;
	for(int i=1; i<=k; i++) printf("%d",a[i]);
	printf("\n");
	return 0;
}
