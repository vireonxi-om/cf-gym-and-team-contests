// Problem: 
// URL: https://codeforces.com/gym/471068/problem/K
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

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

typedef __int128 int128;
int T, n, cas;
const int wayx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int wayy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
map<PII, int> S;
int num[110];
int128 ans;
int main() {
	IO;
	// cin >> n;
	int lim = 20;
	queue<PII> que;
	que.push(mp(0, 0));
	S[mp(0, 0)] = 0;
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		int x = now.fi, y = now.se;
		int dis = S[mp(x, y)];
		if (dis == lim) continue;
		rep(i, 0, 8) {
			int nx = x + wayx[i], ny = y + wayy[i];
			if (!S.count(mp(nx, ny))) {
				S[mp(nx, ny)] = dis + 1;
				que.push(mp(nx, ny));
			}
		}
	}
	for (auto p: S) {
		num[p.se]++;
	}
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= lim) {
			ans = 0;
			repn(i, 0, n) ans += num[i];
		}
		else {
			ans = 0;
			int128 delta = num[lim];
			repn(i, 0, lim) ans += num[i];
			int128 m = n - lim, a0 = delta + 28, am = delta + 28 * m;
			int128 sum = (a0 + am) * m / 2;
			ans = ans + sum;
		}
		string res = "";
		while (ans) res += '0' + (ans % 10), ans /= 10;
		reverse(all(res));
		cout << "Case #" << ++cas << ": " << res << "\n";
	}
	// cout << S.size() << "\n";
	return 0;
}