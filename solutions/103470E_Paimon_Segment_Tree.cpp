// Problem: Paimon Segment Tree
// URL: https://codeforces.com/gym/103470/problem/E
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

int n, m, q;
struct query {
	int l, r, tp, id;
};
vector<query> f[N];
int a[N];
struct node {
	LL sum2, sum, len, sumc;
}tr[M];
// sum2 += k * sum + len * x
// sumc += k * sum + len * x
// sum += len * x 
struct lazy {
	PLL sum2, sumc;
	LL sum, len;
}lz[M];
node operator + (node a, node b) {
	node res = {
		(a.sum2 + b.sum2) % mod,
		(a.sum + b.sum) % mod,
		a.len + b.len,
		(a.sumc + b.sumc) % mod};
	return res;
}
node operator + (node a, lazy b) {
	node res = a;
	res.sum2 = (res.sum2 + b.sum2.fi * res.sum + b.sum2.se * res.len) % mod;
	res.sumc = (res.sumc + b.sumc.fi * res.sum + b.sumc.se * res.len) % mod;
	res.sum = (res.sum + b.sum * res.len) % mod;
	return res;
}
lazy operator + (lazy a, lazy b) {
	lazy res;
	res.sum2.fi = (a.sum2.fi + b.sum2.fi) % mod;
	res.sum2.se = (a.sum2.se + b.sum2.se + a.sum * b.sum2.fi) % mod;
	res.sumc.fi = (a.sumc.fi + b.sumc.fi) % mod;
	res.sumc.se = (a.sumc.se + b.sumc.se + a.sum * b.sumc.fi) % mod;
	res.sum = (a.sum + b.sum) % mod;
	res.len = a.len;
	return res;
}
void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void pushdown(int k) {
	lz[LC] = lz[LC] + lz[k];
	lz[RC] = lz[RC] + lz[k];
	tr[LC] = tr[LC] + lz[k];
	tr[RC] = tr[RC] + lz[k];
	lz[k].sum2 = lz[k].sumc = mp(0, 0), lz[k].sum = 0;
}
void build(int k, int l, int r) {
	lz[k].len = tr[k].len = r - l + 1;
	if (l == r) {
		tr[k].sum2 = (LL)a[l] * a[l] % mod;
		tr[k].sum = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a, int b, lazy c) {
	if (l == a && r == b) {
		tr[k] = tr[k] + c;
		lz[k] = lz[k] + c;
		return;
	}
	pushdown(k);
	int mid = (l + r) / 2;
	if (b <= mid) change(LC, l, mid, a, b, c);
	else if (a > mid) change(RC, mid + 1, r, a, b, c);
	else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
	update(k);
}
node ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return tr[k];
	int mid = (l + r) / 2;
	pushdown(k);
	node res;
	if (b <= mid) res = ask(LC, l, mid, a, b);
	else if (a > mid) res = ask(RC, mid + 1, r, a, b);
	else res = ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b);
	update(k);
	return res;
}
struct operation {
	int l, r, x;
}b[N];
LL ans[N];
int main() {
	IO;
	cin >> n >> m >> q;
	repn(i, 1, n) {
		cin >> a[i];
		a[i] = (a[i] + mod) % mod;
	}
	build(1, 1, n);
	repn(i, 1, m) {
		cin >> b[i].l >> b[i].r >> b[i].x;
		b[i].x = (b[i].x + mod) % mod;
	}
	repn(i, 1, q) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		if (x) f[x - 1].pb({l, r, -1, i});
		f[y].pb({l, r, 1, i});
	}
	// t = i + 1
	repn(i, 0, m) {
		LL t = i + 1;
		if (i) {
			LL s1 = 2 * b[i].x % mod;
			LL s2 = (LL)b[i].x * b[i].x % mod;
			LL c1 = 2 * (t - 1) * b[i].x % mod; c1 = (mod - c1) % mod;
			LL c2 = (t - 1) * b[i].x % mod * b[i].x % mod; c2 = (mod - c2) % mod;
			lazy cur = {mp(s1, s2), mp(c1, c2), b[i].x, 0};
			change(1, 1, n, b[i].l, b[i].r, cur);
		}
		for (auto p: f[i]) {
			int l = p.l, r = p.r, tp = p.tp, id = p.id;
			node res = ask(1, 1, n, l, r);
			LL val = (res.sumc + t * res.sum2) % mod;
			if (tp == 1) ans[id] = (ans[id] + val) % mod;
			else ans[id] = (ans[id] + mod - val) % mod;
		}
	}
	repn(i, 1, q) cout << ans[i] << "\n";
	return 0;
}