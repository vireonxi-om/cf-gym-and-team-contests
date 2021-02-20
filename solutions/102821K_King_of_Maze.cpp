// Problem: King of Maze
// URL: https://codeforces.com/gym/102821/problem/K
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

const int N = 55;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, cas, n, m, q, nu;
string s;
PII f[N];
int a[N][N], dis[N][N], flag[N][N], ex, ey;
vector<PII> g[N][N];
queue<PII> que;
const int wayx[4] = {-1, 1, 0, 0};
const int wayy[4] = {0, 0, -1, 1};
int way[N][N][5], pp[N][N], dp[N][N];
int check(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	return 1;
}
void bfs() {
	memset(dis, -1, sizeof(dis));
	dis[ex][ey] = 0;
	que.push(mp(ex, ey));
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		int x = now.fi, y = now.se;
		rep(i, 0, 4) {
			int nx = x + wayx[i];
			int ny = y + wayy[i];
			if (!check(nx, ny)) continue;
			if (a[nx][ny]) continue;
			if (dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[x][y] + 1;
			que.push(mp(nx, ny));
		}
	}
	repn(i, 1, n) {
		repn(j, 1, m) {
			if (dis[i][j] == -1 && a[i][j] != 2) way[i][j][4] = 1;
			else if (dis[i][j] != -1) {
				rep(k, 0, 4) {
					int nx = i + wayx[k];
					int ny = j + wayy[k];
					if (check(nx, ny) && dis[nx][ny] + 1 == dis[i][j]) {
						way[i][j][k] = 1;
						break;
					}
				}
			}
		}
	}
}
int cal(int x, int y) {
	if (x == ex && y == ey) return 0;
	if (pp[x][y]) return dp[x][y] = inf;
	if (way[x][y][4]) return inf;
	if (dp[x][y] != -1) return dp[x][y];
	pp[x][y] = 1;
	int res = 0;
	rep(i, 0, 4) {
		int nx = x + wayx[i], ny = y + wayy[i];
		if (!check(nx, ny)) continue;
		if (!way[x][y][i]) continue;
		res = max(res, min(cal(nx, ny) + 1, inf));
	}
	pp[x][y] = 0;
	return dp[x][y] = res;
}
		
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m >> q;
		nu = 0;
		repn(i, 1, n) {
			cin >> s;
			rep(j, 0, m) {
				if (s[j] == '.') a[i][j + 1] = 0;
				else if (s[j] == '#') a[i][j + 1] = 1;
				else if (s[j] == 'E') a[i][j + 1] = 0, ex = i, ey = j + 1;
				else if (s[j] == '?') f[nu++] = mp(i, j + 1);
			}
		}
		repn(i, 1, n) {
			repn(j, 1, m) {
				g[i][j].clear();
				rep(k, 0, 5) way[i][j][k] = 0;
			}
		}
		rep(i, 0, 1 << nu) {
			rep(j, 0, nu) {
				int x = f[j].fi, y = f[j].se;
				if ((i >> j) & 1) a[x][y] = 2;
				else a[x][y] = 0;
			}
			bfs();
		}
		memset(dp, -1, sizeof(dp));
		cout << "Case " << ++cas << ":\n";
		while (q--) {
			int x, y;
			cin >> x >> y;
			repn(i, 1, n) repn(j, 1, m) pp[i][j] = 0;
			int res = cal(x, y);
			if (res == inf) cout << "-1\n";
			else cout << res << "\n";
		}
	}
	return 0;
}