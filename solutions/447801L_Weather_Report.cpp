// Problem: Weather Report
// URL: https://codeforces.com/gym/447801/problem/L
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
typedef pair<double, LL> PDL;

const int N = 510000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, cnt;
LD p[N], a[N], w[N], pw[5][60];
vector<int> g[N];
priority_queue<PDL> q;
LD ans;
LL C[60][60];
int main() {
	IO;
	C[0][0] = 1;
    rep(i, 1, 60) {
		C[i][0] = 1;
        repn(j, 1, i)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	cin >> n;
	repn(i, 1, 4) cin >> p[i];
	repn(i, 1, 4) {
		pw[i][0] = 1;
		repn(j, 1, n) pw[i][j] = pw[i][j - 1] * p[i];
	}
	repn(i, 0, n) repn(j, 0, n - i) repn(k, 0, n - i - j) {
		int l = n - i - j - k;
		a[++cnt] = pw[1][i] * pw[2][j] * pw[3][k] * pw[4][l];
		w[cnt] = C[n][i] * C[n - i][j] * C[n - i - j][k] * C[n - i - j - k][l];
		q.push(mp(-a[cnt], w[cnt]));
	}
	while (1) {
		auto x = q.top(); q.pop();
		if (x.se > 1) {
			ans -= x.fi * 2 * (x.se / 2);
			q.push({x.fi * 2, x.se / 2});
			if (x.se % 2) q.push({x.fi, 1});
			continue;
		}
		if (q.empty()) break;
		auto y = q.top(); q.pop();
		ans -= x.fi + y.fi;
		q.push({x.fi + y.fi, 1});
		if (y.se > 1) q.push({y.fi, y.se - 1});
	}
	cout << fixed << setprecision(15) << (double)ans << "\n";
	return 0;
}