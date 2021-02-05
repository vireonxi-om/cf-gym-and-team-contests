// Problem: Crystal Crosswind
// URL: https://codeforces.com/gym/468812/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, k;
int f[N][N], g[N][N], h[N][N], b[N][N][11];
int ax[N], ay[N];
queue<PII> que;
int main() {
	IO;
	cin >> m >> n >> k;
	repn(i, 1, n) repn(j, 1, m) g[i][j] = 1;
	repn(i, 1, k) {
		int wx, wy, num;
		cin >> wy >> wx >> num;
		ax[i] = wx, ay[i] = wy;
		repn(j, 1, n) repn(l, 1, m) h[j][l] = 0;
		while (num --) {
			int x, y;
			cin >> y >> x;
			f[x][y] = 1;
			b[x][y][i] = 1;
			h[x][y] = 1;
		}
		if (wx >= 0 && wy >= 0) {
			repn(j, 1, n) repn(l, 1, m) {
				if (h[j][l]) continue;
				int nj = j - wx, nl = l - wy;
				if (nj < 1 || nj > n || nl < 1 || nl > m) continue;
				int nnj = j + wx, nnl = l + wy;
				if (h[nj][nl]) {
					if (nnj < 1 || nnj > n || nnl < 1 || nnl > m) h[j][l] = 1;
					else if (!h[nnj][nnl]) h[j][l] = 1;
				}
			}
		}
		else if (wx >=0 && wy < 0) {
			repn(j, 1, n) pern(l, 1, m) {
				if (h[j][l]) continue;
				int nj = j - wx, nl = l - wy;
				if (nj < 1 || nj > n || nl < 1 || nl > m) continue;
				int nnj = j + wx, nnl = l + wy;
				if (h[nj][nl]) {
					if (nnj < 1 || nnj > n || nnl < 1 || nnl > m) h[j][l] = 1;
					else if (!h[nnj][nnl]) h[j][l] = 1;
				}
			}
		}
		else if (wx < 0 && wy >= 0) {
			pern(j, 1, n) repn(l, 1, m) {
				if (h[j][l]) continue;
				int nj = j - wx, nl = l - wy;
				if (nj < 1 || nj > n || nl < 1 || nl > m) continue;
				int nnj = j + wx, nnl = l + wy;
				if (h[nj][nl]) {
					if (nnj < 1 || nnj > n || nnl < 1 || nnl > m) h[j][l] = 1;
					else if (!h[nnj][nnl]) h[j][l] = 1;
				}
			}
		}
		else { // wx < 0 && wy < 0
			pern(j, 1, n) pern(l, 1, m) {
				if (h[j][l]) continue;
				int nj = j - wx, nl = l - wy;
				if (nj < 1 || nj > n || nl < 1 || nl > m) continue;
				int nnj = j + wx, nnl = l + wy;
				if (h[nj][nl]) {
					if (nnj < 1 || nnj > n || nnl < 1 || nnl > m) h[j][l] = 1;
					else if (!h[nnj][nnl]) h[j][l] = 1;
				}
			}
		}
		repn(j, 1, n) repn(l, 1, m) if (h[j][l] == 0) g[j][l] = 0;
	}
	repn(i, 1, n) repn(j, 1, m) if (f[i][j]) que.push(mp(i, j));
	while (!que.empty()) {
		PII now = que.front();
		que.pop();
		int x = now.fi, y = now.se;
		repn(i, 1, k) {
			if (b[x][y][i]) continue;
			int wx = ax[i], wy = ay[i];
			int nx = x - wx, ny = y - wy;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (!f[nx][ny]) {
				f[nx][ny] = 1;
				que.push(mp(nx, ny));
			}
			
		}
	}
	repn(i, 1, n) repn(j, 1, m) if (!g[i][j]) que.push(mp(i, j));
	while (!que.empty()) {
		PII now = que.front();
		que.pop();
		int x = now.fi, y = now.se;
		repn(i, 1, k) {
			int wx = ax[i], wy = ay[i];
			int nx = x + wx, ny = y + wy;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (b[nx][ny][i]) continue;
			if (g[nx][ny]) {
				g[nx][ny] = 0;
				que.push(mp(nx, ny));
			}
			
		}
	}
		
	repn(i, 1, n) {
		repn(j, 1, m) {
			if (f[i][j]) cout << '#';
			else cout << '.';
		}
		cout << "\n";
	}
	cout << "\n";
	repn(i, 1, n) {
		repn(j, 1, m) {
			if (!g[i][j]) assert(!f[i][j]);
			if (g[i][j]) cout << '#';
			else cout << '.';
		}
		cout << "\n";
	}
	return 0;
}