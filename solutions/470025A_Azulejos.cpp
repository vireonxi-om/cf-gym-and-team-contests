// Problem: Azulejos
// URL: https://codeforces.com/gym/470025/problem/A
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

const int N = 510000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, p[2][N], h[2][N], n0, n1, t0, t1, ansa[N], ansb[N], pos;
PII a[N], b[N];
set<PII> sa, sb;
void print() {
	cout << "impossible\n";
	exit(0);
}
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> p[0][i];
	repn(i, 1, n) cin >> h[0][i];
	repn(i, 1, n) cin >> p[1][i];
	repn(i, 1, n) cin >> h[1][i];
	repn(i, 1, n) a[i] = mp(p[0][i], i), b[i] = mp(p[1][i], i);
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	t0 = t1 = 1;
	repn(i, 1, n) {
		int id = a[i].se;
		if (a[i].fi == a[1].fi) t0 = i, sa.insert(mp(h[0][id], id));
		else break;
	}
	repn(i, 1, n) {
		int id = b[i].se;
		if (b[i].fi == b[1].fi) t1 = i, sb.insert(mp(h[1][id], id));
		else break;
	}
	while (1) {
		if (sa.size() == sb.size()) {
			for (auto x: sb) {
				auto it = sa.lower_bound(mp(x.fi + 1, 0));
				if (it == sa.end()) print();
				ansa[++pos] = (it -> se);
				ansb[pos] = x.se;
				sa.erase(it);
			}
			sa.clear(), sb.clear();
			int l0 = t0 + 1, l1 = t1 + 1;
			if (l0 > n) break;
			repn(i, l0, n) {
				int id = a[i].se;
				if (a[i].fi == a[l0].fi) t0 = i, sa.insert(mp(h[0][id], id));
				else break;
			}
			repn(i, l1, n) {
				int id = b[i].se;
				if (b[i].fi == b[l1].fi) t1 = i, sb.insert(mp(h[1][id], id));
				else break;
			}
		}
		else if (sa.size() > sb.size()) {
			for (auto x: sb) {
				auto it = sa.lower_bound(mp(x.fi + 1, 0));
				if (it == sa.end()) print();
				ansa[++pos] = (it -> se);
				ansb[pos] = x.se;
				sa.erase(it);
			}
			sb.clear();
			int l1 = t1 + 1;
			repn(i, l1, n) {
				int id = b[i].se;
				if (b[i].fi == b[l1].fi) t1 = i, sb.insert(mp(h[1][id], id));
				else break;
			}
		}
		else {
			for (auto x: sa) {
				auto it = sb.upper_bound(mp(x.fi - 1, n + 1));
				if (it == sb.begin()) print();
				it--;
				ansa[++pos] = x.se;
				ansb[pos] = (it -> se);
				sb.erase(it);
			}
			sa.clear();
			int l0 = t0 + 1;
			repn(i, l0, n) {
				int id = a[i].se;
				if (a[i].fi == a[l0].fi) t0 = i, sa.insert(mp(h[0][id], id));
				else break;
			}
		}
	}
	repn(i, 1, n) cout << ansa[i] << " \n"[i == n];
	repn(i, 1, n) cout << ansb[i] << " \n"[i == n];
	return 0;
}