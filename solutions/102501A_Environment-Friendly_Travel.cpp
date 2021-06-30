// Problem: Environment-Friendly Travel
// URL: https://codeforces.com/gym/102501/problem/A
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int num, c[N], st, ed, sx, sy, ex, ey, B;
int x[N], y[N];
int dis[N][110];
struct node {
	int id, b, dis;
	friend bool operator < (node a, node b) {
		return a.dis > b.dis;
	}
};
vector<PII> g[N];
int ans, pp[N][110];
int sqr(int x) {
	return x * x;
}
int cal(int x1, int y1, int x2, int y2) {
	int res = ceil(sqrt(sqr(x1 - x2) + sqr(y1 - y2)) - eps);
	return res;
}
priority_queue<node> q;
int main() {
	IO;
	cin >> sx >> sy;
	cin >> ex >> ey;
	cin >> B;
	cin >> c[0];
	cin >> m;
	repn(i, 1, m) cin >> c[i];
	cin >> n;
	rep(i, 0, n) {
		cin >> x[i] >> y[i];
		int k;
		cin >> k;
		while (k--) {
			int dst, tp;
			cin >> dst >> tp;
			g[i].pb(mp(dst, tp));
			g[dst].pb(mp(i, tp));
		}
	}
	repn(i, 0, n) repn(j, 0, B) dis[i][j] = inf;
	if (cal(sx, sy, ex, ey) <= B) ans = c[0] * cal(sx, sy, ex, ey);
	else ans = inf;
	rep(i, 0, n) {
		int d = cal(sx, sy, x[i], y[i]);
		if (d <= B) {
			dis[i][d] = d * c[0];
			q.push((node){i, d, dis[i][d]});
		}
	}
	while (!q.empty()) {
		auto now = q.top();
		int xx = now.id, b = now.b;
		q.pop();
		if (pp[xx][b]) continue;
		pp[xx][b] = 1;
		int nd = cal(x[xx], y[xx], ex, ey);
		if (nd + b <= B) ans = min(ans, dis[xx][b] + nd * c[0]);
		for (auto p: g[xx]) {
			int yy = p.fi, tp = p.se;
			int d = cal(x[xx], y[xx], x[yy], y[yy]);
			if (d + b <= B && dis[xx][b] + d * c[tp] < dis[yy][d + b]) {
				dis[yy][d + b] = dis[xx][b] + d * c[tp];
				q.push((node){yy, d + b, dis[yy][d + b]});
			}
		}
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}