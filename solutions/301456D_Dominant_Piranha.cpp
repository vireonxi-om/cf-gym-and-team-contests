// Problem: Dominant Piranha
// URL: https://codeforces.com/gym/301456/problem/D
// Rating: 900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[310000];

void solve(void)
{
	memset(a,0,sizeof(a)); 
	int *max=a, num=-1;
	scanf("%d", &n);
	scanf("%d%d", &a[1], &a[2]);
	for(int i=3; i<=n; i++){
		scanf("%d", &a[i]);
		if ((a[i-1]>a[i-2]&&a[i-1]>=a[i])||(a[i-1]>=a[i-2]&&a[i-1]>a[i])){
			if(a[i-1]>*max) {
				max=&a[i-1];num=i-1;
			}
		}
	}
	if(a[n]>a[n-1] && a[n]>*max){
		num=n; max=&a[n];
	}
	if(a[1]>a[2] && a[1]>*max){
		num=1; max=&a[1];
	}
	printf("%d\n",num);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
