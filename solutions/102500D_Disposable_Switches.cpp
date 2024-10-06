// Problem: Disposable Switches
// URL: https://codeforces.com/gym/102500/problem/D
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

const int N = 2100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m;
vector<PII> g[N];
LL dis[N][N];
int pp[N][N], cp[N], dp[N], num[N];
vector<int> ans;
queue<int> que;
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	repn(i, 1, n) repn(j, 0, n) dis[i][j] = INF;
	dis[1][0] = 0;
	rep(i, 0, n) {
		repn(j, 1, n) {
			for (auto p: g[j]) {
				int y = p.fi, w = p.se;
				dis[y][i + 1] = min(dis[y][i + 1], dis[j][i] + w);
			}
		}
	}
	repn(i, 1, n) {
		if (dis[n][i] == INF) continue;
		double mn = 0, mx = INF;
		repn(j, 1, i - 1) {
			mx = min(mx, (double)(dis[n][j] - dis[n][i]) / (i - j));
		}
		repn(j, i + 1, n) {
			mn = max(mn, (double)(dis[n][i] - dis[n][j]) / (j - i));
		}
		if (mn > mx + eps) continue;
		memset(dp, 0, sizeof(dp));
		dp[n] = 1, num[n] = i;
		que.push(n);
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			LL mn = INF;
			for (auto p: g[x]) {
				int y = p.fi, w = p.se;
				if (num[x] >= 1) mn = min(mn, dis[y][num[x] - 1] + w);
			}
			for (auto p: g[x]) {
				int y = p.fi, w = p.se;
				if (num[x] >= 1 && dis[y][num[x] - 1] + w == mn) {
					if (!dp[y]) que.push(y), num[y] = num[x] - 1;
					dp[y] = 1;
				}
			}
		}
		repn(j, 1, n) if (dp[j]) cp[j] = 1;
	}
	repn(i, 1, n) if (!cp[i]) ans.pb(i);
	cout << ans.size() << "\n";
	rep(i, 0, ans.size()) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << " ";
		else cout << "\n";
	}
	return 0;
}