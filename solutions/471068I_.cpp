// Problem: 
// URL: https://codeforces.com/gym/471068/problem/I
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, cas;
LL ans;
map<PII, int> S;
unordered_map<int, int> col[N], ring[N];
vector<int> g[N];
int dfn[N], low[N], f[N], cnt, sz[N], pre[N];
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) f[fx] = fy, sz[fy] += sz[fx];
}
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

int main() {
	IO;
	cin >> T;
	while (T--) {
		S.clear();
		cin >> n >> m;
		cnt = 0;
		repn(i, 1, n) col[i].clear(), ring[i].clear(), g[i].clear(), dfn[i] = 0, f[i] = i, sz[i] = 1;
		repn(i, 1, n) {
			int x, y, c;
			cin >> x >> y >> c;
			g[x].pb(y), g[y].pb(x);
			if (x > y) swap(x, y);
			S[mp(x, y)] = c;
			col[x][c]++, col[y][c]++;
		}
		repn(i, 1, n) if (!dfn[i]) dfs(i, 0);
		for (auto p: S) {
			int x = p.fi.fi, y = p.fi.se, c = p.se;
			if (find(x) == find(y)) ring[find(x)][c]++;
		}
		ans = 0;
		repn(i, 1, n) ans += col[i].size() - 1;
		repn(i, 1, n) if (find(i) == i && sz[i] > 1 && ring[i].size() == 1) ans++;
		cout << "Case #" << ++cas << ":\n";
		while (m--) {
			int x, y, c;
			cin >> x >> y >> c;
			if (x > y) swap(x, y);
			ans -= col[x].size() - 1;
			ans -= col[y].size() - 1;
			int oc = S[mp(x, y)];
			if (find(x) == find(y)) {
				if (ring[find(x)].size() == 1) ans--;
				ring[find(x)][oc]--;
				if (ring[find(x)][oc] == 0) ring[find(x)].erase(oc);
			}
			S[mp(x, y)] = c;
			col[x][oc]--;
			if (col[x][oc] == 0) col[x].erase(oc);
			col[y][oc]--;
			if (col[y][oc] == 0) col[y].erase(oc);
			col[x][c]++, col[y][c]++;
			ans += col[x].size() - 1, ans += col[y].size() - 1;
			if (find(x) == find(y)) {
				ring[find(x)][c]++;
				if (ring[find(x)].size() == 1) ans++;
			}
			cout << ans << "\n";
		}
	}
			
	return 0;
}