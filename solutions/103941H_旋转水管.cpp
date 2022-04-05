// Problem: 旋转水管
// URL: https://codeforces.com/gym/103941/problem/H
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
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, m, x, y;
int f[4][N], pp[4][N][4];
const int wayx[4] = {0, 0, 1, -1};
const int wayy[4] = {1, -1, 0, 0};
struct node {
	int x, y, dir;
};
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> m >> x >> y;
		rep(i, 0, 4) repn(j, 0, m + 1) f[i][j] = pp[i][j][0] = pp[i][j][1] = pp[i][j][2] = pp[i][j][3] = 0;
		f[0][x] = 1, f[3][y] = 1;
		string s;
		cin >> s;
		rep(i, 0, m) if (s[i] == 'I') f[1][i + 1] = 2;
		else f[1][i + 1] = 3;
		cin >> s;
		rep(i, 0, m) if (s[i] == 'I') f[2][i + 1] = 2;
		else f[2][i + 1] = 3;
		queue<node> que;
		pp[1][x][2] = 1;
		que.push({1, x, 2});
		int sx = x, ey = y;
		while (!que.empty()) {
			auto p = que.front(); que.pop();
			int x = p.x, y = p.y, dir = p.dir;
			if (f[x][y] == 2) {
				int pdir;
				if (x == 1 && y == sx) pdir = 1;
				else if (x == 2 && y == ey) pdir = 1;
				else pdir = 0;
				if (pdir == 1) {
					if (dir == 0 || dir == 1) continue;
				}
				else {
					if (dir == 2 || dir == 3) continue;
				}
				int ndir = dir, nx = x + wayx[ndir], ny = y + wayy[ndir];
				if (f[nx][ny] && !pp[nx][ny][ndir]) {
					pp[nx][ny][ndir] = 1;
					que.push({nx, ny, ndir});
				}
			}
			if (f[x][y] == 3) {
				if (dir == 0 || dir == 1) {
					int ndir = 2, nx = x + wayx[ndir], ny = y + wayy[ndir];
					if (f[nx][ny] && !pp[nx][ny][ndir]) {
						pp[nx][ny][ndir] = 1;
						que.push({nx, ny, ndir});
					}
					ndir = 3, nx = x + wayx[ndir], ny = y + wayy[ndir];
					if (f[nx][ny] && !pp[nx][ny][ndir]) {
						pp[nx][ny][ndir] = 1;
						que.push({nx, ny, ndir});
					}
				}
				else {
					int ndir = 0, nx = x + wayx[ndir], ny = y + wayy[ndir];
					if (f[nx][ny] && !pp[nx][ny][ndir]) {
						pp[nx][ny][ndir] = 1;
						que.push({nx, ny, ndir});
					}
					ndir = 1, nx = x + wayx[ndir], ny = y + wayy[ndir];
					if (f[nx][ny] && !pp[nx][ny][ndir]) {
						pp[nx][ny][ndir] = 1;
						que.push({nx, ny, ndir});
					}
				}
			}
		}
		if (pp[3][y][2]) cout << "YES\n";
		else cout << "NO\n";
	}		
	return 0;
}