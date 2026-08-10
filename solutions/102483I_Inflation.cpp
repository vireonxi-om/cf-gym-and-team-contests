// Problem: Inflation
// URL: https://codeforces.com/gym/102483/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;

const int N=210000;
const int M=1100000;
const LL mod=1e9+7;

int n,a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	double ans=1.0;
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>i) flag=1;
		ans=min((double)a[i]/(double)i,ans);
	}
	if (flag) printf("-1\n");
	else printf("%.10f\n",ans);
	return 0;
}