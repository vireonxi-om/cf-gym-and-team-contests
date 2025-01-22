// Problem: Boomerangs
// URL: https://codeforces.com/gym/102001/problem/K
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

const int N = 310000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, pp[N];
vector<int> g[N];
struct node {
	int x, y, z;
};
vector<node> ans;
int dfn[N];
set<int> S[N];
void dfs(int x, int fa) {
	pp[x] = 1;
	dfn[x] = dfn[fa] + 1;
	for (auto y: g[x]) {
		if (y == fa) continue;
		if (pp[y]) {
			if (dfn[y] > dfn[x]) continue;
			S[x].insert(y);
		}
		else S[x].insert(y), dfs(y, x);
	}
	auto it = S[x].begin();
	int flag = 0;
	if (S[x].size() % 2 == 1) it++, flag = 1;
	while (it != S[x].end()) {
		int tx = (*it);
		it++;
		int tz = (*it);
		it++;
		int ty = x;
		ans.pb((node){tx, ty, tz});
	}
	if (flag && fa > 0) {
		ans.pb((node){*(S[x].begin()), x, fa});
		S[fa].erase(x);
	}
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y), g[y].pb(x);
	}
	repn(i, 1, n) if (!pp[i]) dfs(i, 0);
	cout << ans.size() << "\n";
	for (auto p: ans) {
		cout << p.x << " " << p.y << " " << p.z << "\n";
	}
	return 0;
}