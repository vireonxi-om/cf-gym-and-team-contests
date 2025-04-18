// Problem: Cut Inequality Down
// URL: https://codeforces.com/gym/102428/problem/C
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;
const int L = 400;
int n, m;
LL l, r;
LL a[N], f[N][3];
LL cal(LL x, int st, int ed) {
	rep(i, st, ed) {
		x += a[i];
		x = max(x, l);
		x = min(x, r);
	}
	return x;
}
int main()
{
	IO;
	cin >> n >> l >> r;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n / L) {
		f[i][0] = cal(l, i * L, (i + 1) * L);
		f[i][1] = cal(r, i * L, (i + 1) * L);
		rep(j, i * L, (i + 1) * L) f[i][2] += a[j];
	}
	int q;
	cin >> q;
	while (q--) {
		int st, ed;
		LL x;
		cin >> st >> ed >> x;
		st--;
		if (ed - st <= 2 * L) cout << cal(x, st, ed) << "\n";
		else {
			int fidx = (st + L - 1 ) / L;
			int sidx = ed / L;
			x = cal(x, st, fidx * L);
			rep(i, fidx, sidx) {
				x += f[i][2];
				x = max(x, f[i][0]);
				x = min(x, f[i][1]);
			}
			x = cal(x, sidx * L, ed);
			cout << x << "\n";
		}
	}
	return 0;
}