// Problem: Dessert Café
// URL: https://codeforces.com/gym/102920/problem/C
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, k;
vector<int> g[N];
int num[N], ans, pp[N], nu[N];
void dfs(int x, int fa) {
	for (auto y: g[x]) {
		if (y != fa) dfs(y, x), num[x] += num[y], nu[x] += (num[y] > 0);
	}
}
void dfs2(int x, int fa, int z) {
	if (pp[x] || (nu[x] + (z > 0)) >= 2) ans++;
	for (auto y: g[x]) {
		if (y != fa) {
			int nz = z | ((num[x] - num[y]) > 0);
			dfs2(y, x, nz);
		}
	}
}
int main()
{
	IO;
	cin >> n >> k;
	rep(i, 1, n) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(y), g[y].pb(x);
	}
	repn(i, 1, k) {
		int x;
		cin >> x;
		num[x] = 1, nu[x] = 1, pp[x] = 1;
	}
	dfs(1, 0);
	dfs2(1, 0, 0);
	cout << ans << endl;
	return 0;
}