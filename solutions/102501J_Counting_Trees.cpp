// Problem: Counting Trees
// URL: https://codeforces.com/gym/102501/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 2100000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

#define BUF_SIZE 100000
bool IOerror = 0;
inline char nc() {
	static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
	if (p1 == pend) {
		p1 = buf;
		pend = buf + fread(buf, 1, BUF_SIZE, stdin);
		if (pend == p1) {
			IOerror = 1;
			return -1;
		}
	}
	return *p1++;
}
inline bool blank(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
	char ch;
	while (blank(ch = nc()));
	if (IOerror) return;
	for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
}
#undef BUF_SIZE

LL f[N], inv[N], ff[N];
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
int n, p[N];
set<int> S;
LL C(int n, int m) {
	LL res = f[n] * inv[m] % mod;
	res = res * inv[n - m] % mod;
	return res;
}
LL dp[N], ans = 1;
PII a[N];
int main() {
	IO;
	f[0] = 1, inv[0] = 1, ff[0] = ff[1] = 1;  
	rep(i, 1, N) {
		f[i] = (LL)(i) * f[i - 1] % mod;
	    if (i > 1) ff[i]= (LL)(mod - mod / i) * ff[mod % i] % mod;
	    inv[i] = inv[i - 1] * ff[i] % mod;
	}
	read(n);
	dp[0] = 1;
	repn(i, 1, n) dp[i] = C(2 * i, i) * ff[i + 1] % mod;
	repn(i, 1, n) {
		read(p[i]);
		a[i] = mp(p[i], i);
	}
	sort(a + 1, a + n + 1);
	int last = -1, num = 0;
	a[0] = mp(-1, -1);
	S.insert(n + 1);
	repn(i, 1, n) {
		int cur = *(S.lower_bound(a[i].se));
		if (a[i].fi != a[i - 1].fi || cur != last) {
			ans = ans * dp[num] % mod;
			num = 1;
		}
		else num++;
		last = cur;
		S.insert(a[i].se);
	}
	ans = ans * dp[num] % mod;
	cout << ans << endl;
	return 0;
}
	