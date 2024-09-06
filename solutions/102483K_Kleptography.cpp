// Problem: Kleptography
// URL: https://codeforces.com/gym/102483/problem/K
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

const int N=210000;
const int M=1100000;
const LL mod=1e9+7;

int n,m;
char s[N],t[N];
char key[N],plain[N],cipher[N];
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",cipher+1);
	for (int i=1;i<=n;i++)
		plain[m-n+i]=s[i];
	for (int i=m;i>=1;i--)
	{
		if (plain[i])
		{
			int tmp=(cipher[i]-plain[i]+26)%26;
			key[i]=tmp+'a';
			if (i>n) plain[i-n]=key[i];
		}
		else if (key[i])
		{
			int tmp=(cipher[i]-key[i]+26)%26;
			plain[i]=tmp+'a';
			if (i+n<=m) key[i+n]=plain[i];
		}
	}
	printf("%s\n",plain+1);
	return 0;
}