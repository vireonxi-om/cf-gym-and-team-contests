// Problem: Perfect Matching
// URL: https://codeforces.com/gym/104128/problem/J
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, cnt, a[N], sz[N], fat[N], pp[N], cp[N], posx[N], posy[N];
map<PII, int> S, SS;
vector<int> f[N], g[N];
int find(int x) {
	return fat[x] == x? x: fat[x] = find(fat[x]);
}
vector<PII> ans;
int tmp[N];
void dfs(int x, int fa) {
	cp[x] = 1;
	for (auto y: g[x]) {
		if (y != fa) dfs(y, x);
	}
	int sp = SS[mp(fa, x)];
	int tail = 0;
	if (!pp[sp]) tmp[tail++] = sp;
	for (auto y: f[x]) if (y != sp && !pp[y]) tmp[tail++] = y;
	int st = tail & 1;
	for (int i = st; i < tail; i += 2) {
		int s1 = tmp[i], s2 = tmp[i + 1];
		ans.pb(mp(s1, s2));
		pp[s1] = pp[s2] = 1;
	}
}
	
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		S.clear(), SS.clear();
		cnt = 0;
		repn(i, 1, n) {
			cin >> a[i];
			pp[i] = 0;
			int x = a[i] + i, y = a[i] - i;
			if (!S.count(mp(x, 0))) S[mp(x, 0)] = ++cnt, f[cnt].clear(), g[cnt].clear();
			if (!S.count(mp(y, 1))) S[mp(y, 1)] = ++cnt, f[cnt].clear(), g[cnt].clear();
			f[posx[i] = S[mp(x, 0)]].pb(i);
			f[posy[i] = S[mp(y, 1)]].pb(i);
		}
		repn(i, 1, cnt) {
			sz[i] = f[i].size();
			fat[i] = i;
			cp[i] = 0;
		}
		repn(i, 1, n) {
			int x = posx[i], y = posy[i];
			SS[mp(x, y)] = SS[mp(y, x)] = i;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				sz[fy] += sz[fx];
				fat[fx] = fy;
				g[x].pb(y), g[y].pb(x);
			}
		}
		int flag = 0;
		repn(i, 1, cnt) {
			if (find(i) == i && sz[i] % 4) flag = 1;
		}
		if (flag) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		ans.clear();
		repn(i, 1, cnt) {
			if (!cp[i]) dfs(i, 0);
		}
		for (auto p: ans) cout << p.fi << " " << p.se << "\n";
	}
	return 0;
}