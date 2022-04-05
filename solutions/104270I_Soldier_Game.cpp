// Problem: Soldier Game
// URL: https://codeforces.com/gym/104270/problem/I
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

const int N = 410000;
const int M = 4100000;
const int mod = 1e9+7;
const int inf = 2 * (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, a[N], b[N];
LL ans, cur;
struct edge {
	int u, v, w;
	friend bool operator < (edge a, edge b) {
		return a.w < b.w;
	}
}e[N];
struct node {
	int l, r;
	LL a[2][2];
}tr[M];
void update(int k) {
	LL x = a[tr[LC].r], y = a[tr[RC].l];
	int lenl = tr[LC].r - tr[LC].l + 1, lenr = tr[RC].r - tr[RC].l + 1;
	rep(i, 0, 2) rep(j, 0, 2) tr[k].a[i][j] = INF;
	if (lenl == 1 && lenr == 1) {
		if (x >= cur && y >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], max(x, y));
		if (x + y >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], x + y);
		if (x >= cur) tr[k].a[0][1] = min(tr[k].a[0][1], x);
		if (y >= cur) tr[k].a[1][0] = min(tr[k].a[1][0], y);
		tr[k].a[1][1] = -INF;
	}
	else if (lenl == 1) {
		if (x >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], max(x, tr[RC].a[0][0]));
		if (x + y >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], max(x + y, tr[RC].a[1][0]));
		if (x >= cur) tr[k].a[0][1] = min(tr[k].a[0][1], max(x, tr[RC].a[0][1]));
		if (x + y >= cur) tr[k].a[0][1] = min(tr[k].a[0][1], max(x + y, tr[RC].a[1][1]));
		tr[k].a[1][0] = min(tr[k].a[1][0], tr[RC].a[0][0]);
		tr[k].a[1][1] = min(tr[k].a[1][1], tr[RC].a[0][1]);
	}
	else if (lenr == 1) {
		if (y >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], max(y, tr[LC].a[0][0]));
		if (x + y >= cur) tr[k].a[0][0] = min(tr[k].a[0][0], max(x + y, tr[LC].a[0][1]));
		if (y >= cur) tr[k].a[1][0] = min(tr[k].a[1][0], max(y, tr[LC].a[1][0]));
		if (x + y >= cur) tr[k].a[1][0] = min(tr[k].a[1][0], max(x + y, tr[LC].a[1][1]));
		tr[k].a[0][1] = min(tr[k].a[0][1], tr[LC].a[0][0]);
		tr[k].a[1][1] = min(tr[k].a[1][1], tr[LC].a[1][0]);
	}
	else {
		rep(l, 0, 2) rep(r, 0, 2) {
			tr[k].a[l][r] = max(tr[LC].a[l][0], tr[RC].a[0][r]);
			if (x + y >= cur) tr[k].a[l][r] = min(tr[k].a[l][r], max({tr[LC].a[l][1], tr[RC].a[1][r], x + y}));
		}
	}
}
	
void updatep(int k, int p) {
	tr[k].a[0][0] = tr[k].a[0][1] = tr[k].a[1][0] = INF;
	tr[k].a[1][1] = -INF;
	if (a[p] >= cur) tr[k].a[0][0] = a[p];
}
void build(int k, int l, int r) {
	tr[k].l = l, tr[k].r = r;
	if (l == r) {
		updatep(k, l);
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a) {
	if (l == r) {
		updatep(k, l);
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid) change(LC, l, mid, a);
	else change(RC, mid + 1, r, a);
	update(k);
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		m = 0;
		repn(i, 1, n) cin >> a[i], e[++m] = {i, i, a[i]};
		rep(i, 1, n) e[++m] = {i, i + 1, a[i] + a[i + 1]};
		sort(e + 1, e + m + 1);
		cur = -INF;
		ans = INF;
		build(1, 1, n);
		int head = 1;
		repn(i, 1, m) {
			cur = e[i].w;
			while (head <= m && e[head].w < cur) {
				change(1, 1, n, e[head].u), change(1, 1, n, e[head].v);
				head++;
			}
			ans = min(ans, tr[1].a[0][0] - cur);
		}
		cout << ans << "\n";
	}
	return 0;
}