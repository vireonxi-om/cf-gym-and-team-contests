// Problem: Posterize
// URL: https://codeforces.com/gym/482684/problem/F
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

const int N = 260;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

int n, d;
LL dp[N][N], sum[3][N];
LL cal(int l, int r, LL v) {
	LL res = sum[2][r] - sum[2][l - 1];
	res -= 2 * (sum[1][r] - sum[1][l - 1]) * v;
	res += (sum[0][r] - sum[0][l - 1]) * v * v;
	return res;
}
int main() {
	IO;
	cin >> n >> d;
	repn(i, 1, n) {
		LL r, p;
		cin >> r >> p;
		r++;
		sum[0][r] += p;
		sum[1][r] += p * r;
		sum[2][r] += p * r * r;
	}
	repn(i, 1, 256) rep(j, 0, 3) sum[j][i] += sum[j][i - 1];
	repn(i, 1, 256) dp[i][1] = cal(1, i, i);
	repn(j, 2, d) repn(i, j, 256) {
		dp[i][j] = INF;
		repn(k, j - 1, i - 1) {
			int mid = (i + k) / 2;
			dp[i][j] = min(dp[i][j], dp[k][j - 1] + cal(k, mid, k) + cal(mid + 1, i, i)); 
		}
	}
	LL ans = INF;
	repn(i, d, 256) {
		ans = min(ans, dp[i][d] + cal(i + 1, 256, i));
	}
	cout << ans << "\n";
	return 0;
}