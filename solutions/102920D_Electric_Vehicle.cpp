// Problem: Electric Vehicle
// URL: https://codeforces.com/gym/102920/problem/D
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
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n;
int a[N], b[N], c[N];
LL w, num;
LL d[N][N], cost[N][N];
vector<int> g[N];
LL dp1[11][N], dp2[11][N];
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i] >> b[i] >> c[i];
	cin >> w >> num;
	repn(i, 1, n) repn(j, 1, n) {
		d[i][j] = abs(a[i] - a[j]) + abs(b[i] - b[j]);
		if (d[i][j] <= w) g[i].pb(j);
	}
	repn(i, 1, n) repn(j, 1, n) cost[i][j] = INF;
	repn(i, 1, n) repn(j, 1, n) if (d[i][j] > w && d[i][j] <= 2 * w)  {
		for (auto x: g[i]) {
			if (d[x][j] <= w) cost[i][j] = min(cost[i][j], (LL)c[x] * (d[i][x] + d[x][j] - w));
		}
	}
	repn(i, 0, num) repn(j, 1, n) dp1[i][j] = dp2[i][j] = INF;
	dp1[0][1] = 0;
	rep(i, 0, num) repn(j, 1, n) {
		dp2[i + 1][j] = min(dp2[i + 1][j], dp1[i][j] + w * c[j]);
		repn(k, 1, n) {
			if (d[j][k] <= w) {
				dp1[i + 1][k] = min(dp1[i + 1][k], dp1[i][j] + d[j][k] * c[j]);
				dp2[i + 1][k] = min(dp2[i + 1][k], dp2[i][j] + d[j][k] * c[k]);
			}
			dp1[i + 1][k] = min(dp1[i + 1][k], dp2[i][j] + cost[j][k]);
		}
	}
	LL ans = INF;
	repn(i, 0, num) ans = min(ans, dp1[i][2]);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}