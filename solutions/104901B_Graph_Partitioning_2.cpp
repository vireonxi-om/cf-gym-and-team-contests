// Problem: Graph Partitioning 2
// URL: https://codeforces.com/gym/104901/problem/B
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

const int N = 110000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, k, sz[N];
const int L = 320;
vector<int> g[N];
LL dp[N][L + 10], tmp[L + 10];
int dp2[N][L + 10][3], tmp2[L + 10][3];
int cal(int n, int num) {
	int d = n / k;
	if (d * k + num > n) d--;
	int n1 = num, n0 = d - num;
	return n - n0 * k - n1 * (k + 1);
}
void dfs(int x, int fa) {
	memset(dp[x], 0, sizeof(dp[x]));
	memset(dp2[x], 0, sizeof(dp2[x]));
	if (k <= L) dp[x][1] = 1;
	else dp2[x][0][2] = 1;
	sz[x] = 1;
	for (auto y: g[x]) {
		if (y == fa) continue;
		dfs(y, x);
		if (k <= L) {
			memset(tmp, 0, sizeof(tmp));
			repn(i, 1, min(sz[x], k + 1)) {
				repn(j, 1, min(sz[y], k + 1)) {
					if (j == k || j == k + 1) tmp[i] = (tmp[i] + dp[x][i] * dp[y][j]) % mod;
					if (i + j <= k + 1) tmp[i + j] = (tmp[i + j] + dp[x][i] * dp[y][j]) % mod;
				}
			}
			rep(i, 0, L + 10) dp[x][i] = tmp[i];
		}
		else {
			memset(tmp2, 0, sizeof(tmp2));
			int lx = sz[x] / k, ly = sz[y] / k;
			repn(i, 0, lx) rep(sx, 0, 3) {
				repn(j, 0, ly) rep(sy, 0, 3) {
					int rx, ry;
					if (sx == 0) rx = k;
					else if (sx == 1) rx = k + 1;
					else rx = cal(sz[x], i);
					if (sy == 0) ry = k;
					else if (sy == 1) ry = k + 1;
					else ry = cal(sz[y], j);
					if (ry == k || ry == k + 1) tmp2[i + j][sx] = (tmp2[i + j][sx] + (LL)dp2[x][i][sx] * dp2[y][j][sy]) % mod;
					if (rx + ry <= k + 1) {
						if (rx + ry == k + 1) tmp2[i + j + 1][1] = (tmp2[i + j + 1][1] + (LL)dp2[x][i][sx] * dp2[y][j][sy]) % mod;
						else if (rx + ry == k) tmp2[i + j][0] = (tmp2[i + j][0] + (LL)dp2[x][i][sx] * dp2[y][j][sy]) % mod;
						else tmp2[i + j][2] = (tmp2[i + j][2] + (LL)dp2[x][i][sx] * dp2[y][j][sy]) % mod;
					}
				}
			}
			rep(i, 0, L + 10) rep(j, 0, 3) dp2[x][i][j] = tmp2[i][j];
		}
		sz[x] += sz[y];
	}
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		repn(i, 1, n) g[i].clear();
		rep(i, 1, n) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y), g[y].pb(x);
		}
		dfs(1, 0);
		LL ans = 0;
		if (k <= L) ans = (dp[1][k] + dp[1][k + 1]) % mod;
		else {
			repn(i, 0, n / k) {
				ans = (ans + dp2[1][i][0] + dp2[1][i][1]) % mod;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}