// Problem: Merge
// URL: https://codeforces.com/gym/105143/problem/M
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++20 (GCC 13-64)
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
LL a[N];
vector<pair<LL, int>> cnt;
map<LL, int> m;
vector<LL> res;

bool find(LL num) {
	if (num <= 0) return false;
	if (m[num] && cnt[m[num]-1].se > 0) {
		cnt[m[num]-1].se --;
		return true;
	}
	else if (num > 1) {
		LL num1 = num / 2, num2 = num - num1;
		if (num1 % 2) swap(num1, num2);
		if (m[num1] && cnt[m[num1]-1].se > 0) {
			cnt[m[num1]-1].se --;
			if (find(num2)) {
				return true;
			}
			else {
				cnt[m[num1]-1].se ++;
			}
		}
	}
	return false;
}

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	LL cur = -1;
	int pos = 1, num = 0;
	repn(i, 1, n) {
		if (cur != a[i]) {
			if (cur > 0) {
				m[cur] = pos ++;
				cnt.pb(mp(cur, num));
			}
			cur = a[i];
			num = 1;
		}
		else num ++;
	}
	m[cur] = pos ++;
	cnt.pb(mp(cur, num));
//	for (auto pr : cnt) {
//		cout << pr.fi << " " << pr.se << "\n";
//	}
	per(i, 0, pos - 1) {
		while (cnt[i].se > 0) {
			cnt[i].se --;
			if (cnt[i].fi % 2) {
				if (i > 0 && cnt[i-1].fi + 1 == cnt[i].fi && cnt[i-1].se > 0) {
					res.pb(cnt[i-1].fi + cnt[i].fi);
					cnt[i-1].se --;
				}
				else {
					res.pb(cnt[i].fi);
				}
			}
			else {
				if (find(cnt[i].fi + 1)) {
					res.pb(2 * cnt[i].fi + 1);
				}
				else if (find(cnt[i].fi - 1)) {
					res.pb(2 * cnt[i].fi - 1);
//					cnt[i].se --;
				}
				else {
					res.pb(cnt[i].fi);
//					cnt[i].se --;
				}
			}
		}
	}
	sort(all(res));
	cout << res.size() << "\n";
	per(i, 0, res.size()) {
		cout << res[i] << " ";
	}cout << "\n";
	return 0;
}