// Problem: Nim Cheater
// URL: https://codeforces.com/gym/103119/problem/I
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

const int N = 41000;
const int M = 16384;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, pos = 1;
int ans[N];
vector<int> g[N];
int dp[20][M], posa[N], posb[N], id[N], fa[N], sz[N], son[N];
void dfs1(int x) {
	sz[x] = 1;
	for (auto y: g[x]) {
		dfs1(y);
		if (sz[y] > sz[son[x]]) son[x] = y;
		sz[x] += sz[y];
	}
}
int tmp[M];
void add(int depth, int a, int b) {
	rep(i, 0, M) tmp[i] = min(dp[depth][i], dp[depth][i ^ a] + b);
	memcpy(dp[depth], tmp, sizeof(tmp));
}

void dfs2(int x, int depth, int sum) {
	if (x > 1) {
		add(depth, posa[x], posb[x]);
		ans[x] = dp[depth][sum];
	}
	for (auto y: g[x]) {
		if (y != son[x]) {
			memcpy(dp[depth + 1], dp[depth], sizeof(dp[depth]));
			dfs2(y, depth + 1, sum ^ posa[y]);
		}
	}
	if (son[x]) dfs2(son[x], depth, sum ^ posa[son[x]]);
}
int main()
{
	IO;
	cin >> n;
	int cur = 1;
	repn(i, 1, n) {
		string s;
		cin >> s;
		if (s == "ADD") {
			pos++;
			g[cur].pb(pos);
			cin >> posa[pos] >> posb[pos];
			fa[pos] = cur;
			cur = pos;
		}
		else cur = fa[cur];
		id[i] = cur;
	}
	dfs1(1);
	rep(i, 0, M) dp[0][i] = inf;
	dp[0][0] = 0;
	dfs2(1, 0, 0);
	repn(i, 1, n) cout << ans[id[i]] << "\n";
	return 0;
}