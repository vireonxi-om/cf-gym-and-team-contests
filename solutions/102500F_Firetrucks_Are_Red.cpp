// Problem: Firetrucks Are Red
// URL: https://codeforces.com/gym/102500/problem/F
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 410000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const int INF = 1e8;
const double eps = 1e-9;

map<int, int> S;
int n, m, f[N], cnt, val[N];
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}
vector<int> g[N];
int main() {
	IO;
	cin >> n;
	cnt = n;
	repn(i, 1, n) {
		f[i] = i;
		cin >> m;
		repn(j, 1, m) {
			int x;
			cin >> x;
			if (!S.count(x)) S[x] = ++cnt, val[cnt] = x, f[cnt] = cnt;
			int fx = find(S[x]), fy = find(i);
			if (fx != fy) {
				f[fx] = fy;
				g[S[x]].pb(i), g[i].pb(S[x]);
			}
		}
	}
	int flag = 0;
	repn(i, 2, n) if (find(i) != find(1)) flag = 1;
	if (flag) {
		cout << "impossible\n";
		return 0;
	}
	repn(i, n + 1, cnt) {
		if (g[i].size() > 1) {
			rep(j, 1, g[i].size()) {
				cout << g[i][0] << " " << g[i][j] << " " << val[i] << "\n";
			}
		}
	}
	return 0;
}