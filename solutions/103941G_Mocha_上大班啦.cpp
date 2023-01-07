// Problem: Mocha 上大班啦
// URL: https://codeforces.com/gym/103941/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 1100;
const int M = 4100;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m, q;
LL f[N][M], inv;
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
int main() {
	IO;
	cin >> n >> m;
	inv = pow_mod(100, mod - 2);
	repn(i, 1, n) {
		string s;
		cin >> s;
		rep(j, 0, m) {
			if (s[j] == '1') f[i][j + 1] = 1;
		}
	}
	cin >> q;
	while (q--) {
		int i, j, l, r;
		LL p;
		cin >> i >> j >> l >> r >> p;
	}
	LL ans = 0;
	repn(j, 1, m) {
		LL res = 1;
		repn(i, 1, n) res = res * f[i][j] % mod;
		ans = (ans + res) % mod;
	}
	cout << ans << "\n";
	return 0;
}