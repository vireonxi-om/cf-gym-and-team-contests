// Problem: Shortest Path Query
// URL: https://codeforces.com/gym/103055/problem/D
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

const int N=210000;
const int M=1100000;
const LL mod=1e9+7;
const LL inf=1e18;
int n,m,q;
int check(int a,int b)
{
	if (a<b) swap(a,b);
	while (a>b) a>>=1;
	return a==b;
}
vector<PII> g[N],h[N];
int dep[N],f[N];
LL dp[N][20];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if (fx!=fy) f[fx]=fy;
}
priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> que;
int pp[N];
void work(int x)
{
	int d=dep[x];
	que.push(mp(0,x));
	vector<int> tmp;
	tmp.pb(x);
	while (!que.empty())
	{
		auto qq=que.top();
		int now=qq.se;
		que.pop();
		if (pp[now]) continue;
		pp[now]=1;
		for (auto p:g[now])
		{
			int y=p.fi,w=p.se;
			if (y>=x&&dp[y][d]>dp[now][d]+w) dp[y][d]=dp[now][d]+w,tmp.pb(y),que.push({dp[y][d],y});
		}
	}
	for (auto x:tmp)
		pp[x]=0;
}
int main()
{
	scanf("%d %d",&n,&m);
	repn(i,1,n) f[i]=i;
	repn(i,1,m)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
		//h[x].pb(mp(y,w));
		merge(x,y);
	}
	repn(i,1,n)
		rep(j,0,20)
			dp[i][j]=inf;
	repn(i,1,n)
		dep[i]=dep[i>>1]+1,dp[i][dep[i]]=0;
	repn(i,1,n)
		work(i);
	scanf("%d",&q);
	while (q--)
	{
		int x,y,tmp,d;
		scanf("%d %d",&x,&y);
		if (find(x)!=find(y))
		{
			printf("-1\n");
			continue;
		}
		LL ans=inf;
		tmp=x,d=dep[x];
		while (tmp)
		{
			if (check(x,tmp)&&check(y,tmp))
			{
				ans=min(ans,dp[x][d]+dp[y][d]);
			}
			d--;
			tmp>>=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}// maintenance note (3): small formatting cleanup on this file — 2026-08-24
