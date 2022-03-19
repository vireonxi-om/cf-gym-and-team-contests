// Problem: Districts Connection
// URL: https://codeforces.com/gym/301456/problem/C
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[5100], b[5100];

void solve(void)
{
	memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	int can=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[i]=1;
		if (i>1 && a[i]!=a[i-1]) can=1;
		}
	if (can==0)
	printf("NO\n");
	else{
		printf("YES\n");
		int count=0, now=1, next;
		b[1]=0;
		while (count<n-1){
			for(j=1; j<=n; j++){
				if(a[now]!=a[j] && b[j]!=0){
					printf("%d %d\n", now, j);
					count++; next=j; b[j]=0;
				}
			}
			now=next;
		}
	}
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
