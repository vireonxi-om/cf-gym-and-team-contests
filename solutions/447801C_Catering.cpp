// Problem: Catering
// URL: https://codeforces.com/gym/447801/problem/C
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
const int M = 4100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

struct MCMF {
	// SPFA, dinic, no negative ring
	// st must be the lowest index, ed must be the highest index
	int e[M], f[M], pre[M], last[N];
	int dd[N], pp[N], now[N];
	int num, st, ed, maxflow;
	LL d[N], w[N], ans;
	queue<int> q;
	void init() {
		num = 1;
		repn(i, st, ed) last[i] = 0;
		ans = maxflow = 0;
	}
	void insert(int x, int y, int c, LL v) {
		e[++num] = y, f[num] = c, w[num] = v, pre[num] = last[x], last[x] = num;
		e[++num] = x, f[num] = 0, w[num] = -v, pre[num] = last[y], last[y] = num;
	}
	bool spfa() {
		repn(i, st, ed) d[i] = INF, dd[i] = inf, pp[i] = 0;
		q.push(st);
		d[st] = dd[st] = 0, pp[st] = 1;
		while (!q.empty()) {
			int x = q.front();
			for (int i = last[x]; i; i = pre[i]) {
				if (!f[i]) continue;
				int y = e[i];
				if (d[y] > d[x] + w[i] || d[y] == d[x] + w[i] && dd[y] > dd[x] + 1) {
					d[y] = d[x] + w[i];
					dd[y] = dd[x] + 1;
					if (!pp[y]) pp[y] = 1, q.push(y);
				}
			}
			pp[x] = 0;
			q.pop();
		}
		// maximum flow
		// if (d[ed] == INF) return false;
		// return true;
		// minimum cost
		if (d[ed] >= 0) return false;
		return true;
	}
	int dfs(int x, int incf) {
	    if(x == ed) return incf;
	    int flow = 0, ww;
	    for (int i = now[x]; i; i = pre[i])
	        if (f[i] && dd[e[i]] == dd[x] + 1 && d[e[i]] == d[x] + w[i]) {
				ww = dfs(e[i], min(incf - flow, f[i]));
	            f[i] -= ww, f[i ^ 1] += ww;
	            flow += ww;
	            ans += (LL)ww * (LL)w[i];
	            if (f[i]) now[x] = i;
				if (flow == incf) return incf;
	        }
	    if(!flow) dd[x] = -1;
	    return flow;
	}
	void run() {
		while(spfa()) {
			repn(i, st, ed) now[i] = last[i];
			maxflow += dfs(st, inf);
		}
	}
}solver;
int n, k;
int main() {
	IO;
	cin >> n >> k;
	solver.st = 0, solver.ed = 1 + 2 * n + 1;
	solver.init();
	solver.insert(0, 1, k, 0);
	repn(i, 2, n + 1) solver.insert(i * 2 - 2, i * 2 - 1, 1, -inf);
	repn(i, 2, n + 1) {
		int x;
		cin >> x;
		solver.insert(1, i * 2 - 2, 1, x);
		solver.insert(i * 2 - 1, 1 + 2 * n + 1, 1, 0);
	}
	
	repn(i, 2, n) {
		repn(j, i + 1, n + 1) {
			int x;
			cin >> x;
			solver.insert(i * 2 - 1, j * 2 - 2, 1, x);
		}
	}
	solver.run();
	LL ans = solver.ans + (LL)n * inf;
	cout << ans << "\n";
	return 0;
}