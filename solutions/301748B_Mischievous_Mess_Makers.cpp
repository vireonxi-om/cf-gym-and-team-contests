// Problem: Mischievous Mess Makers
// URL: https://codeforces.com/gym/301748/problem/B
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long result;

int main()
{
	scanf("%d%d", &n, &k);
	if(n==1) result=0;
	else if(k<(n+1)/2){
		result=(long long)(n-1)*k + (n-2*k)*k;
	}
	else
		for(int i=1; i<n; i++) result+=i;
	printf("%lld\n",result);
	return 0;
}
