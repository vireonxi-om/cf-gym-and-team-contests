// Problem: Keyboarding
// URL: https://codeforces.com/gym/447801/problem/F
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

const int N = 55;
const int M = 11000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, l, dis[N][N][M];
string s[N], t;
struct node {
	int x, y, k;
};
const int wayx[4] = {0, 0, 1, -1};
const int wayy[4] = {1, -1, 0, 0};
PII nxt[N][N][4];
char f[N][N];
queue<node> que;
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> s[i];
		repn(j, 1, m) f[i][j] = (s[i][j - 1]);
	}
	cin >> t;
	t += '*';
	l = t.size();
	repn(i, 1, n) repn(j, 1, m) repn(k, 0, l) dis[i][j][k] = inf;
	repn(i, 1, n) repn(j, 1, m) rep(k, 0, 4) {
		nxt[i][j][k] = mp(-1, -1);
		int nx = i, ny = j;
		while (1) {
			nx += wayx[k], ny += wayy[k];
			if (nx < 1 || nx > n || ny < 1 || ny > m) break;
			if (f[nx][ny] == f[i][j]) continue;
			nxt[i][j][k] = mp(nx, ny);
			break;
		}
	}
	
	dis[1][1][0] = 0;
	que.push({1, 1, 0});
	while (!que.empty()) {
		auto p = que.front(); que.pop();
		int x = p.x, y = p.y, k = p.k;
		rep(i, 0, 4) {
			int nx = nxt[x][y][i].fi, ny = nxt[x][y][i].se;
			if (nx == -1) continue;
			int nk = k;
			if (dis[nx][ny][nk] == inf) {
				dis[nx][ny][nk] = dis[x][y][k] + 1;
				que.push({nx, ny, nk});
			}
		}
		if (k < l && f[x][y] == t[k] && dis[x][y][k + 1] == inf) {
			dis[x][y][k + 1] = dis[x][y][k] + 1;
			que.push({x, y, k + 1});
		}
	}
	int ans = inf;
	repn(i, 1, n) repn(j, 1, m) ans = min(ans, dis[i][j][l]);
	cout << ans << "\n";
	return 0;
}