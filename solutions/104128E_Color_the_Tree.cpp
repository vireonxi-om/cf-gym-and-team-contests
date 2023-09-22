// Problem: Color the Tree
// URL: https://codeforces.com/gym/104128/problem/E
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
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, a[N];
const int MAX=110000;
int stmx[MAX][32], stmn[MAX][32];
int preLog2[MAX];

void st_prepare(int n, int *array) {
	preLog2[1] = 0;
	repn(i, 2, n) {
		preLog2[i] = preLog2[i - 1];
		if ((1 << preLog2[i] + 1) == i) preLog2[i]++;
	}
	per(i, 0, n) {
		stmx[i][0] = stmn[i][0] = array[i];
		for (int j = 1; (i + (1 << j) - 1) < n; j++) {
			stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1 << j - 1)][j - 1]);
			stmn[i][j] = min(stmn[i][j - 1], stmn[i + (1 << j - 1)][j - 1]);
		}
	}
}
int query_max(int l, int r) {
	int len = r - l + 1, k = preLog2[len];
	return max(stmx[l][k], stmx[r - (1 << k) + 1][k]);
}
LL query_min(int l, int r) {
	int len = r - l + 1, k = preLog2[len];
	return min(stmn[l][k], stmn[r - (1 << k) + 1][k]);
}
int dep[N], dfn[N], f[N][20], cnt;
vector<int> g[N], lst[N];
int cmp(int x, int y) {
	return dfn[x] < dfn[y];
}
void dfs(int x, int fa) {
	dfn[x] = ++cnt, dep[x] = dep[fa] + 1;
	lst[dep[x]].pb(x);
	f[x][0] = fa;
	rep(i, 1, 20) f[x][i] = f[f[x][i - 1]][i - 1];
	for (auto y: g[x]) if (y != fa) dfs(y, x);
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for (int i = 19; i--;)
		if (tmp >> i & 1) x = f[x][i];
	if (x == y) return x;
	for (int i = 19; i--;)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
vector<int> vg[N], vlist;
void virtual_init(vector<int> varr) {
	static int st[N];
	int tail = 0, n = varr.size();
	sort(varr.begin(), varr.end(), cmp);
	vlist.clear(), vlist.pb(1);
	st[++tail] = 1;
	for (auto x: varr) {
		int tmp = lca(st[tail], x);
		while (1) {
			if (dep[st[tail - 1]] <= dep[tmp]) {
				int y = st[tail--];
				if (tmp != y) vg[tmp].pb(y);
				if (st[tail] != tmp) st[++tail] = tmp, vlist.pb(tmp);
				break;
			}
			int y = st[tail];
			if (st[tail - 1] != y) vg[st[tail - 1]].pb(y);
			tail--;
		}
		if (st[tail] != x) st[++tail] = x, vlist.pb(x);
	}
	while (tail > 1) {
		int y = st[tail];
		if (st[tail - 1] != y) vg[st[tail - 1]].pb(y);
		tail--;
	}
}
void clear() {
	for (auto x: vlist) vg[x].clear();
}
LL ans, dp[N];
int cp[N];
int cur;
void work(int x, int fa) {
	dp[x] = 0;
	for (auto y: vg[x]) {
		work(y, x);
		dp[x] += dp[y];
	}
	if (cp[x]) dp[x] = query_min(cur - dep[x], cur - dep[fa] - 1);
	else dp[x] = min(dp[x], query_min(cur - dep[x], cur - dep[fa] - 1));
}
		
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		repn(i, 1, n) g[i].clear(), lst[i].clear();
		rep(i, 1, n) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y), g[y].pb(x);
		}
		st_prepare(n, a);
		cnt = 0;
		dfs(1, 0);
		ans = 0;
		repn(i, 1, n) {
			if (lst[i].size() == 0) continue;
			vector<int> varr = lst[i];
			for (auto x: varr) cp[x] = 1;
			virtual_init(varr);
			cur = i;
			work(1, 0);
			for (auto x: varr) cp[x] = 0;
			clear();
			ans += dp[1];
		}
		cout << ans << "\n";
	}
	return 0;
}