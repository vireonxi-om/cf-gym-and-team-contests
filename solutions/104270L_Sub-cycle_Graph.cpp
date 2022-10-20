// Problem: Sub-cycle Graph
// URL: https://codeforces.com/gym/104270/problem/L
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
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n;
LL m, ans, f[N], ff[N], inv[N], ipw2[N];
LL C(int n, int m) {
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
LL inv2 = pow_mod(2, mod - 2), inv6 = pow_mod(6, mod - 2);
int main() {
	IO;
	f[0] = 1;
	rep(i, 1, N) f[i] = (f[i - 1] * i) % mod;
	ipw2[0] = 1;
	rep(i, 1, N) ipw2[i] = ipw2[i - 1] * inv2 % mod;
	ff[1] = ff[0] = inv[1] = inv[0] = 1;  
	rep(i, 2, N) {
    	inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    	ff[i] = inv[i];
	}
	rep(i, 2, N) inv[i] = (inv[i - 1] * inv[i]) % mod;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		if (m > n) {
			cout << "0\n";
			continue;
		}
		if (m == n) {
			ans = f[n] * ff[n] % mod;
			ans = ans * inv2 % mod;
			cout << ans << "\n";
			continue;
		}
		if (m == n - 1) {
			cout << (f[n] * inv2 % mod) << "\n";
			continue;
		}
		int num = n - m;
		ans = 0;
		repn(i, 0, num) {
			int left = n - i, ng = num - i;
			if (left < ng * 2 || ng < 0) continue;
			if (ng == 0 && left == 0) {
				ans = (ans + 1) % mod;
				continue;
			}
			if (ng == 0) continue;
			LL res = f[left] * C(ng + left - ng - ng - 1, ng - 1) % mod;
			res = res * ipw2[ng] % mod;
			res = res * inv[ng] % mod;
			res = res * C(n, n - i) % mod;
			ans = (ans + res) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}