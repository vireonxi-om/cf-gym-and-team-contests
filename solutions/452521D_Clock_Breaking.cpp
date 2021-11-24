// Problem: Clock Breaking
// URL: https://codeforces.com/gym/452521/problem/D
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

const int N = 110;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, flag;
char num[10][7][4];
int f[7][21], tmp[7][21];
char st[8] = {'.', '0', '1', '?', 'W', '?', '?', '?'};
struct node {
	char s[7][21];
	void init() {
		rep(i, 0, 7) rep(j, 0, 21) s[i][j] = '.';
	}
	void read() {
		rep(i, 0, 7) {
			string t;
			cin >> t;
			rep(j, 0, 21) s[i][j] = t[j];
		}
	}
	void print() {
		rep(i, 0, 7) {
			rep(j, 0, 21) {
				s[i][j] = st[f[i][j]];
				putchar(s[i][j]);
			}
			putchar('\n');
		}
		
	}
	void insert(int idx, int w) {
		rep(i, 0, 7) rep(j, 0, 4) s[i][j + w] = num[idx][i][j];
	}
		
}a[N], b[N], ans;
vector<PII> arr;
void work(int x, int idx) {
	if (idx == 0) num[x][0][1] = num[x][0][2] = 'X';
	if (idx == 1) num[x][3][1] = num[x][3][2] = 'X';
	if (idx == 2) num[x][6][1] = num[x][6][2] = 'X';
	if (idx == 3) num[x][1][0] = num[x][2][0] = 'X';
	if (idx == 4) num[x][1][3] = num[x][2][3] = 'X';
	if (idx == 5) num[x][4][0] = num[x][5][0] = 'X';
	if (idx == 6) num[x][4][3] = num[x][5][3] = 'X';
}
node make(int h, int m) {
	node res;
	res.init();
	if (h >= 10) res.insert(h / 10, 0);
	res.insert(h % 10, 5);
	res.insert(m / 10, 12);
	res.insert(m % 10, 17);
	res.s[2][10] = res.s[4][10] = 'X';
	return res;
}
int main() {
	IO;
	rep(i, 0, 10) rep(j, 0, 7) rep(k, 0, 4) num[i][j][k] = '.';
	for (auto x: {0, 3, 4, 5, 6, 2}) work(0, x);
	for (auto x: {4, 6}) work(1, x);
	for (auto x: {0, 4, 1, 5, 2}) work(2, x);
	for (auto x: {0, 4, 1, 6, 2}) work(3, x);
	for (auto x: {3, 1, 4, 6}) work(4, x);
	for (auto x: {0, 3, 1, 6, 2}) work(5, x);
	for (auto x: {0, 3, 1, 5, 6, 2}) work(6, x);
	for (auto x: {0, 4, 6}) work(7, x);
	for (auto x: {0, 3, 4, 1, 5, 6, 2}) work(8, x);
	for (auto x: {0, 3, 4, 1, 6, 2}) work(9, x);
	rep(i, 0, 7) rep(j, 0, 4) if (num[8][i][j] == 'X') {
		for (auto w: {0, 5, 12, 17}) arr.pb(mp(i, j + w));
	}
	arr.pb(mp(2, 10)), arr.pb(mp(4, 10));
	// arr.clear(), arr.pb(mp(4, 10));
	cin >> n;
	repn(i, 1, n) a[i].read();
	ans.init();
	repn(h, 0, 23) repn(m, 0, 59) {
		int ch = h, cm = m;
		repn(j, 1, n) {
			b[j] = make(ch, cm);
			cm += 1;
			if (cm == 60) cm = 0, ch += 1;
			if (ch == 24) ch = 0;
		}
		memset(tmp, 0, sizeof(tmp));
		int ff = 0;
		for (auto p: arr) {
			int x = p.fi, y = p.se;
			// W
			int fw = 1;
			repn(j, 1, n) if (a[j].s[x][y] != b[j].s[x][y]) fw = 0;
			// 0
			int f0 = 1;
			repn(j, 1, n) if (a[j].s[x][y] == 'X') f0 = 0;
			// 1
			int f1 = 1;
			repn(j, 1, n) if (a[j].s[x][y] == '.') f1 = 0;
			tmp[x][y] = f0 + f1 * 2 + fw * 4;
			if (tmp[x][y] == 0) {
				ff = 1;
				break;
			}
		}
		if (ff) continue;
		flag = 1;
		rep(i, 0, 7) rep(j, 0, 21) f[i][j] |= tmp[i][j];
	}
	if (flag) ans.print();
	else cout << "impossible\n";
	return 0;
}