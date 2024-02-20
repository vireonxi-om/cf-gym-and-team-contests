// Problem: Stop, Yesterday Please No More
// URL: https://codeforces.com/gym/104128/problem/A
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

const int N = 3000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, k, a[N][N];
string s;
PII h; 

void solve() {
	cin >> n >> m >> k;
	cin >> s;
	h = mp(n, m);
	repn(i, 0, 2 * n) {
		repn(j, 0, 2 * m) a[i][j] = 0;
	}
	PII st = h;
	a[n][m] = 1;
	for (auto x : s) {
		if (x == 'U') st.fi ++;
		if (x == 'D') st.fi --;
		if (x == 'L') st.se ++;
		if (x == 'R') st.se --;
		if (st.fi <= 2 * n && st.fi >= 0 && st.se <= 2 * m && st.se >= 0) {
			a[st.fi][st.se] = 1;
		}
	}
	repn(i, 0, 2 * n) {
		repn(j, 0, 2 * m) {
			if (i > 0) a[i][j] += a[i - 1][j];
			if (j > 0) a[i][j] += a[i][j - 1];
			if (i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
		}
	}
	int u = 1, d = n, l = 1, r = m;
	int num1 = 0, num2 = 0, m1 = 0, m2 = 0, m3 = 0, m4 = 0; 
	for (auto x : s) {
		if (x == 'U') num1 --; 
		else if (x == 'D') num1 ++;
		else if (x == 'L') num2 --;
		else num2 ++;
		m1 = min(m1, num1); m2 = max(m2, num1);
		m3 = min(m3, num2); m4 = max(m4, num2);
	} 
	u -= m1; d -= m2; l -= m3; r -= m4;
	//cout << u << " " << d << " " << l << " " << r << "\n";
	int ans = 0, tot = (d - u + 1) * (r - l + 1);
	if (u <= d && l <= r) {
		repn(i, 1, n) {
			repn(j, 1, m) {
				PII ul = mp(u, l), dr = mp(d, r);
				ul.fi = ul.fi - i + n; ul.se = ul.se - j + m;
				dr.fi = dr.fi - i + n; dr.se = dr.se - j + m;
				//cout << i << " " << j << "\n";
				//cout << ul.fi << " " << ul.se << " " << dr.fi << " " << dr.se << "\n";
				int sum = a[dr.fi][dr.se];
				if (ul.fi) sum -= a[ul.fi - 1][dr.se];
				if (ul.se) sum -= a[dr.fi][ul.se - 1];
				if (ul.fi && ul.se) sum += a[ul.fi - 1][ul.se - 1];
				if (sum + k == tot) ans ++;
			}
		}
	} 
	else {
		if (k == 0) ans = n * m; 
		else ans = 0;
	}
	cout << ans << "\n";
} 

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



