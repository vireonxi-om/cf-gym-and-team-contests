// Problem: Jackdaws And Crows
// URL: https://codeforces.com/gym/102500/problem/J
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

const int N = 510000;
const int M = 2100000;
const int mod = 1e9+7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, rr, cc;
int a[N];
PII b[N];
struct Matrix {
	int n = 2;
	LL a[2][2];
	friend Matrix operator + (Matrix a, Matrix b) {
		Matrix res;
		rep(i, 0, 2) rep(j, 0, 2) res.a[i][j] = INF;
		rep(i, 0, 2) rep(j, 0, 2) {
			rep(k, 0, 2) {
				res.a[i][j] = min(res.a[i][j], a.a[i][k] + b.a[k][j]);
			}
		}
		return res;
	}
}tr[M];
void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void build(int k, int l, int r) {
	if (l == r) {
		if (a[l] == 0) tr[k].a[0][0] = rr, tr[k].a[0][1] = INF, tr[k].a[1][0] = INF, tr[k].a[1][1] = rr;
		else if (a[l] < 0) tr[k].a[0][0] = rr, tr[k].a[0][1] = INF, tr[k].a[1][0] = 0, tr[k].a[1][1] = rr;
		else tr[k].a[0][0] = rr, tr[k].a[0][1] = 0, tr[k].a[1][0] = INF, tr[k].a[1][1] = rr; 
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a) {
	if (l == r) {
		tr[k].a[1][0] = tr[k].a[0][1] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid) change(LC, l, mid, a);
	else change(RC, mid + 1, r, a);
	update(k);
}
LL ans = INF, cur;
int main() {
	IO;
	cin >> n >> cc >> rr;
	repn(i, 1, n) cin >> a[i], b[i] = mp(abs(a[i]) + 1, i);
	sort(b + 1, b + 1 + n);
	build(1, 1, n);
	rep(j, 0, 2) rep(k, 0, 2) {
		ans = min(ans, tr[1].a[j][k] + cur * (LL)cc);
	}
	repn(i, 1, n) {
		cur = b[i].fi;
		change(1, 1, n, b[i].se);
		rep(j, 0, 2) rep(k, 0, 2) {
			ans = min(ans, tr[1].a[j][k] + cur * (LL)cc);
		}
	}
	cout << ans << endl;
	return 0;
}