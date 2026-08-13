// Problem: Keystroke
// URL: https://codeforces.com/gym/102835/problem/M
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, n, m, nrow, ncol;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		int row = 0, col = 0;
		while (n--) {
			int x;
			cin >> x;
			row |= 1 << x;
		}
		while (m--) {
			int x;
			cin >> x;
			col |= 1 << x;
		}
		int ans = 0;
		rep(i, 0, 1 << 4) {
			int a1 = (i >> 0) & 1;
			int a2 = (i >> 1) & 1;
			int a3 = (i >> 2) & 1;
			int a4 = (i >> 3) & 1;
			int mrow = 0, mcol = 0;
			if (a1) mrow |= 1, mcol |= 1;
			if (a2) mrow |= 1, mcol |= 2;
			if (a3) mrow |= 2, mcol |= 1;
			if (a4) mrow |= 2, mcol |= 2;
			if (mrow == row && mcol == col) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}