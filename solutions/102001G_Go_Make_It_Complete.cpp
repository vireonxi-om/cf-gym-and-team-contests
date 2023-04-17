// Problem: Go Make It Complete
// URL: https://codeforces.com/gym/102001/problem/G
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

const int N = 510;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int g[N][N];
int du[N], pp[N];
queue<int> que;
int ans = inf;
int find() {
	int mx = -1;
	repn(i, 1, n)
		repn(j, i + 1, n)
			if (g[i][j] == 0) mx = max(mx, du[i] + du[j]);
	return mx;
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = 1;
		du[x]++, du[y]++;
	}
	while (1) {
		int mx = find();
		if (mx == -1) break;
		ans = min(ans, mx);
		repn(i, 1, n) repn(j, i + 1, n) {
			if (g[i][j] == 0 && du[i] + du[j] >= ans) {
				if (!pp[i]) que.push(i), pp[i] = 1;
				if (!pp[j]) que.push(j), pp[j] = 1;
			}
		}
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			pp[now] = 0;
			repn(i, 1, n) {
				if (i != now && g[now][i] == 0 && du[now] + du[i] >= ans) {
					du[now]++;
					du[i]++;
					g[now][i] = g[i][now] = 1;
					if (!pp[now]) que.push(now), pp[now] = 1;
					if (!pp[i]) que.push(i), pp[i] = 1;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}