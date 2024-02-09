// Problem: Half Mixed
// URL: https://codeforces.com/gym/104160/problem/F
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

int T, n, m;
int a[M];
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		if ((n % 4 == 1 || n % 4 == 2) && (m % 4 == 1 || m % 4 == 2)) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		if (n % 4 == 3 || n % 4 == 0) {
			LL sum = (LL)n * (n + 1) / 4;
			int cur = 1, p = 0;
			while (cur <= n) {
				int l = 1, r = n - cur + 1, ans;
				while (l <= r) {
					LL mid = (l + r) / 2;
					if (mid * (mid + 1) / 2 + n - (cur + mid - 1) <= sum) l = mid + 1, ans = mid;
					else r = mid - 1;
				}
				sum -= (LL)ans * (ans + 1) / 2;
				repn(i, cur, cur + ans - 1) a[i] = p;
				p ^= 1;
				cur += ans;
			}
			repn(i, 1, n) repn(j, 1, m) cout << a[i] << " \n"[j == m];
		}
		else {
			LL sum = (LL)m * (m + 1) / 4;
			int cur = 1, p = 0;
			while (cur <= m) {
				int l = 1, r = m - cur + 1, ans;
				while (l <= r) {
					LL mid = (l + r) / 2;
					if (mid * (mid + 1) / 2 + m - (cur + mid - 1) <= sum) l = mid + 1, ans = mid;
					else r = mid - 1;
				}
				sum -= (LL)ans * (ans + 1) / 2;
				repn(i, cur, cur + ans - 1) a[i] = p;
				p ^= 1;
				cur += ans;
			}
			repn(i, 1, n) repn(j, 1, m) cout << a[j] << " \n"[j == m];
		}
	}
	return 0;
}