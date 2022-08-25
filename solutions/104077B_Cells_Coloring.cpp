// Problem: Cells Coloring
// URL: https://codeforces.com/gym/104077/problem/B
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
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m;
LL c, d;
string s[260];
int row[260], col[260];

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
	void run() {
		while(bfs()) {
			repn(i, st, ed) now[i] = last[i];
			maxflow += dfs(st, inf);
		}
	}
}solver;

int main() {
	IO;
	cin >> n >> m >> c >> d;
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '.'){
				row[i] ++; col[j] ++;
				
			} 
		}
	}
	LL ans = d * n * m;
	solver.st = 1; solver.ed = m + n + 2;
	repn(k, 0, max(n, m)) {
		solver.init();
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (s[i][j] == '.') solver.insert(1 + 1 + i, 1 + n + 1 + j, 1);
			}
		} 
		int tot = 0;
		rep(i, 0, n){
			if (row[i] - k <= 0) continue;
			solver.insert(1, 1 + 1 + i, row[i] - k);
			tot += row[i] - k;
		} 
		rep(j, 0, m){
			if (col[j] - k <= 0) continue;
			solver.insert(1 + n + 1 + j, n + m + 2, col[j] - k);
			tot += col[j] - k;
		} 
		solver.run();
		//cout << tot << " " << solver.maxflow << "\n";
		LL z = tot - solver.maxflow; 
		//cout << z << " " << k << " " << z * d + c * k << "\n";
		ans = min(ans, z * d + c * k);
	}
	cout << ans << "\n";
	return 0;
}