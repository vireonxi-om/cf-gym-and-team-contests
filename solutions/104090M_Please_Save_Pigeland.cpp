// Problem: Please Save Pigeland
// URL: https://codeforces.com/gym/104090/problem/M
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

const int N = 1100000;
const int M = 2100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, k, pp[N], arr[N], l[N], r[N], cnt;
LL dis[N], d[N], sum, ans = 3 * INF;
vector<PII> g[N];
void dfs(int x, int fa) {
	if (pp[x]) {
		l[x] = ++cnt;
		arr[cnt] = x;
		sum += dis[x];
	}
	else l[x] = cnt + 1;
	for (auto p: g[x]) {
		int y = p.fi;
		LL w = p.se;
		if (y != fa) {
			dis[y] = dis[x] + w;
			dfs(y, x);
		}
	}
	r[x] = cnt;
}
LL v[M];
void update(int k) {
	v[k] = __gcd(abs(v[LC]), abs(v[RC]));
}
void change(int k, int l, int r, int a, LL b) {
	if (l == r) {
		v[k] += b;
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid) change(LC, l, mid, a, b);
	else change(RC, mid + 1, r, a, b);
	update(k);
}
void process(int l, int r, LL w) {
	if (l > r) return;
	sum += (r - l + 1) * w;
	change(1, 1, cnt, l, w);
	if (r + 1 <= cnt) change(1, 1, cnt, r + 1, -w);
}
void build(int k, int l, int r) {
	if (l == r) {
		v[k] = dis[arr[l]] - dis[arr[l - 1]];
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}

void work(int x, int fa) {
	ans = min(ans, sum / v[1]);
	for (auto p: g[x]) {
		int y = p.fi;
		LL w = p.se;
		if (y != fa) {
			process(1, cnt, w);
			process(l[y], r[y], - w - w);
			work(y, x);
			process(l[y], r[y], w + w);
			process(1, cnt, -w);
		}
	}
}
int main() {
	IO;
	cin >> n >> k;
	if (k == 1) {
		cout << 0 << endl;
		return 0;
	}
	repn(i, 1, k) {
		int x;
		cin >> x;
		pp[x] = 1;
	}
	rep(i, 1, n) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(y, w)), g[y].pb(mp(x, w));
	}
	dfs(1, 0);
	build(1, 1, cnt);
	work(1, 0);
	cout << ans * 2 << "\n";
	return 0;
}