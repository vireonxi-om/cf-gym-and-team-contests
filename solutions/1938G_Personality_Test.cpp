// Problem: Personality Test
// URL: https://codeforces.com/problemset/problem/1938/G
// Rating: 2300
// Tags: none (gym/team contest)
// Language: C++20 (GCC 11-64)
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

const int N = 5100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, k, x, y, tx, ty;
short f[26][N], len[26], num[N][N], w[N][N];
int check(int l, int r) {
	repn(i, l, r) rep(j, l, i) num[i][j] = 0;
	rep(j, 0, m) {
		memset(len, 0, sizeof(len));
		repn(i, l, r) {
			if (w[i][j] == -1) continue;
			int x = w[i][j];
			rep(l, 0, len[x]) {
				num[i][f[x][l]]++;
				if (num[i][f[x][l]] == k) {
					tx = f[x][l];
					ty = i;
					return 1;
				}
			}
			f[x][len[x]++] = i;
		}
	}
	return 0;
}
int main() {
	IO;
	cin >> n >> m >> k;
	repn(i, 1, n) {
		string s;
		cin >> s;
		rep(j, 0, m) {
			if (s[j] == '.') w[i][j] = -1;
			else w[i][j] = s[j] - 'A';
		}
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(1, mid)) r = ty - 1, ans = ty;
		else l = mid + 1;
	}
	y = ans;
	if (ans == -1) {
		cout << ans << "\n";
		return 0;
	}
	l = 1, r = y - 1, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid, y)) l = tx + 1, ans = tx;
		else r = mid - 1;
	}
	x = ans;
	cout << x << " " << y << "\n";
	return 0;
}