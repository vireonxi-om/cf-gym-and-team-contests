// Problem: Yet Another Bookshelf
// URL: https://codeforces.com/gym/301456/problem/E
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[60];

void solve(void)
{
	memset(a, 0, sizeof(a));
	int count=0;
	scanf("%d",&n); 
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		if (a[i]==0) count++;
	}
	for(int i=0; ; i++){
		if(a[i]==1) break;
		else count--;
	}
	for(int i=n-1; ; i--){
		if(a[i]==1) break;
		else count--;
	}
	printf("%d\n", count);
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
