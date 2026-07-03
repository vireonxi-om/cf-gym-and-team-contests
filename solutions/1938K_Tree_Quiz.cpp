// Problem: Tree Quiz
// URL: https://codeforces.com/problemset/problem/1938/K
// Rating: 2400
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
const int M = 11000000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, q, root;
vector<PII> h[N];
vector<int> g[N];
LL ans[N];
int l[N], r[N], cnt, sz[N];
int dep[N], f[N][20], arr[N];
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

void dfs(int x, int fa) {
	l[x] = ++cnt;
	arr[cnt] = x;
	f[x][0] = fa;
	sz[x] = 1;
	rep(i, 1, 20) f[x][i] = f[f[x][i - 1]][i - 1];
	dep[x] = dep[fa] + 1;
	for (auto y: g[x]) dfs(y, x), sz[x] += sz[y];
	r[x] = cnt;
}
int sum[M], num[M], ch[M][2], pos;
int copy(int x) {
	pos++;
	sum[pos] = sum[x];
	ch[pos][0] = ch[x][0], ch[pos][1] = ch[x][1];
	return pos;
}
void insert(int k, int l, int r, int a) {
	sum[k]++;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (a <= mid) insert(ch[k][0] = copy(ch[k][0]), l, mid, a);
	else insert(ch[k][1] = copy(ch[k][1]), mid + 1, r, a);
}
int ask(int a, int b, int c, int d, int l, int r, int k) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	int res = sum[ch[b][0]] - sum[ch[a][0]] + sum[ch[d][0]] - sum[ch[c][0]];
	if (res >= k) return ask(ch[a][0], ch[b][0], ch[c][0], ch[d][0], l, mid, k);
	else return ask(ch[a][1], ch[b][1], ch[c][1], ch[d][1], mid + 1, r, k - res);
}
int rt[N];
void add(int k, int l, int r, int a, int b) {
	num[k] += b;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (a <= mid) add(LC, l, mid, a, b);
	else add(RC, mid + 1, r, a, b);
}
PII ask(int k, int l, int r, int a) {
	if (l == r) return mp(l, a);
	int mid = (l + r) / 2;
	if (num[LC] >= a) return ask(LC, l, mid, a);
	else return ask(RC, mid + 1, r, a - num[LC]);
}
int getk(int x, int k) {
	per(i, 0, 20) if (k >> i & 1) x = f[x][i];
	return x;
}
void dfs2(int x, int fa) {
	add(1, 1, n, x, sz[x]);
	for (auto p: h[x]) {
		int k = p.fi, id = p.se;
		PII res = ask(1, 1, n, k);
		int w = res.fi;
		k = res.se;
		int a, b, c, d;
		if (w == x) {
			a = b = 0;
			c = l[x] - 1, d = r[x];
		}
		else {
			int ww = getk(x, dep[x] - dep[w] - 1);
			a = l[w] - 1, b = l[ww] - 1, c = r[ww], d = r[w];
		}
		int y = ask(rt[a], rt[b], rt[c], rt[d], 1, n, k);
		ans[id] = (LL)(x - 1) * n * n + (LL)(w - 1) * n + y - 1;
	}
	add(1, 1, n, x, -sz[x]);
	for (auto y: g[x]) {
		add(1, 1, n, x, sz[x] - sz[y]);
		dfs2(y, x);
		add(1, 1, n, x, sz[y] - sz[x]);
	}
	
}
int main() {
	IO;
	cin >> n >> q;
	repn(i, 1, n) {
		int x;
		cin >> x;
		if (x == 0) root = i;
		else g[x].pb(i);
	}
	dfs(root, 0);
	rt[0] = ++pos;
	repn(i, 1, n) rt[i] = copy(rt[i - 1]), insert(rt[i], 1, n, arr[i]);
	repn(i, 1, q) {
		LL k;
		cin >> k;
		int x = (k - 1) / n + 1;
		h[x].pb(mp((k - 1) % n + 1, i));
	}
	dfs2(root, 0);
	repn(i, 1, q) cout << ans[i] << "\n";
	return 0;
}