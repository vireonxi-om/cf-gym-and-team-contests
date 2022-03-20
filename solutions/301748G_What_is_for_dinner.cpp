// Problem: What is for dinner?
// URL: https://codeforces.com/gym/301748/problem/G
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m, k, t[1100];

int main()
{
	int row, tooth;
	long long sum=0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++) t[i]=1100000;
	for(int i=1; i<=n; i++){
		scanf("%d%d", &row, &tooth);
		if (t[row]>tooth) t[row]=tooth;
	}
	for(int i=1;i<=m;i++) sum+=t[i];
	if(k<sum) printf("%d",k);
	else printf("%lld",sum);
	return 0;
}
