// Problem: Birdwatching
// URL: https://codeforces.com/gym/102501/problem/K
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
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, s;
vector<int> g[N], rg[N];
int dfn[N], low[N], instack[N], cnt, scc_cnt;
stack<int> st;
int pp[N], scc[N], num[N];
void dfs(int x) {
	dfn[x] = low[x] = ++cnt;
	st.push(x);
	instack[x] = 1;
	for (auto y: g[x]) {
		if (dfn[y] == 0) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (instack[y]) low[x] = min(low[x], dfn[y]);
	}
	if (low[x] == dfn[x]) {
		++scc_cnt;
		while (!st.empty() && st.top() != x) {
			scc[st.top()] = scc_cnt;
			instack[st.top()] = 0;
			st.pop();
		}
		st.pop();
		scc[x] = scc_cnt;
		instack[x] = 0;
	}
}
vector<int> ans;
int main() {
	IO;
	cin >> n >> m >> s;
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		if (x != s) g[y].pb(x);
		rg[x].pb(y);
	}
	dfs(s);
	rep(i, 0, n) {
		if (dfn[i]) {
			for (auto x: rg[i]) {
				if (dfn[x] && scc[x] != scc[i]) num[scc[i]]++;
			}
		}
	}
	for (auto x: g[s]) {
		if (num[scc[x]] == 1) ans.pb(x);
	}
	sort(all(ans));
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << "\n";
	return 0;
}