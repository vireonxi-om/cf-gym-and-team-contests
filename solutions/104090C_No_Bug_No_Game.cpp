// Problem: No Bug No Game
// URL: https://codeforces.com/gym/104090/problem/C
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

const int N = 3100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand


int n, k, dp[N][N][10], p, w[N], ans;
int main() {
	IO;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	dp[1][0][0] = 0;
	repn(i, 1, n) {
		cin >> p;
		repn(j, 1, p) cin >> w[j];
		pern(j, 0, k) {
			rep(l, 0, 10) dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
			if (j + p <= k) {
				rep(l, 0, 10) if (dp[i][j][l] != -1) dp[i + 1][j + p][l] = max(dp[i + 1][j + p][l], dp[i][j][l] + w[p]);
			}
			rep(l, 1, p) {
				if (j + l > k) break;
				if (dp[i][j][0] != -1) dp[i + 1][j + l][l] = max(dp[i + 1][j + l][l], dp[i][j][0] + w[l]);
			}
		}
	}
	repn(i, 1, k) rep(j, 0, 10) if (j == 0 || i == k) ans = max(ans, dp[n + 1][i][j]);
	cout << ans << "\n";
	return 0;
}