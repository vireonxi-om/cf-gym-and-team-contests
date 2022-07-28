// Problem: United in Stormwind
// URL: https://codeforces.com/gym/103202/problem/M
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
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;
void fwt_xor(LL *a,int length,int type)
{
	int len=-1;
	for (int x=length;x;++len,x>>=1);
	for (int i=1;i<=len;++i)
		for (int j=0;j<length;j+=1<<i)
			for (int k=j,szk=1<<i-1;k<j+szk;++k)
			{
				LL s=a[k],t=a[k+szk];
				a[k]=s+t;
				a[k+szk]=s-t;
			}
	if (type==1) return;
	for (int i=0;i<length;++i)
		a[i]=a[i] / length;
}
int n, m;
LL k;
LL a[N], b[N];
int c[N];
int main()
{
	IO;
	cin >> n >> m >> k;
	repn(i, 1, n) {
		string s;
		cin >> s;
		int res = 0;
		rep(j, 0, m) res = res * 2 + s[j] - 'A';
		a[res]++;
	}
	fwt_xor(a, 1 << m, 1);
	rep(i, 0, 1 << m)
		a[i] = a[i] * a[i];
	fwt_xor(a, 1 << m, -1);
	a[0] -= n;
	rep(i, 0, 1 << m) a[i] /= 2;
	LL all = (LL)n * (n - 1) / 2;
	rep(i, 0, m) {
		rep(j, 0, 1 << m) {
			if (j >> i & 1) a[j] += a[j ^ (1 << i)];
		}
	}
	int ans = 0;
	rep(i, 1, 1 << m) if (all - a[i ^ ((1 << m) - 1)] >= k) ans++;
	cout << ans << endl;
	return 0;
}