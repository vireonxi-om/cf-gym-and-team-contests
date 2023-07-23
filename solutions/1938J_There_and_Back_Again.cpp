// Problem: There and Back Again
// URL: https://codeforces.com/problemset/problem/1938/J
// Rating: 2100
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m;
struct edge {
	int x, y, w;
}e[M];
vector<PII> g[N];
int dis1[N], disn[N], pp[N], pre[N];
priority_queue<PII, vector<PII>, greater<PII> > q;
int dp[N];
PII a[N];
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int x, y, w;
		cin >> x >> y >> w;
		e[i] = {x, y, w};
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	repn(i, 1, n) dis1[i] = disn[i] = inf;
	dis1[1] = disn[n] = 0;
	q.push(mp(0, 1));
	while (!q.empty()) {
		int now = q.top().se;
		q.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: g[now]){
			int y = p.fi, w = p.se;
			if (dis1[now] + w < dis1[y]) {
				dis1[y] = dis1[now] + w;
				pre[y] = now;
				q.push(mp(dis1[y], y));
			}
		}
	}
	if (dis1[n] == inf) {
		cout << "-1\n";
		return 0;
	}
	memset(pp, 0, sizeof(pp));
	q.push(mp(0, n));
	while (!q.empty()) {
		int now = q.top().se;
		q.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: g[now]){
			int y = p.fi, w = p.se;
			if (disn[now] + w < disn[y]) {
				disn[y] = disn[now] + w;
				q.push(mp(disn[y], y));
			}
		}
	}
	dp[1] = 1;
	repn(i, 1, n) a[i] = mp(dis1[i], i);
	sort(a + 1, a + n + 1);
	repn(i, 1, n) {
		int u = a[i].se;
		for (auto p: g[u]) {
			int v = p.fi, w = p.se;
			if (dis1[u] + w == dis1[v]) {
				dp[v] = min(dp[v] + dp[u], 2);
			}
		}
	}
	if (dp[n] == 2) {
		cout << 2 * dis1[n] << "\n";
		return 0;
	}
	int ans = dis1[n], mn = inf;
	repn(i, 1, m) {
		int u = e[i].x, v = e[i].y, w = e[i].w;
		if (dis1[u] + w + disn[v] == dis1[n] || disn[u] + w + dis1[v] == dis1[n]) continue;
		mn = min(mn, dis1[u] + w + disn[v]);
		swap(u, v);
		mn = min(mn, dis1[u] + w + disn[v]);
	}
	int x = n;
	memset(pp, 0, sizeof(pp));
	while (x) pp[x] = 1, x = pre[x];
	x = n;
	while (x) {
		for (auto p: g[x]) {
			int y = p.fi, w = p.se;
			if (!pp[y]) mn = min(mn, dis1[n] + 2 * w);
		}
		x = pre[x];
	}
	if (mn == inf) cout << "-1\n";
	else cout << ans + mn << "\n";
	return 0;
}