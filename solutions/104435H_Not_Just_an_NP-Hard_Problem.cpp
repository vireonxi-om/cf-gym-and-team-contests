// Problem: Not Just an NP-Hard Problem
// URL: https://codeforces.com/gym/104435/problem/H
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

int T, n;
LL x[N], sum0, sum1;
vector<int> a0, a1;
PII a[N];
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		sum0 = sum1 = 0;
		repn(i, 1, n) {
			cin >> x[i];
			a[i] = mp(x[i], i);
		}
		sort(a + 1, a + n + 1);
		a0.clear(), a1.clear();
		per(i, 1, n) {
			if (sum0 <= sum1) {
				sum0 += a[i].fi;
				a0.pb(a[i].se);
			}
			else {
				sum1 += a[i].fi;
				a1.pb(a[i].se);
			}
		}
		int la, lb;
		if (sum0 <= sum1) {
			int d = sum1 - sum0;
			if (d == a[n].fi) {
				la = 1, lb = a[n].fi - 1;
				sum0 += la + lb;
				a0.pb(n + 1), a0.pb(n + 2);
			}
			else {
				la = d + (a[n].fi - d) / 2;
				lb = a[n].fi - la;
				sum0 += la, sum1 += lb;
				a0.pb(n + 1), a1.pb(n + 2);
			}
		}
		else {
			int d = sum0 - sum1;
			if (d == a[n].fi) {
				la = 1, lb = a[n].fi - 1;
				sum1 += la + lb;
				a1.pb(n + 1), a1.pb(n + 2);
			}
			else {
				lb = d + (a[n].fi - d) / 2;
				la = a[n].fi - lb;
				sum0 += la, sum1 += lb;
				a0.pb(n + 1), a1.pb(n + 2);
			}
		}
		cout << a[n].se << " " << la << " " << lb << "\n";
		sort(all(a0)), sort(all(a1));
		rep(i, 0, a0.size()) cout << a0[i] << " \n"[i == SZ(a0) - 1];
		rep(i, 0, a1.size()) cout << a1[i] << " \n"[i == SZ(a1) - 1];
		LL area = sum0 * sum1;
		if (area & 1) cout << area / 2 << ".5000000000000000\n";
		else cout << area / 2 << ".0000000000000000\n";
	}
	return 0;
}