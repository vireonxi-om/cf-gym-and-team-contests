// Problem: Beautiful Bridges
// URL: https://codeforces.com/gym/470025/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
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

const int N = 11000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int n, h;
LL x[N], y[N], dp[N];
LL alp, blt;
int lf[N], rt[N];

int main() {
	cin >> n >> h >> alp >> blt; 
	repn(i, 1, n) cin >> x[i] >> y[i];
	repn(i, 1, n) y[i] = h - y[i];
	repn(i, 1, n) {
		int l = i, r = n, ans = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			int mp = (mid + i) / 2;
			int n1 = x[mid] - x[i], n2 = x[mid] + x[i];
			bool yes = true;
			repn(j, i, mp) {
				if (2 * y[j] > n1) continue;
				LL num = 4 * y[j] * y[j] - 4 * y[j] * n1 + 4 * x[j] * x[j] - 4 * x[j] * n2 + (LL) n2 * n2;
				if (num > 0) yes = false;
			}
			if (yes) {
				l = mid + 1;
				ans = max(ans, mid);
			}
			else r = mid - 1;
		}
		lf[i] = ans;
	}
	pern(i, 1, n) {
		int l = 1, r = i, ans = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			int mp = (mid + i + 1) / 2;
			int n1 = x[i] - x[mid], n2 = x[i] + x[mid];
			bool yes = true;
			repn(j, mp, i) {
				if (2 * y[j] > n1) continue;
				LL num = 4 * y[j] * y[j] - 4 * y[j] * n1 + 4 * x[j] * x[j] - 4 * x[j] * n2 + (LL) n2 * n2;
				if (num > 0) yes = false;
			}
			if (yes) {
				r = mid - 1;
				ans = min(ans, mid);
			}
			else l = mid + 1;
		}
		rt[i] = ans;
	}
	/*
	repn(i, 1, n) cout << lf[i] << " ";
	cout << "\n";
	repn(i, 1, n) cout << rt[i] << " ";
	cout << "\n";
	*/
	repn(i, 1, n) dp[i] = 1e18;
	dp[1] = alp * y[1];
	repn(i, 2, n) {
		rep(j, 1, i) {
			if (lf[j] < i || rt[i] > j) continue;
			dp[i] = min(dp[i], dp[j] + alp * y[i] + blt * (x[i] - x[j]) * (x[i] - x[j]));
		}
	}
	if (dp[n] == 1e18) cout << "impossible\n";
	else cout << dp[n] << "\n";
	return 0;
}
