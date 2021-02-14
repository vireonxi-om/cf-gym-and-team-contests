// Problem: Height Profile
// URL: https://codeforces.com/gym/102500/problem/H
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<double, int> PID;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const int INF = 1e8;
const double eps = 1e-9;

int n, k, a[N];
double x, xie[N];
PID mx[M], mn[M];
void update(int k) {
	mx[k] = max(mx[LC], mx[RC]);
	mn[k] = min(mn[LC], mn[RC]);
}
void build(int k, int l, int r) {
	if (l == r) {
		mx[k] = mn[k] = mp(a[l] - l * x, l);
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
PID ask(int k, int l, int r, int a, int b, double cur, int tp) {
	if (l == r) return mx[k];
	if (tp == 0) {
		if (mx[k].fi < cur - eps) return mx[k];
	}
	else {
		if (mn[k].fi > cur + eps) return mn[k];
	}
	if (l == a && r == b) {
		int mid = (l + r) / 2;
		if (tp == 0) {
			if (mx[RC].fi > cur - eps) return ask(RC, mid + 1, r, mid + 1, b, cur, tp);
			else return ask(LC, l, mid, a, mid, cur, tp);
		}
		else {
			if (mn[LC].fi < cur + eps) return ask(LC, l, mid, l, mid, cur, tp);
			else return ask(RC, mid + 1, r, mid + 1, b, cur, tp);
		}
	}
	int mid = (l + r) / 2;
	if (b <= mid) return ask(LC, l, mid, a, b, cur, tp);
	else if (a > mid) return ask(RC, mid + 1, r, a, b, cur, tp);
	else {
		if (tp == 0) {
			PID res = ask(RC, mid + 1, r, mid + 1, b, cur, tp);
			if (res.fi < cur - eps) return ask(LC, l, mid, a, mid, cur, tp);
			else return res;
		}
		else {
			PID res = ask(LC, l, mid, a, mid, cur, tp);
			if (res.fi > cur + eps) return ask(RC, mid + 1, r, mid + 1, b, cur, tp);
			else return res;
		}
	}
}
int main() {
	IO;
	cin >> n >> k;
	repn(i, 0, n) {
		cin >> a[i];
		if (i) xie[i] = (double)(a[i] - a[i - 1]);
	}
	while (k--) {
		cin >> x;
		x = x * 10;
		double ans = -1;
		build(1, 0, n);
		repn(i, 0, n - 1) {
			double cur = a[i] - x * i;
			PID res = ask(1, 0, n, i + 1, n, cur, 0);
			if (res.fi < cur - eps) continue;
			ans = max(ans, (double)res.se - i);
			if (i == 0) continue;
			double l = i - 1, r = i;
			rep(j, 0, 100) {
				double mid = (l + r) / 2;
				double nx = mid, ny = a[i] - (i - mid) * xie[i];
				double val = ny - nx * x;
				if (val < res.fi + eps) ans = max(ans, res.se - nx), r = mid;
				else l = mid;
			}
		}
		repn(i, 1, n) {
			double cur = a[i] - x * i;
			PID res = ask(1, 0, n, 0, i - 1, cur, 1);
			if (res.fi > cur + eps) continue;
			ans = max(ans, (double)i - res.se);
			if (i == n) continue;
			double l = i, r = i + 1;
			rep(j, 0, 100) {
				double mid = (l + r) / 2;
				double nx = mid, ny = a[i] + (mid - i) * xie[i + 1];
				double val = ny - nx * x;
				if (val > res.fi - eps) ans = max(ans, nx - res.se), l = mid;
				else r = mid;
			}
		}
		if (ans < 0) printf("-1\n");
		else printf("%.10f\n", ans);
	}
	return 0;
}