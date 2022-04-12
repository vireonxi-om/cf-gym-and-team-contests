// Problem: Hourly Coding Problem
// URL: https://codeforces.com/gym/103117/problem/G
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
const int M=11000000;
const LL mod=1e9+7;
const LL inf=1e18;
const int inff=1e9;
int T,n,k;
int a[N],p[N],ys[N],pos[N];
LL sum[N];
PII dp[N];
struct Fenwick
{
	PII v[N];
	void init(int n)
	{
		repn(i,1,n)
			v[i]=mp(inff,-inff);
	}
	PII merge(PII a,PII b)
	{
		return mp(min(a.fi,b.fi),max(a.se,b.se));
	}
	inline int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x,PII y)
	{
		for (int i=x;i<=n;i+=lowbit(i))
			v[i]=merge(v[i],y);
	}
	PII get(int x)
	{
		PII res=mp(inff,-inff);
		for (int i=x;i;i-=lowbit(i))
			res=merge(res,v[i]);
		return res;
	}
}v;
struct SegmentTree
{
	int v[M];
	void build(int k,int l,int r)
	{
		v[k]=-inff;
		if (l==r) return;
		int mid=(l+r)/2;
		build(LC,l,mid);
		build(RC,mid+1,r);
	}
	void update(int k)
	{
		v[k]=max(v[LC],v[RC]);
	}
	void add(int k,int l,int r,int a,int b)
	{
		if (l==r)
		{
			v[k]=b;
			return;
		}
		int mid=(l+r)/2;
		if (a<=mid) add(LC,l,mid,a,b);
		else add(RC,mid+1,r,a,b);
		update(k);
	}
	int ask(int k,int l,int r,int a,int b)
	{
		if (l>r) return n;
		if (l==a&&r==b) return v[k];
		int mid=(l+r)/2;
		if (b<=mid) return ask(LC,l,mid,a,b);
		else if (a>mid) return ask(RC,mid+1,r,a,b);
		else return max(ask(LC,l,mid,a,mid),ask(RC,mid+1,r,mid+1,b));
	}
}A;
int cmp(int x,int y)
{
	return sum[x]<sum[y];
}
int check(LL x)
{
	v.init(n);
	repn(i,1,n)
	{
		int y=p[i];
		pos[p[i]]=pos[p[i-1]];
		while (pos[y]<n&&sum[p[pos[y]+1]]<=sum[y]+x) pos[y]++;
	}
	dp[n]=mp(0,0);
	v.add(ys[n],dp[n]);
	per(i,1,n)
	{
		dp[i]=v.get(pos[i]);
		dp[i].fi++,dp[i].se++;
		v.add(ys[i],dp[i]);
	}
	return dp[1].fi<=k&&k<=dp[1].se;
}
vector<PII> f[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);
		n++;
		sum[1]=0;
		LL mn=inf,mx=-inf;
		repn(i,2,n)
		{
			scanf("%d",&a[i-1]),sum[i]=sum[i-1]+(LL)a[i-1];
			mn=min(mn,sum[i]);
			mx=max(mx,sum[i]);
		}
		repn(i,1,n) p[i]=i;
		sort(p+1,p+1+n,cmp);
		repn(i,1,n) ys[p[i]]=i;
	
		LL l=mn-abs(mx)-1,r=mx+abs(mn),ans;
		while (l<=r)
		{
			LL mid=(l+r)/2;
			if (check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		check(ans);
		A.build(1,1,n);
		repn(i,1,n)
		{
			if (dp[i].fi<=k&&dp[i].se>=k) A.add(1,1,n,ys[i],i);
			if (dp[i].fi-1>=0&&dp[i].fi-1<k) f[dp[i].fi-1].pb({i,0});
			if (dp[i].se>=0&&dp[i].se<k) f[dp[i].se].pb({i,1});
		}
		int now=1;
		while (k--)
		{
			for (auto p:f[k])
			{
				int pos=p.fi,op=p.se;
				if (op) A.add(1,1,n,ys[pos],pos);
				else A.add(1,1,n,ys[pos],-inff);
			}
			f[k].clear();
			int pre=A.ask(1,1,n,1,pos[now]);
			printf("%d",pre-now);
			if (k) printf(" ");
			else printf("\n");
			now=pre;
		}
	}
		
	return 0;
}