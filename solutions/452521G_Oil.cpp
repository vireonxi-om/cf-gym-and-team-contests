// Problem: Oil
// URL: https://codeforces.com/gym/452521/problem/G
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
typedef pair<LL, LL> PLL;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 2100;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);


int n;
LL p[N][3];
vector<pair<long double, int>> tmp;

inline int dcmp(long double x) {
    return (x > eps) - (x < -eps);
}

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		rep(j, 0, 3) cin >> p[i][j]; 
		if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
	} 
	LL ans = 0;
	repn(i, 1, n) {
		rep(k, 0, 2) {
			tmp.clear();
			long double x1 = p[i][k], y1 = p[i][2];
			repn(j, 1, n) {
				if (p[j][2] == p[i][2]) continue;
				long double x2 = p[j][0], y2 = p[j][2];
				long double a = x1 - y1 * (x2 - x1) / (y2 - y1);
				x2 = p[j][1];
				long double b = x1 - y1 * (x2 - x1) / (y2 - y1);
				if (dcmp(a - b) > 0) swap(a, b);
				tmp.pb(mp(a - eps, -j)); tmp.pb(mp(b + eps, j));
			}
			sort(all(tmp));
			LL cur = p[i][1] - p[i][0];
			ans = max(ans, cur);
			for (auto pr : tmp) {
				if (pr.se > 0) cur -= p[pr.se][1] - p[pr.se][0];
				else cur += p[-pr.se][1] - p[-pr.se][0];
				ans = max(ans, cur);
			}
		}
		
	}
	cout << ans << "\n";
	return 0;
	
}