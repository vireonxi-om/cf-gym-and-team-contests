// Problem: Negative Prefixes
// URL: https://codeforces.com/gym/302311/problem/E
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, len, a[110], l[110], ul[110];

void solve()
{
	len=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=1; i<=n; i++){
		scanf("%d", &l[i]);
		if(l[i]==0){
			len++;
			ul[len]=a[i];
		}
	}
	sort(ul+1, ul+len+1);
	for(int i=1,j=len; i<=n; i++){
		if(l[i]==0) a[i]=ul[j--];
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
}
