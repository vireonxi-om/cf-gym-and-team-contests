// Problem: Catch the Plane
// URL: https://codeforces.com/gym/102482/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> PII;

const int N = 2100000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf  = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int n, m, cnt = 0;
LL k;
struct bus {
	int sp, ep;
	LL st, et;
	int id;
	double p;
	friend bool operator < (bus a, bus b) {
		return a.st < b.st;
	}
	void input() {
		cin >> sp >> ep >> st >> et >> p;
	}
}a[N];
int v[N], idx[N];
vector<pair<PII, double> > g[N];
vector<int> rg[N];
vector<bus> f[N];
double dp[N];
int du[N];
queue<int> que;
int main() {
	IO;
	cin >> m >> n;
	cin >> k;
	repn(i, 1, m) a[i].input(), f[a[i].sp].eb(a[i]);
	if (f[0].size() == 0) {
		cout << "0.0\n";
		return 0;
	}
	rep(i, 0, n) {
		sort(all(f[i]));
		rep(j, 0, SZ(f[i])) f[i][j].id = ++cnt, v[cnt] = i, idx[cnt] = j;
	}
	cnt++;
	rep(i, 0, n) {
		rep(j, 0, SZ(f[i])) {
			int dst = f[i][j].ep;
			LL t = f[i][j].et;
			
			int tid, fid = 0;
			if (dst == 1) tid = cnt;
			else {
				bus p;
				p.st = t;
				int pos = upper_bound(f[dst].begin(), f[dst].end(), p) - f[dst].begin();
				if (pos >= f[dst].size()) tid = 0;
				else tid = f[dst][pos].id;
			}
			int pos = upper_bound(f[i].begin(), f[i].end(), f[i][j]) - f[i].begin();
			if (pos < f[i].size()) fid = f[i][pos].id, du[f[i][j].id]++, rg[fid].pb(f[i][j].id);
			g[f[i][j].id].eb(mp(mp(tid, fid), f[i][j].p)), du[f[i][j].id]++, rg[tid].pb(f[i][j].id);
			if (j + 1 < SZ(f[i])) du[f[i][j].id]++, rg[f[i][j + 1].id].pb(f[i][j].id);
		}
	}
	dp[cnt] = 1;
	repn(i, 0, cnt) if (du[i] == 0) que.push(i);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto y: rg[x]) {
			du[y]--;
			if (du[y] == 0) que.push(y);
		}
		if (x == cnt) continue;
		if (idx[x] + 1 < f[v[x]].size()) dp[x] = dp[f[v[x]][idx[x] + 1].id];
		for (auto z: g[x]) {
			int y = z.fi.fi, w = z.fi.se;
			double p = z.se;
			dp[x] = max(dp[x], p * dp[y] + (1 - p) * dp[w]);
		}
	}
		
	cout << fixed << setprecision(15) << dp[1] << "\n";
	return 0;
}