// Problem: League of Legends
// URL: https://codeforces.com/gym/103055/problem/A
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

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;

int a1,a2,x;
int main()
{
	repn(i,1,5)
	{
		scanf("%d",&x);
		a1+=x-1;
	}
	repn(i,1,5)
	{
		scanf("%d",&x);
		a2+=x-1;
	}
	if (a1>=a2) printf("Blue\n");
	else printf("Red\n");
	return 0;
}