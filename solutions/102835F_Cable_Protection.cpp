// Problem: Cable Protection
// URL: https://codeforces.com/gym/102835/problem/F
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int st1, st2;
vector<int> g[N];
int ans;
int dp[N][2];
void dfs(int x, int fa) {
	dp[x][1] = 1, dp[x][0] = 0;
	for (auto y: g[x]) {
		if (y != fa) {
			dfs(y, x);
			dp[x][1] += min(dp[y][0], dp[y][1]);
			dp[x][0] += dp[y][1];
		}
	}
}
int main()
{
	IO;
	cin >> n >> m;
	int flag = 0;
	repn(i, 1, n) {
		int x, y;
		cin >> x >> y;
		x++, y++;
		if (!flag && x <= n && y <= n) flag = 1, st1 = x, st2 =  y;
		else g[x].pb(y), g[y].pb(x);
	}
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		x++, y++;
		g[x].pb(y), g[y].pb(x);
	}
	ans = n + m;
	dfs(st1, 0);
	ans = min(ans, dp[st1][1]);
	dfs(st2, 0);
	ans = min(ans, dp[st2][1]);
	cout << ans << endl;
	return 0;
}