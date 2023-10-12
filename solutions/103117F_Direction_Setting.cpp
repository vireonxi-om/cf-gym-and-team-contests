// Problem: Direction Setting
// URL: https://codeforces.com/gym/103117/problem/F
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

//const int N=110000;
//const int M=1100000;

const int N=4100;
const int M=1100000;
const LL mod=1e9+7;
struct edge
{
	int x,y;
}b[M];
int T,n,m;
int a[N];
int e[M],f[M],w[M],pre[M],last[N];
int d[N],dd[N],pp[N],now[N];
int num=1,st,ed,maxflow,flag;
LL ans;
queue<int> q;
void insert(int x,int y,int z,int c)
{
	e[++num]=y,f[num]=z,w[num]=c,pre[num]=last[x],last[x]=num;
	e[++num]=x,f[num]=0,w[num]=-c,pre[num]=last[y],last[y]=num;
}
bool spfa()
{	
	for (int i=st;i<=ed;i++)
		d[i]=dd[i]=1e9,pp[i]=0;
	q.push(st);
	d[st]=dd[st]=0;pp[st]=1;
	while (!q.empty())
	{
		int x=q.front();
		for (int i=last[x];i;i=pre[i])
		{
			if (!f[i]) continue;
			int y=e[i];
			if (d[y]>d[x]+w[i]||d[y]==d[x]+w[i]&&dd[y]>dd[x]+1)
			{
				d[y]=d[x]+w[i];
				dd[y]=dd[x]+1;
				if (!pp[y]) pp[y]=1,q.push(y);
			}
		}
		pp[x]=0;
		q.pop();
	}
	if (d[ed]==1e9) return false;
	return true;
}
int dfs(int x,int incf)
{
    if(x==ed)return incf;
    int flow=0,ww;
    for (int i=now[x];i;i=pre[i])
        if(f[i]&&dd[e[i]]==dd[x]+1&&d[e[i]]==d[x]+w[i])
        {
			ww=dfs(e[i],min(incf-flow,f[i]));
            f[i]-=ww,f[i^1]+=ww;
            flow+=ww;
            ans+=(LL)ww*(LL)w[i];
            if (f[i]) now[x]=i;
			if(flow==incf) return incf;
        }
    if(!flow) dd[x]=-1;
    return flow;
}
void dinic()
{
	while(spfa()) 
	{
		for (int i=st;i<=ed;i++)
			now[i]=last[i];
		maxflow+=dfs(st,1e9);
	}
}
char s[N];
int main()
{
	IO;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		repn(i,1,n)
			cin>>a[i];
		repn(i,0,m+2*n+1)
			last[i]=0;
		num=1;
		ans=0;
		st=0,ed=m+2*n+1;
		repn(i,1,n)
		{
			insert(m+2*i-1,ed,a[i],0);
			insert(m+2*i,ed,1e9,1);
		}
		repn(i,1,m)
		{
			int x,y;
			cin>>x>>y;
			b[i]={x,y};
			insert(st,i,1,0);
			insert(i,m+2*x-1,1,0);
			insert(i,m+2*x,1,0);
			insert(i,m+2*y-1,1,0);
			insert(i,m+2*y,1,0);
		}
		dinic();
		printf("%lld\n",ans);
		repn(i,1,m)
		{
			int pos;
			for (int j=last[i];j;j=pre[j])
			{
				int y=e[j];
				if (y<m+1||y>m+2*n) continue;
				if (f[j]) continue;
				y=(y-m+1)/2;
				if (y==b[i].x) s[i]='1';
				else s[i]='0';
			}
		}
		s[m+1]=0;
		printf("%s\n",s+1);
	}
			
	return 0;
}