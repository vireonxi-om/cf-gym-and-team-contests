// Problem: Divide a Tree
// URL: https://codeforces.com/gym/102821/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, cas, n, ans, cur, flag;
int a[N], son[N], sz[N], pp[N];
vector<int> g[N];
void dfs(int x, int fa) {
	sz[x] = 1;
	for (auto y: g[x]) {
		if (y != fa) {
			dfs(y, x);
			if (sz[y] > sz[son[x]]) son[x] = y;
			sz[x] += sz[y];
		}
	}
}
int b[N], num[N];
void work(int x, int fa, int f) {
	b[a[x]] += f;
	if (b[a[x]] == num[a[x]]) flag = 1;
	for (auto y: g[x]) {
		if (y != fa && !pp[y] && y != cur) work(y, x, f);
	}
}
void dfs2(int x, int fa, int keep) {
	for (auto y: g[x]) {
		if (y != fa && y != son[x]) dfs2(y, x, 0);
	}
	if (son[x]) {
		dfs2(son[x], x, 1);
		cur = son[x];
	}
	flag = 0;
	work(x, fa, 1);
	if (flag) ans++, pp[x] = 1;
	cur = 0;
	if (!keep || flag) work(x, fa, -1);
}
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		repn(i, 1, n) num[i] = b[i] = 0;
		repn(i, 1, n) cin >> a[i], g[i].clear(), son[i] = pp[i] = 0, num[a[i]]++;
		rep(i, 1, n) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y), g[y].pb(x);
		}
		dfs(1, 0);
		ans = 0;
		dfs2(1, 0, 1);
		cout << "Case " << ++cas << ": " << ans << "\n";
	}
	return 0;
}