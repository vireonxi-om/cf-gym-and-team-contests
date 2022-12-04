// Problem: Ship Traffic
// URL: https://codeforces.com/gym/447801/problem/I
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, w, u, v, t1, t2, cnt;
struct node {
	double t;
	int op;
	friend bool operator < (node a, node b) {
		if (a.t != b.t) return a.t < b.t;
		return a.op < b.op;
	}
}a[N];
int dir[N];
int main() {
	IO;
	cin >> n >> w >> u >> v >> t1 >> t2;
	double delta = (double)w / (double)v;
	repn(i, 1, n) {
		string s;
		cin >> s;
		if (s[0] == 'E') dir[i] = 1;
		else dir[i] = -1;
		int m;
		cin >> m;
		repn(j, 1, m) {
			int l, p;
			cin >> l >> p;
			if (p >= 0 && dir[i] == 1) {
				if (abs(p) >= l) continue;
				l -= abs(p), p = 0;
			}
			if (p <= 0 && dir[i] == -1) {
				if (abs(p) >= l) continue;
				l -= abs(p), p = 0;
			}
			double st = (double)abs(p) / (double)u - i * delta;
			double ed = (double)(abs(p) + l) / (double)u - (i - 1) * delta;
			if (ed < t1 + eps) continue;
			if (st > t2 + eps) continue;
			ed = min(ed, (double)t2), st = max(st, (double)t1);
			a[++cnt] = {st, 0}, a[++cnt] = {ed, 1};
		}
	}
	double last = t1, ans = 0;
	int num = 0;
	sort(a + 1, a + cnt + 1);
	repn(i, 1, cnt) {
		double t = a[i].t;
		int op = a[i].op;
		if (op == 0) {
			if (num == 0) ans = max(ans, t - last);
			num++;
			last = inf;
		}
		else {
			num--;
			if (num == 0) last = t;
		}
	}
	ans = max(ans, t2 - last);
	cout << fixed << setprecision(15) << ans << "\n";
	return 0;
}