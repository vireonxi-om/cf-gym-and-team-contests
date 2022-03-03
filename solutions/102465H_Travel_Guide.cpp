// Problem: Travel Guide
// URL: https://codeforces.com/gym/102465/problem/H
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int dis[3][N], pp[N];
vector<PII> g[N];
priority_queue<pair<int, int> > que;
void dijkstra(int st) {
	rep(i, 0, n) dis[st][i] = inf, pp[i] = 0;
	dis[st][st] = 0;
	que.push({0, st});
	while (!que.empty()) {
		int now = que.top().se;
		que.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: g[now]) {
			int y = p.fi, w = p.se;
			if (dis[st][now] + w < dis[st][y]) {
				dis[st][y] = dis[st][now] + w;
				que.push({-dis[st][y], y});
			}
		}
	}
}
map<int, int> S;
int c[N], num;
int cur;
struct point {
	int d[3], id;
	friend bool operator < (point a, point b) {
		return a.d[cur] < b.d[cur];
	}
}p[N];
int ans[N], v[N];
inline int lowbit(int x) {
	return x & -x;
}
void add(int x, int y) {
	for (int i = x; i < N; i += lowbit(i)) v[i] += y;
}
int get(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += v[i];
	return res;
}
void work(int l, int r) {
	if (l == r) return;
	cur = 0;
	sort(p + l, p + r + 1);
	if (p[l].d[0] == p[r].d[0]) {
		cur = 1;
		sort(p + l, p + r + 1);
		int cl = l, cr = l;
		while (cl <= r) {
			while (cr < r && p[cr + 1].d[1] == p[cl].d[1]) cr++;
			repn(i, cl, cr) {
				int val = p[i].d[2];
				if (get(val) > 0) pp[p[i].id] = 1;
			}
			repn(i, cl, cr) {
				int val = p[i].d[2];
				add(val, 1);
			}
			repn(i, cl, cr) {
				int val = p[i].d[2];
				if (get(val - 1) > 0) pp[p[i].id] = 1;
			}
			cl = cr + 1;
		}
		repn(i, l, r) {
			int val = p[i].d[2];
			add(val, -1);
		}
		return;
	}
	int pos = (l + r) / 2, cx;
	int cpos = pos;
	if (p[pos].d[0] != p[r].d[0]) {
		while (p[pos + 1].d[0] == p[cpos].d[0]) pos++;
		cx = p[pos].d[0];
	}
	else {
		while (p[pos].d[0] == p[cpos].d[0]) pos--;
		cx = p[pos].d[0];
	}
	work(l, pos);
	work(pos + 1, r);
	cur = 1;
	sort(p + l, p + r + 1);
	int cl = l, cr = l;
	while (cl <= r) {
		while (cr < r && p[cr + 1].d[1] == p[cl].d[1]) cr++;
		repn(i, cl, cr) {
			int val = p[i].d[2];
			if (p[i].d[0] > cx) continue;
			add(val, 1);
		}
		repn(i, cl, cr) {
			int val = p[i].d[2];
			if (p[i].d[0] <= cx) continue;
			if (get(val) > 0) pp[p[i].id] = 1;
		}
		cl = cr + 1;
	}
	repn(i, l, r) {
		int val = p[i].d[2];
		if (p[i].d[0] > cx) continue;
		add(val, -1);
	}
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	dijkstra(0), dijkstra(1), dijkstra(2);
	rep(d, 0, 3) {
		rep(i, 0, n) c[i] = dis[d][i];
		sort(c, c + n);
		S[c[0]] = num = 1;
		rep(i, 1, n) if (c[i] != c[i - 1]) S[c[i]] = ++num;
		rep(i, 0, n) p[i].d[d] = S[dis[d][i]];
	}
	memset(pp, 0, sizeof(pp));
	rep(i, 0, n) p[i].id = i;
	work(0, n - 1);
	int ans = 0;
	rep(i, 0, n) if (!pp[i]) ans++;
	cout << ans << endl;
	return 0;
}