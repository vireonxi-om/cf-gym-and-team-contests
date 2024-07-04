// Problem: Flippy Sequence
// URL: https://codeforces.com/gym/104270/problem/C
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, a[N], x, y;
string s, t;
LL ans;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		cin >> t;
		int num = 0;
		a[n + 1] = 0;
		rep(i, 0, n) {
			a[i + 1] = (s[i] - '0') ^ (t[i] - '0');
			if (a[i] == 0 && a[i + 1] == 1) num++, x = i + 1;
		}
		rep(i, 0, n) {
			if (a[i + 1] == 1 && a[i + 2] == 0) y = i + 1;
		}
		if (num > 2) {
			cout << "0\n";
			continue;
		}
		
		ans = 0;
		if (num == 0) ans = (LL)n * (LL)(n + 1) / 2;
		else if (num == 1) {
			ans += (y - x) * 2;
			ans += (x - 1 + n - y) * 2;
		}
		else ans = 6;
		cout << ans << "\n";
	}
	return 0;
}