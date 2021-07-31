// Problem: Ban or Pick, What's the Trick
// URL: https://codeforces.com/gym/104065/problem/A
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, k, a[N], b[N];
int pp[N][11][11][2], dp[N][11][11][2];
int dfs(int depth, int x, int y, int st) {
	if (pp[depth][x][y][st]) return dp[depth][x][y][st];
	pp[depth][x][y][st] = 1;
	if (depth == n + 1) return dp[depth][x][y][st] = 0;
	if (st == 0) {
		int apos = 1 + k - x + (depth - 1) - (k - y);
		int bpos = 1 + k - y + (depth - 1) - (k - x);
		int res = -inf;
		if (apos <= n && x) res = max(res, dfs(depth, x - 1, y, 1) + a[apos]);
		if (bpos <= n) res = max(res, dfs(depth, x, y, 1));
		return dp[depth][x][y][st] = res;
	}
	else {
		int apos = 1 + k - x + (depth - 1) - (k - y);
		int bpos = 1 + k - y + (depth) - (k - x);
		int res = inf;
		if (bpos <= n && y) res = min(res, dfs(depth + 1, x, y - 1, 0) - b[bpos]);
		if (apos <= n) res = min(res, dfs(depth + 1, x, y, 0));
		return dp[depth][x][y][st] = res;
	}
	
}
int main() {
	IO;
	cin >> n >> k;
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) cin >> b[i];
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	sort(b + 1, b + n + 1), reverse(b + 1, b + n + 1);
	cout << dfs(1, k, k, 0) << "\n";
	return 0;
}