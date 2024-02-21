// Problem: Restore Atlantis
// URL: https://codeforces.com/gym/103055/problem/B
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

const int N=4100;
const int M=210000;
const int MM=5100000;
const LL mod=1e9+7;

int n,q;
priority_queue<int> s1[N];
priority_queue<int,vector<int>,greater<int> > s2[N];
struct rect
{
	int ax,bx,ay,by;
	void read()
	{
		scanf("%d %d %d %d",&ax,&ay,&bx,&by);
	}
}rec[M];
struct event
{
	int l,r,op,idx,y;
	friend bool operator < (event &a,event &b)
	{
		if (a.y!=b.y) return a.y<b.y;
		return a.op<b.op;
	}
}a[M];

struct event2
{
	int x,y,op,idx;
	friend bool operator < (event2 &a,event2 &b)
	{
		if (a.y!=b.y) return a.y<b.y;
		return a.op<b.op;
	}
}b[MM];
int m,nn,pp[M];
PII idx[MM];
void add(int k,int l,int r,int a,int b,int c)
{
	if (l==a&&r==b) {s1[k].push(c),s2[k].push(c);return;}
	int mid=(l+r)/2;
	if (b<=mid) add(LC,l,mid,a,b,c);
	else if (a>mid) add(RC,mid+1,r,a,b,c);
	else add(LC,l,mid,a,mid,c),add(RC,mid+1,r,mid+1,b,c);
}
void dfs(int k,int l,int r,int a,int b)
{
	while (!s1[k].empty()&&!pp[s1[k].top()]) s1[k].pop();
	while (!s2[k].empty()&&!pp[s2[k].top()]) s2[k].pop();
	if (!s1[k].empty()) b=max(b,s1[k].top());
	if (!s2[k].empty()) a=min(a,s2[k].top());
	if (l==r)
	{
		if (a<=b) idx[++nn]=mp(a,b);
		return;
	}
	int mid=(l+r)/2;
	dfs(LC,l,mid,a,b);
	dfs(RC,mid+1,r,a,b);
}
int ans[M],v[M];
int inline lowbit(int x)
{
	return x&-x;
}
void add(int x)
{
	for (int i=x;i<=n;i+=lowbit(i))
		v[i]++;
}
int get(int x)
{
	int res=0;
	for (int i=x;i;i-=lowbit(i))
		res+=v[i];
	return res;
}
int main()
{
	scanf("%d %d",&n,&q);
	repn(i,1,n)
	{
		rec[i].read();
		a[++m]=(event){rec[i].ax+1,rec[i].bx,0,i,rec[i].ay+1};
		a[++m]=(event){rec[i].ax+1,rec[i].bx,2,i,rec[i].by};
	}
	repn(i,1,2000)
		a[++m]=(event){0,0,1,0,i};
	sort(a+1,a+1+m);
	repn(i,1,m)
	{
		if (a[i].op==0)
		{
			int l=a[i].l,r=a[i].r;
			pp[a[i].idx]=1;
			add(1,1,2000,l,r,a[i].idx);
		}
		else if (a[i].op==1) dfs(1,1,2000,1e9,0);
		else pp[a[i].idx]=0;
	}
	m=0;
	repn(i,1,nn)
		b[++m]=(event2){n+1-idx[i].fi,idx[i].se,0,0};
	repn(i,1,q)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		b[++m]=(event2){n+1-l,r,1,i};
	}
	sort(b+1,b+1+m);
	repn(i,1,m)
		if (b[i].op==0) add(b[i].x);
		else ans[b[i].idx]=nn-get(b[i].x);
	repn(i,1,q) printf("%d\n",ans[i]);
	return 0;
}