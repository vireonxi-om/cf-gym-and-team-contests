// Problem: Branch Assignment
// URL: https://codeforces.com/gym/452521/problem/B
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

const int N = 5100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, b, s, r;
int pp[N]; 
vector<PIL> g[N], h[N];
priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL,int>>> q;
LL dis1[N], dis2[N];

void dijkstra1(int st) {
	repn(i, 0, n) dis1[i] = INF, pp[i] = 0;
	dis1[st] = 0;
	q.push(mp(0, st));
	while (!q.empty()) {
		int now = q.top().se; q.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: g[now]) {
			int y = p.fi;
			LL w = p.se;
			if (dis1[now] + w < dis1[y]) dis1[y] = dis1[now] + w, q.push(mp(dis1[y], y));
		}
	}
}
void dijkstra2(int st) {
	repn(i, 0, n) dis2[i] = INF, pp[i] = 0;
	dis2[st] = 0;
	q.push(mp(0, st));
	while (!q.empty()) {
		int now = q.top().se; q.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: h[now]) {
			int y = p.fi;
			LL w = p.se;
			if (dis2[now] + w < dis2[y]) dis2[y] = dis2[now] + w, q.push(mp(dis2[y], y));
		}
	}
}

LL a[N], dp[N][N], w[N][N], sum[N];
int sk[N][N];
int main() {
	IO;
	cin >> n >> b >> s >> r;
	repn(i, 1, r) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		h[v].pb(mp(u, w));
	}
	dijkstra1(b + 1);
	dijkstra2(b + 1);
	repn(i, 1, b) a[i] = dis1[i] + dis2[i];
	sort(a + 1, a + b + 1);
	repn(i, 1, b) sum[i] = sum[i - 1] + a[i];
	repn(i, 1, b) repn(j, i, b) w[i][j] = (sum[j] - sum[i - 1]) * (j - i);
	repn(i, 1, b) dp[i][1] = w[1][i];
	repn(j, 2, s) {
		repn(i, 0, b) dp[i][j] = INF;
		pern(i, j, b) {
			repn(k, max(i - i / j - 5, 0), i - 1) {
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + w[k + 1][i]);
			}
		}
	}
	cout << dp[b][s] << "\n";
	return 0;
}