// Problem: Balance of the Force
// URL: https://codeforces.com/gym/102055/problem/B
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
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, n, m, cnt, flag, num;
int pp[N], col[N], w[2][N], cp[2][N];
vector<int> g[N], tmp;
vector<PII> b;
PII a[2][N];
void dfs(int x, int v) {
	col[x] = v;
	pp[x] = 1;
	tmp.pb(x);
	for (auto y: g[x]) {
		if (pp[y]) {
			if (col[y] != (v ^ 1)) flag = 1;
		}
		else dfs(y, v ^ 1);
	}
}
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cnt++;
		flag = 0;
		cin >> n >> m;
		repn(i, 1, n) {
			g[i].clear();
			pp[i] = 0;
		}
		repn(i, 1, m) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}
		repn(i, 1, n)
			cin >> w[0][i] >> w[1][i];
		num = 0;
		b.clear();
		repn(i, 1, n) {
			if (!pp[i]) {
				tmp.clear();
				dfs(i, 0);
				num++;
				int mn = inf, mx = 0;
				for (auto x:tmp) {
					mn = min(mn, w[col[x]][x]);
					mx = max(mx, w[col[x]][x]);
				}
				a[0][num] = mp(mn, mx);
				b.pb(mp(mn, num));
				mn = inf, mx = 0;
				for (auto x:tmp) {
					mn = min(mn, w[col[x] ^ 1][x]);
					mx = max(mx, w[col[x] ^ 1][x]);
				}
				a[1][num] = mp(mn, mx);
				b.pb(mp(mn, num));
			}
		}
		if (flag) {
			cout << "Case " << cnt << ": IMPOSSIBLE\n";
			continue;
		}
		
		sort(all(b));
		int mx = 0, ans = 1e9, mn;
		repn(i, 1, num) {
			cp[0][i] = cp[1][i] = 0;
			mx = max(mx, min(a[0][i].se, a[1][i].se));
		}
		ans = mx - b[0].fi;
		mn = b[0].fi;
		for (auto p: b) {
			mn = p.fi;
			ans = min(ans, mx - mn);
			int idx = p.se;
			if (a[0][idx].fi == p.fi) cp[0][idx] = 1;
			if (a[1][idx].fi == p.fi) cp[1][idx] = 1;
			if (cp[0][idx] && cp[1][idx]) break;
			int cmx = inf;
			if (cp[0][idx] == 0) cmx = min(cmx, a[0][idx].se);
			if (cp[1][idx] == 0) cmx = min(cmx, a[1][idx].se);
			mx = max(mx, cmx);
		}
		cout << "Case " << cnt << ": " << ans << "\n";
	}	
	return 0;
}