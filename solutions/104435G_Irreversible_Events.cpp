// Problem: Irreversible Events
// URL: https://codeforces.com/gym/104435/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m;
vector<int> g[N];
int dfn[N], low[N], instack[N], scc[N], cnt, scc_cnt, pp[N];
stack<int> st;
void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	st.push(x);
	instack[x] = 1;
	for (auto y: g[x]) {
		if (dfn[y] == 0) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (instack[y]) low[x] = min(low[x], dfn[y]);
	}
	if (low[x]==dfn[x]) {
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
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cnt = scc_cnt = 0;
		repn(i, 1, n) g[i].clear(), dfn[i] = low[i] = instack[i] = pp[i] = 0;
		repn(i, 1, m) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y);
		}
		repn(i, 1, n) if (!dfn[i]) tarjan(i);
		int ans = 0;
		repn(x, 1, n) {
			for (auto y: g[x]) {
				if (scc[x] == scc[y]) continue;
				if (!pp[scc[y]]) pp[scc[y]] = 1;
				else ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}