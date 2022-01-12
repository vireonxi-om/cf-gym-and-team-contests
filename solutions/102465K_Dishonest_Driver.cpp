// Problem: Dishonest Driver
// URL: https://codeforces.com/gym/102465/problem/K
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

const int N = 710;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
char s[N];
int dp[N][N];
ull hsh[N][N];
int main()
{
	IO;
	scanf("%d", &n);
	scanf("%s", s + 1);
	repn(i, 1, n) {
		repn(j, i, n) {
			hsh[i][j] = hsh[i][j - 1] * 37ull + s[j] - 'a' + 1;
		}
	}
	repn(i, 1, n) dp[i][i] = 1;
	repn(i, 2, n) {
		repn(l, 1, n - i + 1) {
			int r = l + i - 1;
			dp[l][r] = r - l + 1;
			repn(k, l, r - 1) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			repn(d, 1, i - 1) {
				if (i % d == 0) {
					ull cur = hsh[l][l + d - 1];
					int flag = 0;
					for (int k = l + d; k <= r; k += d) {
						if (hsh[k][k + d - 1] != cur) flag = 1;
					}
					if (!flag) dp[l][r] = min(dp[l][r], dp[l][l + d - 1]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}