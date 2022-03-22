// Problem: Algorithm Teaching
// URL: https://codeforces.com/gym/102428/problem/A
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
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

map<vector<string>, int> S;
int n;
vector<int> g[N];
int nx, tx[N], ty[N], dx[N], dy[N], dis;
bool flag[N];
bool bfs() {
	queue<int> q;
	dis = inf;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for (int i = 1; i <= nx; i++) 
		if (tx[i] == -1){
			q.push(i);
			dx[i] = 0;
		}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dx[u] > dis) break;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (dy[v] == -1) {
				dy[v] = dx[u] + 1;
				if (ty[v] == -1) dis = dy[v];
				else {
					dx[ty[v]] = dy[v] + 1;
					q.push(ty[v]);
				}
			} 
		}
	}
	return dis != inf;
}
bool dfs(int u) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!flag[v] && dy[v] == dx[u] + 1) {
			flag[v] = 1;
			if (ty[v] != -1 && dy[v] == dis) continue;
			if (ty[v] == -1 || dfs(ty[v])){
				ty[v] = u;
				tx[u] = v;
				return 1;
			}
		}
	}
	return 0;
}
int HC(){
	int ans = 0;
	memset(tx, -1, sizeof(tx));
	memset(ty, -1, sizeof(ty));
	while (bfs()) {
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= nx; i++) if (tx[i] == -1 && dfs(i)) ans++;
	}
	for (int i = 1; i <= nx; i++) g[i].clear();
	return ans;
}
int id[N];
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		int k;
		cin >> k;
		vector<string> v;
		repn(j, 1, k) {
			string tmp;
			cin >> tmp;
			v.pb(tmp);
		}
		sort(all(v));
		rep(j, 1, 1 << k) {
			vector<string> cur;
			rep(l, 0, k) if (j >> l & 1) cur.pb(v[l]);
			if (!S[cur]) S[cur]=++nx;
			id[j] = S[cur];
			for (int l = j; l; l = (l - 1) & j) if (j != l) g[id[j]].pb(id[l]);
		}
	}
	cout << nx - HC() << "\n";
	return 0;
}