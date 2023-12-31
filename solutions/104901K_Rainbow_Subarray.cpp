// Problem: Rainbow Subarray
// URL: https://codeforces.com/gym/104901/problem/K
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

const int N = 510000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, a[N];
multiset<int> l, r;
LL sl, sr, k;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		repn(i, 1, n) cin >> a[i], a[i] -= i;
		sl = sr = 0;
		l.clear(), r.clear();
		int ans = 1;
		int p = 0;
		repn(i, 1, n) {
			if (p < i) {
				p = i;
				l.clear(), r.clear();
				sl = sr = 0;
				l.insert(a[i]), sl += a[i];
			}
			while (p < n) {
				p++;
				if (l.size() == r.size()) {
					r.insert(a[p]), sr += a[p];
					l.insert(*(r.begin())), sl += (*(r.begin()));
					sr -= (*(r.begin())), r.erase(r.begin());
				}
				else {
					l.insert(a[p]), sl += a[p];
					r.insert(*(l.rbegin())), sr += (*(l.rbegin()));
					sl -= (*(l.rbegin())), l.erase(l.lower_bound(*(l.rbegin())));
				}
				LL m = *(l.rbegin());
				LL sum = m * SZ(l) - sl + sr - m * SZ(r);
				if (sum > k) {
					if (l.count(a[p])) l.erase(l.lower_bound(a[p])), sl -= a[p];
					else r.erase(r.lower_bound(a[p])), sr -= a[p];
					if (r.size() > l.size()) {
						sl += *(r.begin()), sr -= *(r.begin());
						l.insert(*(r.begin())), r.erase(r.begin()); 
					}
					if (SZ(l) == SZ(r) + 2) {
						sr += *(l.rbegin()), sl -= *(l.rbegin());
						r.insert(*(l.rbegin())), l.erase(l.lower_bound(*(l.rbegin())));
					}
					p--;
					break;
				}
			}
			ans = max(ans, p - i + 1);
			if (l.count(a[i])) l.erase(l.lower_bound(a[i])), sl -= a[i];
			else r.erase(r.lower_bound(a[i])), sr -= a[i];
			if (r.size() > l.size()) {
				sl += *(r.begin()), sr -= *(r.begin());
				l.insert(*(r.begin())), r.erase(r.begin()); 
			}
			if (SZ(l) == SZ(r) + 2) {
				sr += *(l.rbegin()), sl -= *(l.rbegin());
				r.insert(*(l.rbegin())), l.erase(l.lower_bound(*(l.rbegin())));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}