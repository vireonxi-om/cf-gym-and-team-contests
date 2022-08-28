// Problem: Ants
// URL: https://codeforces.com/gym/103117/problem/C
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
const int M=1100000;
const LL mod=1e9+7;
const LL inf=3e18;
const LL L=1e9+1;
int n,a,b,na,nb;
int c[N],d[N];
int nc[N],nd[N];
LL ans;
int t[N];
LL check1()
{
	LL res=0;
	repn(i,1,n)
	{
		if (d[i]==0) t[i]=c[i];
		else t[i]=L-c[i]+L;
	}
	sort(t+1,t+1+n);
	LL times;
	if (a%n==0) times=(LL)(a-1)/n*2*L+t[n];
	else times=(LL)a/n*2*L+t[a%n];
	return times;
}
LL check2()
{
	LL res=0;
	repn(i,1,n)
	{
		if (d[i]==0) t[i]=c[i]+L;
		else t[i]=L-c[i];
	}
	sort(t+1,t+1+n);
	LL times;
	if (b%n==0) times=(LL)(b-1)/n*2*L+t[n];
	else times=(LL)b/n*2*L+t[b%n];
	return times;
}
void work(LL x)
{
	na=a,nb=b;
	repn(i,1,n)
	{
		if (d[i]==0)
		{
			if (x<c[i]) nd[i]=0,nc[i]=c[i]-x;
			else
			{
				na--;
				LL lft=x-c[i];
				nd[i]=1;
				nc[i]=0;
				int times=lft/L;
				nd[i]^=(times&1);
				nb-=(times+1)/2;
				na-=times/2;
				LL rem=lft%L;
				if (nd[i]==0) nc[i]=L-rem;
				else nc[i]=rem;
			}
		}
		else
		{
			if (x<L-c[i]) nd[i]=1,nc[i]=c[i]+x;
			else
			{
				nb--;
				LL lft=x-(L-c[i]);
				nd[i]=0;
				nc[i]=L;
				int times=lft/L;
				nd[i]^=(times&1);
				na-=(times+1)/2;
				nb-=times/2;
				LL rem=lft%L;
				if (nd[i]==0) nc[i]=L-rem;
				else nc[i]=rem;
			}
		}
	}
}
vector<int> pos;
#define BUF_SIZE 100000
//fread -> read
bool IOerror = 0;
inline char nnc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if(p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if(pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
    char ch;
    while(blank(ch = nnc()));
    if(IOerror)
        return;
    for(x = ch - '0'; (ch = nnc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
}
#undef BUF_SIZE
int main()
{
	read(n),read(a),read(b);
	repn(i,1,n)
		read(c[i]);
	repn(i,1,n)
		read(d[i]);
	LL ans1=check1(),ans2=check2();
	work(min(ans1,ans2));
	if (ans1<ans2)
	{
		LL base=ans1;
		repn(i,1,n)
			if (nd[i]==0) ans1=max(ans1,base+nc[i]);
			else pos.pb(nc[i]);
		sort(all(pos));
		reverse(all(pos));
		for (auto x:pos)
			if (nb==0) ans1=max(ans1,base+L-x);
			else nb--,ans1=max(ans1,base+L-x+L);
		cout<<ans1<<endl;
	}
	else
	{
		LL base=ans2;
		repn(i,1,n)
			if (nd[i]==1) ans2=max(ans2,base+L-nc[i]);
			else pos.pb(nc[i]);
		sort(all(pos));
		for (auto x:pos)
			if (na==0) ans2=max(ans2,base+x);
			else na--,ans2=max(ans2,base+x+L);
		cout<<ans2<<endl;
	}
	return 0;
}