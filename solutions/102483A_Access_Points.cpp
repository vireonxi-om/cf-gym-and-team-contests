// Problem: Access Points
// URL: https://codeforces.com/gym/102483/problem/A
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
typedef __int128 int128;
int n;
int a[N],b[N];
double ans;
struct node
{
	LL num;
	LL sum,sqr;
	double x()
	{
		return (double)sum/(double)num;
	}
	double v()
	{
		double gx=x();
		return sqr+num*gx*gx-2*gx*sum;
	}
	friend node operator + (node a, node b)
	{
		node tmp;
		tmp.num=a.num+b.num;
		tmp.sum=a.sum+b.sum;
		tmp.sqr=a.sqr+b.sqr;
		return tmp;
	}
	friend bool operator < (node a,node b)
	{
		return (int128)a.sum*(int128)b.num<(int128)b.sum*(int128)a.num;
	}
};
stack<node> s;
void work(int a[])
{
	for (int i=1;i<=n;i++)
	{
		node tmp;
		tmp.num=1,tmp.sum=a[i],tmp.sqr=(LL)a[i]*(LL)a[i];
		while (!s.empty()&&tmp<s.top())
		{
			tmp=s.top()+tmp;
			s.pop();
		}
		s.push(tmp);
	}
	while (!s.empty())
	{
		node tmp=s.top();
		s.pop();
		ans+=tmp.v();
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]);
	work(a);
	work(b);
	printf("%.10f\n",ans);
	return 0;
}