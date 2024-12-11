// Problem: Cloud Retainer's Game
// URL: https://codeforces.com/gym/103470/problem/I
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
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, H;
struct point {
	int x, y, tp;
	friend bool operator < (point a, point b) {
		return a.x < b.x;
	};
}a[N];
map<int, set<int>> S;
// 0 - up, 1 - down
int dp[N][2], ans;
int cal(LL x, LL y, int tp) {
	if (tp == 0) return (x - y + 2 * H) % (2 * H);
	else return (x + y) % (2 * H);
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> H;
		cin >> n;
		repn(i, 1, n) {
			cin >> a[i].x >> a[i].y;
			a[i].tp = 0;
		}
		cin >> m;
		repn(i, 1, m) {
			cin >> a[i + n].x >> a[i + n].y;
			a[i + n].tp = 1;
		}
		a[0].tp = 1;
		sort(a + 1, a + n + m + 1);
		S.clear();
		repn(i, 0, n + m) {
			int x = a[i].x, y = a[i].y;
			dp[i][0] = dp[i][1] = -1;
			S[cal(x, y, 0)].insert(i);
			S[cal(x, y, 1)].insert(i);
			// cout << i << " " << cal(x, y, 0) << " " << cal(x, y, 1) << "\n";
		}
		dp[0][0] = 0;
		ans = 0;
		repn(i, 0, n + m) {
			if (a[i].tp == 0) {
				int res = max(dp[i][0], dp[i][1]);
				dp[i][0] = dp[i][1] = res;
			}
			rep(tp, 0, 2) {
				if (dp[i][tp] == -1) continue;
				ans = max(ans, dp[i][tp]);
				int x = a[i].x, y = a[i].y;
				auto it = S[cal(x, y, tp)].upper_bound(i);
				if (it == S[cal(x, y, tp)].end()) continue;
				int idx = *it;
				if (cal(a[idx].x, a[idx].y, 0) == cal(x, y, tp)) dp[idx][0] = max(dp[idx][0], dp[i][tp] + a[idx].tp);
				else dp[idx][1] = max(dp[idx][1], dp[i][tp] + a[idx].tp);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}