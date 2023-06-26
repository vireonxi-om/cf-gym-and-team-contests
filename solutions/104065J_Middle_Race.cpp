// Problem: Middle Race
// URL: https://codeforces.com/gym/104065/problem/J
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n;
LL a, b, c, x, y, z, sum;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> a >> b >> c;
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		sum = n * (a + b + c);
		LL ans = INF;
		repn(x0, 0, n) {
			int l = 0, r = n - x0;
			while (l <= r) {
				int mid = (l + r) / 2;
				LL res = 3 * (x0 * a + mid * b + (n - x0 - mid) * c);
				if (abs(res - sum) < ans) ans = abs(res - sum), x = x0, y = mid, z = n - x0 - mid;
				if (res >= sum) l = mid + 1;
				else r = mid - 1;
			}
		}
		repn(i, 1, n) {
			int res, t1, t2;
			if (x) res = a, x--;
			else if (y) res = b, y--;
			else res = c, z--;
			cout << res << endl;
			fflush(stdout);
			cin >> t1 >> t2;
		}
	}
	return 0;
}