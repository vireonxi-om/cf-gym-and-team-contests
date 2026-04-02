// Problem: 
// URL: https://codeforces.com/gym/471068/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 2100;
const int M = 1100;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int n, m, x;
int a, b, c, d;
vector<PII> g[N];
LL dist[N];
int cnt[N];

int work() {
	repn(i, 0, n) dist[i] = INF, cnt[i] = 0;
	dist[0] = 0, cnt[0] = 1;
	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto p: g[x]) {
			int y = p.fi, w = p.se;
			if (dist[y] > dist[x] + w) {
				dist[y] = dist[x] + w;
				que.push(y);
				cnt[y]++;
				if (cnt[y] > n + 10) return 0;
			}
		}
	}
	return 1;
}
			
	
void solve(){
	cin >> n >> m >> x;
	repn(i, 0, n) {
		g[i].clear();
		dist[i] = 0;
	} 
	repn(i, 1, n) g[0].pb(mp(i, 0));
	rep(i, 1, n) g[i + 1].pb(mp(i, -1));
	repn(i, 1, m) {
		cin >> a >> b >> c >> d;
		if (a == b && c == d) {
			g[b].pb(mp(c, x));
			g[c].pb(mp(b, -x));
		}
		else {
			if (b < c) {
				g[b].pb(mp(c, x - 1));
			}
			if (d > a) {
				g[d].pb(mp(a, -1-x));
			}
		}		
	}
	bool can = work();
	if (can) {
		rep(i, 1, n) {
			cout << dist[i + 1] - dist[i] << " ";
		}
		cout << "\n";
	}
	else cout << "IMPOSSIBLE\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T)  {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
