// Problem: Boats Competition
// URL: https://codeforces.com/gym/299920/problem/I
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int i, n, k, s ,now, a[100];

void solve(void)
{
	memset(a, 0, 100*sizeof(int));
	scanf("%d",&n);
	for(int j=0; j<n; j++){
		scanf("%d",&i);
		a[i]++;
	}
	k=0;
	for(s=2; s<=2*n; s++){
		now=0;
		for(i=1; i<=n; i++){
			if(2*i<s)
			    now+=min(a[i], a[s-i]);
			else if(2*i==s)
				now+=a[i]/2;
		}
		k=max(k,now);
	}
	printf("%d\n", k);
	
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
