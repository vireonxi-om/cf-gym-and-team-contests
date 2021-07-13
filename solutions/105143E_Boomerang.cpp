// Problem: Boomerang
// URL: https://codeforces.com/gym/105143/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++20 (GCC 13-64)
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, r, t0, dis[N + N], x[N], y[N];
vector<int> g[N], h[N + N];
int dep[N], f[N][20];
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
    dep[x] = dep[fa] + 1;
    h[dep[x]].pb(x);
    f[x][0] = fa;
    rep(i, 1, 20) f[x][i] = f[f[x][i - 1]][i - 1];
    for (auto y: g[x]) if (y != fa) dfs(y, x);
}
int cal(int x, int y) {
    int z = lca(x, y);
    return dep[x] + dep[y] - 2 * dep[z];
}
int main() {
    IO;
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    cin >> r >> t0;
    dep[0] = -1;
    dfs(r, 0);
    dis[0] = 0, x[0] = y[0] = r;
    repn(i, 1, n + n) {
        if (h[i].size() == 0) {
            dis[i] = dis[i - 1];
            continue;
        }
        x[i] = x[i - 1], y[i] = y[i - 1];
        for (auto p: h[i]) {
            int d1 = cal(x[i], y[i]);
            int d2 = cal(x[i], p);
            int d3 = cal(y[i], p);
            if (d3 >= d2 && d3 >= d1) {
                x[i] = p;
            }
            else if (d2 >= d3 && d2 >= d1) {
                y[i] = p;
            }
        }
        dis[i] = cal(x[i], y[i]);
    }
    repn(k, 1, n) {
        int l = t0, r = n + n, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((mid - t0) * (LL)k * 2 >= dis[mid]) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << " \n"[k == n];
    }
    return 0;
}