// Problem: 复合函数
// URL: https://codeforces.com/gym/103941/problem/K
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;
int n, m, q, f[N], idx[N], pp[N], len[N], dis[N], instack[N];
int st[N], tail;
struct query {
	LL a, b;
	int id;
	friend bool operator < (query a, query b) {
		return min(a.a, a.b) < min(b.a, b.b);
	}
}a[N];
vector<int> g[N];
int head[N];
void dfs(int x) {
	instack[x] = 1;
	st[++tail] = x;
	int y = f[x];
	if (pp[y]) {
		dis[x] = dis[y] + 1;
		len[x] = len[y];
	}
	else if (instack[y]) {
		int now = tail;
		while (1) {
			pp[st[now]] = 1;
			len[x]++;
			if (st[now] == y) break;
			now--;
		}
	}
	else {
		dfs(y);
		len[x] = len[y];
		if (!pp[x]) dis[x] = dis[y] + 1;
	}
		
	instack[x] = 0;
	tail--;
	pp[x] = 1;
}
int ans[N];
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> f[i];
	repn(i, 1, n) if (!pp[i]) {
		dfs(i);
	}
	repn(i, 1, n) g[len[i]].pb(dis[i]);
	repn(i, 1, n) {
		if (g[i].size() > 0) {
			idx[++m] = i;
			sort(all(g[i]));
		}
	}
	cin >> q;
	repn(i, 1, q) {
		cin >> a[i].a >> a[i].b;
		a[i].id = i;
	}
	sort(a + 1, a + q + 1);
	repn(i, 1, q) {
		LL x = a[i].a, y = a[i].b, d = min(x, y);
		int id = a[i].id, res = 0;
		repn(j, 1, m) {
			int pos = idx[j];
			while (head[pos] < g[pos].size() && d >= g[pos][head[pos]]) head[pos]++;
			if (abs(x - y) % pos == 0) res += head[pos];
		}
		if (x == y) ans[id] = n;
		else ans[id] = res;
	}
	repn(i, 1, q) cout << ans[i] << "\n";
	return 0;
}