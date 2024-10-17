// Problem: Monument Tour
// URL: https://codeforces.com/gym/102465/problem/D
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

int n, x, y;
vector<PII> g[N];
int mn[N], mx[N], px[N], py[N];
LL ans = 1e18, coef, bias;
int main()
{
	IO;
	cin >> x >> y;
	cin >> n;
	repn(i, 0, x) mn[i] = inf, mx[i] = -1;
	repn(i, 1, n) {
		cin >> px[i] >> py[i];
		mn[px[i]] = min(mn[px[i]], py[i]);
		mx[px[i]] = max(mx[px[i]], py[i]);
	}
	rep(i, 0, x) {
		if (mn[i] <= mx[i]) {
			g[mn[i]].pb(mp(0, i));
			g[mx[i]].pb(mp(1, i));
			coef -= 2;
			bias += 2 * mx[i];
		}
	}
	rep(i, 0, y) {
		sort(all(g[i]));
		for (auto p: g[i]) {
			int col = p.se;
			if (p.fi == 0) {
				coef += 2;
				bias -= 2 * mx[col];
				bias += 2 * (mx[col] - mn[col]);
			}
			else {
				coef += 2;
				bias -= 2 * (mx[col] - mn[col]);
				bias -= 2 * mn[col];
			}
		}
		ans = min(ans, (LL)i * coef + bias + x - 1);
	}
	cout << ans << endl;
	return 0;
}