// Problem: Bit Counting Sequence
// URL: https://codeforces.com/problemset/problem/1938/C
// Rating: 1900
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, a[N], b[100];
void work(int x) {
	b[0] = x;
	int l = 1;
	rep(i, 1, n) {
		b[0]++;
		int p = 0;
		while (b[p] == 2 && p < l) {
			b[p] = 0;
			p++;
			b[p]++;
		}
		if (p == l) {
			int d = a[i] - a[i + 1] + 1 - l;
			if (d < 0) {
				cout << "-1\n";
				return;
			}
			rep(j, 0, d) b[p] = 0, p++;
			b[p] = 1;
			l = p + 1;
		}
	}
	LL v = 0;
	per(i, 0, l) v = v * 2 + b[i];
	
	LL xx = v - n + 1;
	int num = a[1] - __builtin_popcountll(xx);
	repn(i, 2, n) if (a[i] - __builtin_popcountll(xx + i - 1) != num) {
		cout << "-1\n";
		return;
	}
	repn(i, 1, num) xx |= 1LL << l, l++;
	repn(i, 1, n) if (__builtin_popcountll(xx + i - 1) != a[i]) {
		cout << "-1\n";
		return;
	}
	cout << xx << "\n";
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		memset(b, 0, sizeof(b));
		cin >> n;
		repn(i, 1, n) cin >> a[i];
		if (n == 1) {
			LL res = 0;
			rep(i, 0, a[1]) res |= 1LL << i;
			cout << res << "\n";
			continue;
		}
		if (a[1] + 1 == a[2]) work(0);
		else work(1);
	}
	return 0;
}