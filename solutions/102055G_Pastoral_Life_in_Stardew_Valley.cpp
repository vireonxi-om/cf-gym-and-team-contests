// Problem: Pastoral Life in Stardew Valley
// URL: https://codeforces.com/gym/102055/problem/G
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;
LL f[N], inv[N], ff[N];
LL C(int n,int m)
{
	LL res=(f[n]*inv[m])%mod;
	res=(res*inv[n-m])%mod;
	return res;
}
int T, n, m, cnt;
int main()
{
	IO;
	f[0]=1;
	for (int i=1;i<N;i++)
		f[i]=(f[i-1]*i)%mod;
	ff[1]=ff[0]=inv[1]=inv[0]=1;  
	for (int i=2;i<N;i++)
	{
    	inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
    	ff[i]=inv[i];
	}
	for (int i=2;i<N;i++)
		inv[i]=(inv[i-1]*inv[i])%mod;
	cin >> T;
	while (T--) {
		cnt++;
		cin >> n >> m;
		LL ans = 1;
		if (n < 3 || m < 3) ans = 0;
		else ans = C(n + 5 - 1 - 3, 4) * C(m + 5 - 1 - 3, 4) %mod;
		cout << "Case " << cnt << ": " << ans << "\n";
	}
	return 0;
}