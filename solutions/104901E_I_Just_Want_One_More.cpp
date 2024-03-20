// Problem: I Just Want... One More...
// URL: https://codeforces.com/gym/104901/problem/E
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
#define eb emplace_back
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m;
struct MCMF {
	// bfs, dinic
	// st must be the lowest index, ed must be the highest index
	int e[M], f[M], pre[M], last[N];
	int d[N], now[N];
	int num, st, ed, maxflow;
	queue<int> q;
	void init() {
		num = 1;
		repn(i, st, ed) last[i] = 0;
		maxflow = 0;
	}
	void insert(int x, int y, int z) {
		e[++num] = y, f[num] = z, pre[num] = last[x], last[x] = num;
		e[++num] = x, f[num] = 0, pre[num] = last[y], last[y] = num;
	}
	bool bfs() {
	    memset(d, -1, sizeof(d));
	    d[st] = 0;
		q.push(st);
	    while(!q.empty()) {
	        int now = q.front();
	        for (int i = last[now]; i; i = pre[i]) if (f[i] && d[e[i]] == -1) {
	                d[e[i]] = d[now] + 1;
	                q.push(e[i]); 
	            }
	        q.pop();
	    }
	    if (d[ed] == -1) return 0;
		return 1;
	}
	int dfs(int x, int incf) {
	    if (x == ed) return incf;
	    int flow = 0, w;
	    for (int i = now[x]; i; i = pre[i]) if (f[i] && d[e[i]] == d[x] + 1) {
				w = dfs(e[i], min(incf - flow, f[i]));
	            f[i] -= w, f[i ^ 1] += w; flow += w;
	            if (f[i]) now[x] = i;
				if (flow == incf) return incf;
	        }
	    if (!flow) d[x] = -1;
	    return flow;
	}
	LL run() {
		while(bfs()) {
			repn(i, st, ed) now[i] = last[i];
			maxflow += dfs(st, inf);
		}
		LL cnta = 0, cntb = 0;
		queue<int> que;
		memset(d, -1, sizeof(d));
		d[st] = 0, que.push(st);
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			if (now >= 1 && now <= n) cnta++;
			for (int i = last[now]; i; i = pre[i]) if (f[i] == 1 && d[e[i]] == -1) {
				que.push(e[i]), d[e[i]] = 0;
			}
		}
		memset(d, -1, sizeof(d));
		d[ed] = 0;
		que.push(ed);
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			if (now >= n + 1 && now <= n + n) cntb++;
			for (int i = last[now]; i; i = pre[i]) if (f[i] == 0 && d[e[i]] == -1) {
				que.push(e[i]), d[e[i]] = 0;
			}
		}
		return cnta * cntb;
	}
}solver;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		solver.st = 0, solver.ed = n + n + 1;
		solver.init();
		repn(i, 1, n) solver.insert(0, i, 1);
		repn(i, 1, n) solver.insert(n + i, n + n + 1, 1);
		repn(i, 1, m) {
			int x, y;
			cin >> x >> y;
			solver.insert(x, y + n, 1);
		}
		cout << solver.run() << "\n";
	}
	return 0;
}