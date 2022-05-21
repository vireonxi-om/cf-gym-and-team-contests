// Problem: Duplicates
// URL: https://codeforces.com/problemset/problem/1938/E
// Rating: 2200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
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

const int N = 110;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, a[N][N], cnt[N], fr[N], fc[N];
vector<pair<PII, int>> ans;

void solve() {
	cin >> n;
	ans.clear();
	repn(i, 1, n) {
		fr[i] = 0; fc[i] = 0;
	}
	repn(i, 1, n) {
		repn(j, 1, n) {
			cin >> a[i][j];
		}
	}
	repn(i, 1, n) {
		repn(t, 1, n) cnt[t] = 0;
		repn(j, 1, n) cnt[a[i][j]] ++;
		repn(t, 1, n) {
			if (cnt[t] == 0) {
				fr[i] = 1;
			}
		}
	}
	repn(j, 1, n) {
		repn(t, 1, n) cnt[t] = 0;
		repn(i, 1, n) cnt[a[i][j]] ++;
		repn(t, 1, n) {
			if (cnt[t] == 0) {
				fc[j] = 1;
			}
		}
	}
	int pc = 1, pr = 1;
	while (pr <= n && pc <= n) {
		while (fr[pr] == 1) pr ++;
		while (fc[pc] == 1) pc ++;
		if (pr > n || pc > n) break;
		int tmp = a[pr][pc] + 1;
		if (tmp > n) tmp = 1;
		ans.pb(mp(mp(pr, pc), tmp));
		pr ++;
		pc ++;
	}
	int pyc = 1;
	while (pr <= n) {
		while (fr[pr] == 1) pr ++;
		while (fc[pyc] == 0) pyc ++;
		if (pr > n || pyc > n) break;
		int tmp = pr;
		bool flag = false;
		while (a[tmp][pyc] == a[pr][pyc]) {
			tmp ++;
			if (tmp > n) tmp = 1;
			if (tmp == pr) {
				flag = true;
				break;
			}
		}
		if (flag) {
			int tmp = a[pr][pyc] + 1;
			if (tmp > n) tmp = 1;
			ans.pb(mp(mp(pr, pyc), tmp));
		}
		else ans.pb(mp(mp(pr, pyc), a[tmp][pyc]));
		pyc ++;
		pr ++;
	}
	int pyr = 1;
	while (pc <= n) {
		while (fr[pyr] == 0) pyr ++;
		while (fc[pc] == 1) pc ++;
		if (pyr > n || pc > n) break;
		int tmp = pc;
		bool flag = false;
		while (a[pyr][tmp] == a[pyr][pc]) {
			tmp ++;
			if (tmp > n) tmp = 1;
			if (tmp == pc) {
				flag = true;
				break;
			}
		}
		if (flag) {
			int tmp = a[pyr][pc] + 1;
			if (tmp > n) tmp = 1;
			ans.pb(mp(mp(pyr, pc), tmp));
		}
		else ans.pb(mp(mp(pyr, pc), a[pyr][tmp]));
		pc ++;
		pyr ++;
	}
	cout << ans.size() << "\n";
	for (auto item : ans) {
		cout << item.fi.fi << " " << item.fi.se << " " << item.se << "\n";	
	}
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();	
	return 0;
}