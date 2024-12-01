// Problem: Spicy Restaurant
// URL: https://codeforces.com/gym/103117/problem/L
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

int n,m,q,w[N];
vector<int> g[N];
int dis[N][110],pp[N],cp[N];
queue<int> que;
void work(int mx)
{
	repn(i,1,n)
		if (cp[i])
			que.push(i),pp[i]=1,dis[i][mx]=0;
	while (!que.empty())
	{
		int now=que.front();
		que.pop();
		for (auto y:g[now])
			if (!pp[y])
			{
				pp[y]=1;
				dis[y][mx]=dis[now][mx]+1;
				que.push(y);
			}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	repn(i,1,n)
		scanf("%d",&w[i]);
	repn(i,1,m)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].pb(y),g[y].pb(x);
	}
	memset(dis,-1,sizeof(dis));
	repn(i,1,100)
	{
		memset(pp,0,sizeof(pp));
		repn(j,1,n)
			if (w[j]<=i) cp[j]=1;
		work(i);
		repn(j,1,n)
		{
			if (dis[j][i-1]==-1);
			else if (dis[j][i]==-1) dis[j][i]=dis[j][i-1];
			else dis[j][i]=min(dis[j][i],dis[j][i-1]);
		}
	}
	while (q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",dis[x][y]);
	}
	return 0;
}