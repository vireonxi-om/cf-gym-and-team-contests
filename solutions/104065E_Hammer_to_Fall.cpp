// Problem: Hammer to Fall
// URL: https://codeforces.com/gym/104065/problem/E
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

const int N = 110000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

const int L = 1000;
int n, m, q, b[N], du[N];
LL dp[N], a[N];
vector<PII> g[N], cg[N];
set<pair<LL, int> > s[N];
int main() {
	IO;
	cin >> n >> m >> q;
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, m) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(y, w)), g[y].pb(mp(x, w));
		du[x] += 1, du[y] += 1;
	}
	repn(i, 1, n) {
		for (auto p: g[i]) {
			int y = p.fi, w = p.se;
			if (du[y] >= L) cg[i].pb(p), s[y].insert(mp(w, i));
		}
	}
	repn(i, 1, q) cin >> b[i];
	pern(i, 1, q) {
		int pos = b[i];
		for (auto p: cg[pos]) {
			int y = p.fi, w = p.se;
			s[y].erase(mp(dp[pos] + w, pos));
		}
		dp[pos] = INF;
		if (du[pos] >= L) dp[pos] = (s[pos].begin()) -> fi;
		else {
			for (auto p: g[pos]) {
				int y = p.fi, w = p.se;
				dp[pos] = min(dp[pos], dp[y] + w);
			}
		}
		for (auto p: cg[pos]) {
			int y = p.fi, w = p.se;
			s[y].insert(mp(dp[pos] + w, pos));
		}
	}
	LL ans = 0;
	repn(i, 1, n) {
		dp[i] %= mod;
		ans = (ans + dp[i] * a[i]) % mod;
	}
	cout << ans << "\n";
	return 0;
}