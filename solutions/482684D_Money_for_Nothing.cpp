// Problem: Money for Nothing
// URL: https://codeforces.com/gym/482684/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
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
typedef pair<LL, LL> PLL;

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

int n, m, s, t;
PLL a[N], b[N], c[N], d[N];
LL ans;
void work(int l, int r, int al, int ar) {
	if (l > r || al > ar) return;
	int mid = (l + r) / 2;
	LL mx = -INF, pos = -1;
	repn(i, al, ar) {
		if (d[i].fi < c[mid].fi) continue;
		LL v = (d[i].fi - c[mid].fi) * (d[i].se - c[mid].se);
		if (v >= mx) mx = v, pos = i;
	}
	ans = max(ans, mx);
	if (pos == -1) work(l, mid - 1, al, ar);
	else {
		work(l, mid - 1, al, pos);
		work(mid + 1, r, pos, ar);
	}
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> a[i].fi >> a[i].se;
	repn(i, 1, m) cin >> b[i].fi >> b[i].se;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	repn(i, 1, n) {
		if (s == 0 || a[i].se < c[s].se) c[++s] = a[i];
	}
	pern(i, 1, m) {
		if (t == 0 || b[i].se > d[t].se) d[++t] = b[i];
	}
	reverse(d + 1, d + t + 1);
	work(1, s, 1, t);
	cout << ans << "\n";
	return 0;
}