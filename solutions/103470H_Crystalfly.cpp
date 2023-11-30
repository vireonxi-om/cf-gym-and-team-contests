// Problem: Crystalfly
// URL: https://codeforces.com/gym/103470/problem/H
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
const int M = 110000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

LL dp[N], b[N], a[N];
int t[N];
int n;
vector<int> v[N]; 

void dfs(int u, int f) {
	LL sdp = 0, sa = 0;
	LL ma = 0, mb1 = 0, id1 = 0, mb2 = 0; 
	//cout << u << " " << f << ": \n";
	for (auto lf : v[u]) {
		if (lf == f) continue;
		dfs(lf, u);
		sdp += dp[lf];
		sa += a[lf];
		ma = max(a[lf], ma);
		if (b[lf] > mb1) {
			mb2 = mb1;
			mb1 = b[lf];
			id1 = lf;
		}
		else if (b[lf] > mb2) {
			mb2 = b[lf];
		}
	}
	dp[u] = a[u] + sdp - sa + ma;
	for (auto lf : v[u]) {
		if (lf == f) continue;
		if (t[lf] == 3) {
			LL num = mb1;
			if (id1 == lf) num = mb2;
			dp[u] = max(dp[u], a[u] + sdp - sa + a[lf] + num);
		}
	}
	b[u] = 2 * a[u] + sdp - sa - dp[u];
	//cout << u << ": \n";
	//cout << dp[u] << " " << b[u]  << " " << "\n";
	return;
}


void solve() {
	cin >> n;
	repn(i, 1, n) {
		dp[i] = 0; b[i] = 0; cin >> a[i];
		v[i].clear();
	}
	repn(i, 1, n) cin >> t[i];
	int t1, t2;
	rep(i, 1, n) {
		cin >> t1 >> t2;
		v[t1].pb(t2);
		v[t2].pb(t1);
	}
	dfs(1, 0);

	cout << dp[1] << "\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




