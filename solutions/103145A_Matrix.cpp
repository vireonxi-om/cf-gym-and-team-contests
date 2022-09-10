// Problem: Matrix
// URL: https://codeforces.com/gym/103145/problem/A
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

const int N = 25100000;
const int M = 5100;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, n;
int f[N], inv[N];
LL C(int n,int m)
{
	LL res=((LL)f[n]*inv[m])%mod;
	res=(res*inv[n-m])%mod;
	return res;
}
LL pow_mod(LL a, LL e) {
    LL res = 1;
    for (;e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
    return res;
}
int main()
{
	IO;
	cin >> T;
	f[0] = 1;
	rep(i, 1, N)
		f[i] = (LL)f[i - 1] * i % mod;
	inv[N - 1] = pow_mod(f[N - 1], mod - 2);
	per(i, 0, N - 1)
	    inv[i] = (LL)inv[i + 1] * (LL)(i + 1) % mod;
	while (T--) {
		cin >> n;
		LL ans = 0;
		LL tmp = f[n * (n - 1)];
		tmp = tmp * n % mod;
		tmp = tmp * n % mod;
		LL res = 0;
		repn(i, 1, n) res = (res + C(n * n - i, n - 1) * f[n - 1]) % mod;
		cout << res * tmp % mod << "\n";
	}			
	return 0;
}