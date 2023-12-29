// Problem: Circuit Board Design
// URL: https://codeforces.com/gym/102483/problem/C
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

const int N=410000;
const int M=1100000;
const LL mod=1e9+7;

int n;
int sz[N];
vector<int> g[N];
void dfs(int x,int fa)
{
	sz[x]=1;
	for (auto y:g[x])
	{
		if (y!=fa) dfs(y,x),sz[x]+=sz[y];
	}
}
const double pi=acos(-1.0);
double ansx[N],ansy[N];
void dfs2(int x,int fa,double xx,double yy,double st,double mx)
{
	ansx[x]=xx,ansy[x]=yy;
	if (mx>pi) mx=pi;
	double w=mx/(double)sz[x];
	double num=0;
	for (auto y:g[x])
	{
		if (y!=fa)
		{
			num+=sz[y]/2.0;
			double nx=xx+cos(st+num*w-mx/2),ny=yy+sin(st+num*w-mx/2);
			dfs2(y,x,nx,ny,st+num*w-mx/2,sz[y]*w);
			num+=sz[y]/2.0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	sz[1]--;
	dfs2(1,0,0,0,0,2*pi);
	for (int i=1;i<=n;i++)
		printf("%.10f %.10f\n",ansx[i],ansy[i]);
	return 0;
}