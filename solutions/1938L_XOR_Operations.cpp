// Problem: XOR Operations
// URL: https://codeforces.com/problemset/problem/1938/L
// Rating: 2800
// Tags: none (gym/team contest)
// Language: C++20 (GCC 11-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

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
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

map<int, int> S;
int n, a[N];
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
vector<int> b;
int main() {
	IO;
	cin >> n;
	cin >> a[1];
	repn(i, 2, n) {
		cin >> a[i];
		a[i] ^= a[1];
		for (auto x: b) a[i] = min(a[i], a[i] ^ x);
		if (a[i]) b.pb(a[i]);
	}
	int m = b.size();
	LL ans = m * (m - 1) / 2 + m * (n - m);
	cout << pow_mod(2, ans) << "\n";
	return 0;
}