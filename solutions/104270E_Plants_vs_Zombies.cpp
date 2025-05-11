// Problem: Plants vs. Zombies
// URL: https://codeforces.com/gym/104270/problem/E
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
typedef long double LD;

const int N = 110000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N];
LL t[N];
LL m;

void solve() {
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> a[i];
	} 
	LL l = 1, r = INF, ans = 0;
	while (l <= r) {
		LL mid = (l + r) / 2;
		LL cnt = 0;
		int last = 0;
		repn(i, 1, n) t[i] = (mid + a[i] - 1) / a[i];
		repn(i, 1, n) {
			if (t[i] <= 0) continue;
			cnt += i - last;
			last = i;
			if (t[i] > 1) {
				cnt += 2 * (t[i] - 1);
				t[i + 1] -= (t[i] - 1);
			}
			if (cnt > m) break;
		}
		if (cnt <= m) {
			ans = max(ans, mid); 
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";
}

int main() {
	IO; 
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;
}

