// Problem: Catch You Catch Me
// URL: https://codeforces.com/gym/104065/problem/C
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

int n, mx[N];
vector<int> g[N];
void dfs(int x, int fa) {
	for (auto y: g[x]) {
		if (y != fa) {
			dfs(y, x);
			mx[x] = max(mx[x], mx[y]);
		}
	}
	mx[x] += 1;
}
int main() {
	IO;
	cin >> n;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1, 0);
	int ans = 0;
	for (auto y: g[1]) ans += mx[y];
	cout << ans << "\n";
	return 0;
}