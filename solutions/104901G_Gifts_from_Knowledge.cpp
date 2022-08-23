// Problem: Gifts from Knowledge
// URL: https://codeforces.com/gym/104901/problem/G
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, num;
PII a[N];
vector<int> g[N];
LL ans;
int f[N], w[N], sz[N];
int getf(int x) {
	while (f[x] != x) x = f[x];
	return x;
}
int getw(int x) {
	int res = 0;
	while (f[x] != x) res ^= w[x], x = f[x];
	return res;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		num = n;
		repn(i, 1, m) g[i].clear();
		repn(i, 1, n) f[i] = i, w[i] = 0, sz[i] = 1;
		repn(i, 1, n) {
			string s;
			cin >> s;
			rep(j, 0, m) if (s[j] == '1') g[j + 1].pb(i);
		}
		ans = 1;
		int l = 1, r = m;
		while (l <= r) {
			if (l == r) {
				if (g[l].size() > 1) ans = 0;
			}
			else {
				if (g[l].size() + g[r].size() > 2) ans = 0;
				else if (g[l].size() + g[r].size() <= 1);
				else {
					int x, y, ww;
					if (g[l].size() == 2) {
						x = g[l][0], y = g[l][1], ww = 1;
					}
					else if (g[r].size() == 2) {
						x = g[r][0], y = g[r][1], ww = 1;
					}
					else if (g[l][0] != g[r][0]) {
						x = g[l][0], y = g[r][0], ww = 0;
					}
					else {
						l++, r--;
						continue;
					}
					int fx = getf(x), fy = getf(y);
					if (fx != fy) {
						if (sz[fx] > sz[fy]) swap(fx, fy);
						sz[fy] += sz[fx];
						w[fx] = (ww ^ getw(x) ^ getw(y));
						f[fx] = fy;
						num--;
					}
					else {
						if (getw(x) ^ getw(y) ^ ww) ans = 0;
					}
				}
			}
			l++, r--;
		}
		repn(i, 1, num) ans = ans * 2 % mod;
		cout << ans << "\n";
	}
	return 0;
}