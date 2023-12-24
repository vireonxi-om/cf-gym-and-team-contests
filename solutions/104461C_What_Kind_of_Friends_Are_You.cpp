// Problem: What Kind of Friends Are You?
// URL: https://codeforces.com/gym/104461/problem/C
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

const int N = 210;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, q, a[N];
vector<string> base, s[N];
set<string> cur, tmp;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> q;
		base.clear();
		cin >> m;
		repn(i, 1, m) {
			string t;
			cin >> t;
			base.pb(t);
		}
		repn(i, 1, q) {
			int num;
			s[i].clear();
			cin >> num;
			while (num--) {
				string t;
				cin >> t;
				s[i].pb(t);
			}
		}
		while (n--) {
			cur.clear();
			for (auto x: base) cur.insert(x);
			repn(i, 1, q) {
				cin >> a[i];
				if (a[i] == 0) {
					for (auto x: s[i]) cur.erase(x);
				}
				else {
					tmp.clear();
					for (auto x: s[i]) if (cur.count(x)) tmp.insert(x);
					cur = tmp;
				}
			}
			if (cur.size() == 1) cout << (*(cur.begin())) << "\n";
			else cout << "Let's go to the library!!\n";
		}
	}
	return 0;
}