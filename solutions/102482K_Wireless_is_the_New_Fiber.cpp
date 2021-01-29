// Problem: Wireless is the New Fiber
// URL: https://codeforces.com/gym/102482/problem/K
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
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> PII;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf  = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int n, m, du[N], b[N], num, cnt, ans, pp[N], cp[N];
PII a[N];
int main() {
	IO;
	cin >> n >> m;
	cnt = 2 * m;
	repn(i, 1, m) {
		int x, y;
		cin >> x >> y;
		du[x]++, du[y]++;
	}
	rep(i, 0, n) a[i] = mp(du[i], i);
	sort(a, a + n);
	reverse(a, a + n);
	int head = 0;
	while (cnt != n + n - 2) {
		int id = a[head].se, delta = min(cnt - (n + n - 2), du[id] - 1);
		cnt -= delta, du[id] -= delta;
		if (delta) ans++;
		head++;
	}
	cout << ans << "\n";
	cout << n << " " << n - 1 << "\n";
	rep(i, 0, n) repn(j, 2, du[i]) b[++num] = i;
	rep(i, 0, n) pp[i] = 1;
	repn(i, 1, num) {
		repn(j, i, num) cp[b[j]] = 1;
		rep(j, 0, n) if (!cp[j] && pp[j]) {
			cout << b[i] << " " << j << "\n";
			pp[j] = 0;
			break;
		}
		repn(j, i, num) cp[b[j]] = 0;
	}
	int x = -1, y = -1;
	rep(i, 0, n) if (pp[i]) {
		if (x == -1) x = i;
		else {
			cout << x << " " << i << "\n";
			break;
		}
	}
	return 0;
}