// Problem: K-skip Permutation
// URL: https://codeforces.com/gym/103117/problem/K
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
#define IO cin.sync_with_stdio(false);
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a;i<n;i++)
#define repn(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pern(i,a,n) for (int i=n;i>=a;i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N=1100000;
const int M=1100000;
const LL mod=1e9+7;

int n,k,cnt;
vector<int> f[N];
int main()
{
	scanf("%d %d",&n,&k);
	repn(i,1,n)
		f[i%k].pb(i);
	rep(i,0,k)
	{
		for (auto x:f[i])
		{
			printf("%d",x);
			cnt++;
			if (cnt==n) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}