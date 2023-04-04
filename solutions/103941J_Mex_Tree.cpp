// Problem: Mex Tree
// URL: https://codeforces.com/gym/103941/problem/J
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
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, v[N], pos[N], pp[N], head;
vector<int> g[N];
int fat[N], sz[N];
void dfs(int x, int fa) {
	fat[x] = fa;
	sz[x] = 1;
	for (auto y: g[x]) {
		if (y != fa) {
			dfs(y, x);
			sz[x] += sz[y];
		}
	}
}
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> v[i];
		pos[v[i]] = i;
	}
	repn(i, 2, n) {
		int x;
		cin >> x;
		g[x].pb(i);
		g[i].pb(x);
	}
	dfs(pos[0], 0);
	int mx = 0;
	for (auto y: g[pos[0]]) mx = max(mx, sz[y]);
	cout << mx;
	head = 0;
	repn(i, 1, n) {
		int cur = pos[i - 1];
		while (cur && !pp[v[cur]]) {
			pp[v[cur]] = 1;
			cur = fat[cur];
		}
		while (pp[head]) head++;
		if (head == i) cout << " " << n - sz[pos[i]];
		else cout << " 0";
	}
	cout << "\n";
	return 0;
}