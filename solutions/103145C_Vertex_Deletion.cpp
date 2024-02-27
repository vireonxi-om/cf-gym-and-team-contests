// Problem: Vertex Deletion
// URL: https://codeforces.com/gym/103145/problem/C
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

const int N = 110000;
const int M = 1100000;
const LL mod = 998244353;
const int inf = (int)998244353;
const double eps = 1e-9;

int T, n;
vector<int> g[N];
LL dp[3][N]; // 0 - destroy  1 - exist & no edge  2 - exist & edge

void dfs(int x, int fa) {
	dp[0][x] = 1;
	dp[1][x] = 1;
	dp[2][x] = 0;
	for (auto y: g[x]) {
		if (y != fa) {
			dfs(y, x);
			LL tmp0 = 0, tmp1 = 0, tmp2 = 0;
			// destroy
			tmp0 = dp[0][x] * (dp[0][y] + dp[2][y]) % mod;
			// exist
			tmp1 = dp[1][x] * dp[0][y] % mod;
			// edge
			tmp2 = (dp[1][x] * (dp[1][y] + dp[2][y]) + dp[2][x] * (dp[0][y] + dp[1][y] + dp[2][y])) % mod;
			dp[0][x] = tmp0;
			dp[1][x] = tmp1;
			dp[2][x] = tmp2;
		}
	}
}
int main()
{
	IO;
	cin >> T;
	while (T--) { 
		cin >> n;
		repn(i, 1, n) g[i].clear();
		rep(i, 1, n) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y), g[y].pb(x);
		}
		dfs(1, 0);
		cout << (dp[0][1] + dp[2][1]) % mod << "\n";
	}
	return 0;
}