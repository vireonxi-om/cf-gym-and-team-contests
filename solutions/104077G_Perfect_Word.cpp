// Problem: Perfect Word
// URL: https://codeforces.com/gym/104077/problem/G
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
string s[N];
PII a[N];
struct StringHash {
	// string is 0-index, arrays are 1-index
	string s;
	int n;
	StringHash () {}
	const ull base = 137;
	vector<ull> hsh, rhsh, pw;
	void init(string _s) {
		s = _s;
		n = s.size();
		hsh.resize(n + 2), rhsh.resize(n + 2), pw.resize(n + 2);
		pw[0] = 1;
		rep(i, 1, n + 2) pw[i] = pw[i - 1] * base;
		hsh[0] = rhsh[n + 1] = 0;
		repn(i, 1, n) hsh[i] = hsh[i - 1] * base + s[i - 1] - 'a' + 1;
		pern(i, 1, n) rhsh[i] = rhsh[i + 1] * base + s[i - 1] - 'a' + 1;
	}
	ull get_hsh(int l, int r) {
		ull res;
		if (l <= r) res = hsh[r] - (hsh[l - 1] * pw[r - l + 1]);
		else swap(l, r), res = rhsh[l] - (rhsh[r + 1] * pw[r - l + 1]);
		return res;
	}
	bool check_palindrome(int l, int r) {
		if (l > r) return 1;
		return get_hsh(l, r) == get_hsh(r, l);
	}
	bool check_same(int l1, int r1, int l2, int r2) {
		return get_hsh(l1, r1) == get_hsh(l2, r2);
	}
}p[N];
set<ull> S;
int ans;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> s[i], a[i] = mp(s[i].size(), i), p[i].init(s[i]);
	sort(a + 1, a + n + 1);
	repn(i, 1, n) {
		int id = a[i].se, len = s[id].size();
		if (len == 1) ans = 1, S.insert(p[id].get_hsh(1, len));
		else {
			if (!S.count(p[id].get_hsh(1, len - 1))) continue;
			if (!S.count(p[id].get_hsh(2, len))) continue;
			ans = max(ans, len);
			S.insert(p[id].get_hsh(1, len));
		}
	}
	cout << ans << "\n";
	return 0;
}