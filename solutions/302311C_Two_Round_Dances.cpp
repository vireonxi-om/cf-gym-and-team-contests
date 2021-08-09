// Problem: Two Round Dances
// URL: https://codeforces.com/gym/302311/problem/C
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long n, result=1;
int main()
{
	scanf("%lld", &n);
	for(int i=1; i<n; i++) result*=i;
	result/=(n/2);
	printf("%lld", result);
	return 0;
}
