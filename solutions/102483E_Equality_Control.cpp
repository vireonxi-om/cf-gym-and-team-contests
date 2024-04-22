// Problem: Equality Control
// URL: https://codeforces.com/gym/102483/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
set<int> S;
int a[2][M],cnt,T,cnta,cntb,Ta,Tb;
int pp[2][M];
struct node
{
	int l,r,op,time;
	friend bool operator < (node a,node b)
	{
		int lena=a.r-a.l+1;
		int lenb=b.r-b.l+1;
		if (lena!=lenb) return lena>lenb;
		return a.time>b.time;
	}
}na[2][M];
	
char s[1100000],nch;
int pos,num;
string op;
vector<int> tmp;
void getnext()
{
	nch=s[++pos];
}
bool isdig(char x)
{
	return x>='0'&&x<='9';
}
void getop()
{
	if (nch=='c')
	{
		for (int i=0;i<6;i++) getnext();
		op="concat";
	}
	else if (nch=='s')
	{
		getnext();
		if (nch=='o')
		{
			for (int i=0;i<5;i++) getnext();
			op="sorted";
		}
		else
		{
			for (int i=0;i<6;i++) getnext();
			op="shuffle";
		}
	}
	else if (nch=='(') getnext(),op="(";
	else if (nch==')') getnext(),op=")";
	else if (nch=='[') getnext(),op="[";
	else if (nch==']') getnext(),op="]";
	else if (nch==',') getnext(),op=",";
	else
	{
		num=0;
		while (isdig(nch)) num=num*10+(nch-'0'),getnext();
		op="num";
	}
}
void getexpr(int type)
{
	getop();
	if (op=="concat")
	{
		getop();
		getexpr(type);
		getop();
		getexpr(type);
		getop();
	}
	if (op=="sorted")
	{
		getop();
		int l=cnt+1;
		getexpr(type);
		int r=cnt;
		getop();
		na[type][++T]={l,r,0,T};
	}
	if (op=="shuffle")
	{
		getop();
		int l=cnt+1;
		getexpr(type);
		int r=cnt;
		getop();
		na[type][++T]={l,r,1,T};
	}
	if (op=="[")
	{
		getop();
		int flag=0;
		while (op!="]")
		{
			if (flag) getop();
			a[type][++cnt]=num;
			getop();
			flag=1;
		}
	}
}
vector<pair<int,int> > sh[2];
void finalize(int type,int cnt,int T)
{
	sort(na[type]+1,na[type]+T+1);
	for (int i=1;i<=T;i++)
	{
		int l=na[type][i].l,r=na[type][i].r,op=na[type][i].op;
		if (pp[type][l]) continue;
		sort(a[type]+l,a[type]+r+1);
		if (op==1)
		{
			set<int> S;
			S.clear();
			for (int j=l;j<=r;j++)
				S.insert(a[type][j]);
			if (S.size()>1) sh[type].pb(mp(l,r));
		}
		for (int j=l;j<=r;j++)
			pp[type][j]=1;
	}
	sort(sh[type].begin(),sh[type].end());
}
int check()
{
	if (cnta!=cntb) return 0;
	for (int i=1;i<=cnta;i++)
		if (a[0][i]!=a[1][i]) return 0;
	if (sh[0].size()!=sh[1].size()) return 0;
	for (int i=0;i<sh[0].size();i++)
		if (sh[0][i]!=sh[1][i]) return 0;
	return 1;
}
int main()
{
	scanf("%s",s);
	nch=s[0],pos=cnt=T=0;
	getexpr(0);
	cnta=cnt,Ta=T;
	scanf("%s",s);
	nch=s[0],pos=cnt=T=0;
	getexpr(1);
	cntb=cnt,Tb=T;
	finalize(0,cnta,Ta);
	finalize(1,cntb,Tb);
	if (check()) printf("equal\n");
	else printf("not equal\n");
	return 0;
}