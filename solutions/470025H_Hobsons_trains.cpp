// Problem: Hobsons' trains
// URL: https://codeforces.com/gym/470025/problem/H
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

int n, k, d[N];
vector<int> g[N];
int dfn[N], low[N], f[N], cnt, sz[N], pre[N], cp[N], len[N], l[N], r[N];
int arr[N], pos[N], num;
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) f[fx] = fy, sz[fy] += sz[fx];
}
map<PII, int> S;
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++cnt;
	for (auto y: g[x]) {
		if (dfn[y] == 0) {
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] <= dfn[x]) Union(y, x);
		}
		else if (y != fa || S[mp(x, y)] == 2) low[x] = min(low[x], dfn[y]);
	}
}
int ff[N][20], sum[N], ans[N], h[N], dep[N], pp[N];
int cal(int x, int len) {
	per(i, 0, 20) if (len >> i & 1) x = ff[x][i];
	return x;
}
void work(int x, int fa, int anc) {
	dep[x] = dep[fa] + 1;
	ff[x][0] = fa;
	rep(i, 1, 20) ff[x][i] = ff[ff[x][i - 1]][i - 1];
	sum[x] += 1;
	if (k <= dep[x] - dep[anc] - 1) sum[cal(x, k + 1)]--;
	else {
		sum[anc]--;
		int left = k - (dep[x] - dep[anc] - 1);
		left = min(left, len[anc]);
		if (pos[anc] + left - 1 <= r[anc]) h[pos[anc]]++, h[pos[anc] + left]--;
		else {
			h[pos[anc]]++, h[r[anc] + 1]--;
			left = left - (r[anc] - pos[anc] + 1);
			h[l[anc]]++, h[l[anc] + left]--;
		}
	}
	for (auto y: g[x]) {
		if (pp[y] || y == fa) continue;
		work(y, x, anc);
		sum[x] += sum[y];
	}
	ans[x] = sum[x];
}
int main() {
	IO;
	cin >> n >> k;
	repn(i, 1, n) f[i] = i, sz[i] = 1;
	repn(i, 1, n) cin >> d[i], g[i].pb(d[i]), g[d[i]].pb(i), S[mp(i, d[i])]++, S[mp(d[i], i)]++;
	repn(i, 1, n) if (!dfn[i]) dfs(i, 0);
	repn(i, 1, n) if (sz[find(i)] > 1 && !cp[find(i)]) {
		cp[find(i)] = 1;
		int now = find(i), cur = num, ll = 0;
		while (!pp[now]) {
			ll++;
			pp[now] = 1;
			arr[++num] = now;
			pos[now] = num;
			now = d[now];
		}
		repn(i, cur + 1, num) len[arr[i]] = ll, l[arr[i]] = cur + 1, r[arr[i]] = num;
	}
	repn(i, 1, n) if (pp[i]) work(i, 0, i);
	int cur = 0;
	repn(i, 1, num) cur += h[i], ans[arr[i]] += cur;
	repn(i, 1, n) cout << ans[i] << "\n";
	return 0;
}