// Problem: Tarot Sham Boast
// URL: https://codeforces.com/gym/482684/problem/K
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
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
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

struct StringHash {
	// string is 0-index, arrays are 1-index
	string s;
	int n;
	StringHash () {}
	const ull base = 114514, cont = 137;
	vector<ull> hsh, rhsh, pw;
	void init(string _s) {
		s = _s;
		n = s.size();
		hsh.resize(n + 2), rhsh.resize(n + 2), pw.resize(n + 2);
		pw[0] = 1;
		rep(i, 1, n + 2) pw[i] = (pw[i - 1] * base) % mod;
		hsh[0] = rhsh[n + 1] = 0;
		repn(i, 1, n) hsh[i] = (hsh[i - 1] * base + s[i - 1] - 'a' + cont + mod) % mod;
		pern(i, 1, n) rhsh[i] = (rhsh[i + 1] * base + s[i - 1] - 'a' + cont + mod) % mod;
	}
	ull get_hsh(int l, int r) {
		ull res;
		if (l <= r) res = (hsh[r] - (hsh[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
		else swap(l, r), res = (rhsh[l] - (rhsh[r + 1] * pw[r - l + 1] % mod) + mod) % mod;
		return res;
	}
	bool check_palindrome(int l, int r) {
		if (l > r) return 1;
		return get_hsh(l, r) == get_hsh(r, l);
	}
	bool check_same(int l1, int r1, int l2, int r2) {
		return get_hsh(l1, r1) == get_hsh(l2, r2);
	}
}A;
int n, m;
pair<string, int> a[11];
string t[11];
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		string s;
		cin >> s;
		t[i] = s;
		a[i].fi = "";
		a[i].se = i;
		int l = s.size();
		repn(j, 1, l) a[i].fi += '0';
		A.init(s);
		rep(j, 1, l) {
			if (2 * l - j <= n && A.check_same(1, j, l - j + 1, l)) {
				(a[i].fi)[l - j] = '1';
			}
		}
	}
	sort(a + 1, a + m + 1);
	repn(i, 1, m) cout << t[a[i].se] << "\n";
	return 0;
}