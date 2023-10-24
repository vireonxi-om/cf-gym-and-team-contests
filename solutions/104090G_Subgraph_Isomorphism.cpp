// Problem: Subgraph Isomorphism
// URL: https://codeforces.com/gym/104090/problem/G
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

int T, n, m, f[N], px, py, pp[N], fat[N], dep[N];
ull hsh[N];
PII e[N];
vector<int> g[N];
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}

int a[N], st[N], tail, num;
void dfs(int x, int fa) {
	st[++tail] = x;
	if (x == py) {
		num = tail;
		repn(i, 1, tail) a[i] = st[i], pp[st[i]] = 1;
	}
	for (auto y: g[x]) {
		if (y != fa) dfs(y, x);
	}
	tail--;
}
vector<int> tmp;

const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
ull shift(ull x) {
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}
ull cal(int x, int fa) {
	vector<ull> tmp;
	ull res = 1;
	for (auto y: g[x]) {
		if (!pp[y] && y != fa) {
			res += shift(cal(y, x));
		}
	}
	return res;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		repn(i, 1, m) cin >> e[i].fi >> e[i].se;
		if (m == n - 1) {
			cout << "YES\n";
			continue;
		}
		if (m > n) {
			cout << "NO\n";
			continue;
		}
		repn(i, 1, n) f[i] = i, pp[i] = 0, g[i].clear();
		repn(i, 1, n) {
			int x = e[i].fi, y = e[i].se;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				g[x].pb(y), g[y].pb(x);
				f[fx] = fy;
			}
			else px = x, py = y;
		}
		num = tail = 0;
		dfs(px, 0);
		repn(i, 1, num) hsh[i] = cal(a[i], 0);
		int flag = 0;
		repn(i, 2, num) if (hsh[i] != hsh[1]) flag = 1;
		if (!flag) {
			cout << "YES\n";
			continue;
		}
		if (num & 1) {
			cout << "NO\n";
			continue;
		}
		flag = 0;
		repn(i, 3, num) if (hsh[i] != hsh[i - 2]) flag = 1;
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}