// Problem: Brexit Negotiations
// URL: https://codeforces.com/gym/102483/problem/B
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
int a[N],du[N];
vector<int> g[N];
priority_queue<pair<int,int> > q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int m;
		scanf("%d",&m);
		for (int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			g[i].pb(x);
			du[x]++;
		}
	}
	for (int i=1;i<=n;i++)
		if (du[i]==0) q.push(mp(-a[i],i));
	int ans=0,cnt=0;
	for (int i=n-1;i>=0;i--)
	{
		pair<int,int> p=q.top();
		q.pop();
		ans=max(ans,-p.fi+i);
		int now=p.se;
		for (auto y:g[now])
		{
			du[y]--;
			if (du[y]==0)
			{
				q.push(mp(-a[y],y));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}