// Problem: Rock Paper Scissors
// URL: https://codeforces.com/gym/103117/problem/D
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

int T,br,bp,bs,dr,dp,ds;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		LL ans=0;
		scanf("%d %d %d",&br,&bp,&bs);
		scanf("%d %d %d",&dr,&dp,&ds);
		int d=min(br,dp);
		br-=d,dp-=d;
		ans+=(LL)d;
		d=min(bp,ds);
		bp-=d,ds-=d;
		ans+=(LL)d;
		d=min(bs,dr);
		bs-=d,dr-=d;
		ans+=(LL)d;
		d=min(br,dr);
		br-=d,dr-=d;
		d=min(bp,dp);
		bp-=d,dp-=d;
		d=min(bs,ds);
		bs-=d,ds-=d;
		d=min(br,ds);
		br-=d,ds-=d;
		ans-=(LL)d;
		d=min(bp,dr);
		bp-=d,dr-=d;
		ans-=(LL)d;
		d=min(bs,dp);
		bs-=d,dp-=d;
		ans-=(LL)d;
		printf("%lld\n",ans);
	}
	return 0;
}