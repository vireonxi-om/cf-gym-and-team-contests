// Problem: Dead-End Detector
// URL: https://codeforces.com/gym/470025/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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

const int N = 510000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, du[N], pp[N];
vector<int> g[N], h[N];
int dfn[N], low[N], f[N], cnt, sz[N], pre[N];
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) f[fx] = fy, sz[fy] += sz[fx];
}
map<PII, PII> S;
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++cnt;
	for (auto y: g[x]) {
		if (dfn[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] <= dfn[x]) Union(y, x);
		}
		else if (y != fa) low[x] = min(low[x], dfn[y]);
	}
}
vector<PII> ans;
int num, root;
PII anc[N];
vector<int> arr;
void work(int x, int fa) {
	pp[x] = 1;
	arr.pb(x);
	if (sz[x] >1) num++, root = x;
	for (auto y: h[x]) if (y != fa) work(y, x);
	if (du[x] == 1) {
		if (fa == 0) anc[x] = S[mp(x, h[x][0])];
		else anc[x] = S[mp(x, fa)];
	}
}
int tp[N];
void work2(int x, int fa) {
	tp[x] = (sz[x] > 1);
	for (auto y: h[x]) {
		if (y != fa) {
			work2(y, x);
			tp[x] += tp[y];
		}
	}
}
void work3(int x, int fa) {
	for (auto y: h[x]) {
		if (y != fa) {
			if (tp[y] == 0) ans.pb(S[mp(x, y)]);
			else work3(y, x);
		}
	}
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) f[i] = i, sz[i] = 1;
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y), g[y].pb(x);
	}
	repn(i, 1, n) if (!dfn[i]) dfs(i, 0);
	repn(x, 1, n) {
		for (auto y: g[x]) {
			if (find(x) == find(y)) continue;
			h[find(x)].pb(find(y)), du[find(x)]++, S[mp(find(x), find(y))] = mp(x, y);
		}
	}
	repn(i, 1, n) if (!pp[find(i)]) {
		num = root = 0;
		arr.clear();
		work(find(i), 0);
		if (num == 0) {
			for (auto x: arr) if (anc[x].fi) ans.pb(anc[x]);
		}
		else {
			work2(root, 0);
			work3(root, 0);
		}
	}
	cout << ans.size() << "\n";
	if (ans.size() > 0) {
		sort(all(ans));
		for (auto p: ans) cout << p.fi << " " << p.se << "\n";
	}
	return 0;
}