// Problem: Game Design
// URL: https://codeforces.com/gym/102483/problem/G
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

set<pair<int,int> > S;
set<pair<int,int> >::iterator it;
char s[N];
int n,x,y,ex,ey;
vector<pair<int,int> > ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if (n>=3)
	{
		int flag=0;
		if (s[n]=='R'&&s[n-1]=='L'&&s[n-2]=='R') flag=1;
		if (s[n]=='L'&&s[n-1]=='R'&&s[n-2]=='L') flag=1;
		if (s[n]=='U'&&s[n-1]=='D'&&s[n-2]=='U') flag=1;
		if (s[n]=='D'&&s[n-1]=='U'&&s[n-2]=='D') flag=1;
		if (flag)
		{
			printf("impossible\n");
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='D')
		{
			S.insert(mp(x,-2*(i+1)));
			S.insert(mp(x,2*(i+1)));
			while (!S.count(mp(x,y-1))) y--;
			ex=x,ey=y-1;
		}
		else if (s[i]=='U')
		{
			S.insert(mp(x,-2*(i+1)));
			S.insert(mp(x,2*(i+1)));
			while (!S.count(mp(x,y+1))) y++;
			ex=x,ey=y+1;
		}
		else if (s[i]=='L')
		{
			S.insert(mp(-2*(i+1),y));
			S.insert(mp(2*(i+1),y));
			while (!S.count(mp(x-1,y))) x--;
			ex=x-1,ey=y;
		}
		else
		{
			S.insert(mp(-2*(i+1),y));
			S.insert(mp(2*(i+1),y));
			while (!S.count(mp(x+1,y))) x++;
			ex=x+1,ey=y;
		}
	}
	S.erase(mp(ex,ey));
	for (it=S.begin();it!=S.end();it++)
		ans.pb(*it);
	printf("%d %d\n",-ex,-ey);
	printf("%d\n",ans.size());
	for (auto p:ans)
	{
		printf("%d %d\n",p.fi-ex,p.se-ey);
	}
	return 0;
}