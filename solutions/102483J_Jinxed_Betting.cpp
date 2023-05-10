// Problem: Jinxed Betting
// URL: https://codeforces.com/gym/102483/problem/J
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
const LL inf=1e18;
int n;
LL a[N];
LL ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+2,a+n+1);
	reverse(a+2,a+n+1);
	a[n+1]=-inf;
	LL dal=0,dmx=0;
	
	if (a[2]!=a[3])
	{
		ans+=a[2]-a[3];
		dal+=a[2]-a[3];
	}
	int tail=2;
	while (true)
	{
		while (tail<n&&a[2]+dmx==a[tail+1]+dal) tail++;
		LL num=tail-1;
		LL d=0,tmp=num;
		while (tmp) d++,tmp/=2;
		LL delta1=a[1]-a[2]-dmx+1;
		LL delta2=a[2]+dmx-a[tail+1]-dal;
		LL round1=(delta1+d-2)/(d-1);
		LL round2=(delta2+d-2)/(d-1);
		if (round1<=round2)
		{
			LL dd=delta1/(d-1);
			ans+=dd*d;
			ans+=delta1%(d-1);
			if (delta1%(d-1)==0) ans--;
			cout<<ans-1<<endl;
			return 0;
		}
		else
		{
			dmx+=round2*(d-1);
			dal+=round2*d;
			ans+=round2*d;
		}
	}
	return 0;
}