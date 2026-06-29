// Problem: Fabricating Sculptures
// URL: https://codeforces.com/gym/102428/problem/F
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

const int N = 5100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int dp[N][N], sum[N];
int main()
{
	IO;
	cin >> n >> m;
	dp[0][0] = 1;
	repn(i, 1, n) {
		repn(j, i, m) {
			dp[i][j] = (dp[i - 1][j - 1] + sum[j - i]) % mod;
			sum[j] = (sum[j] + dp[i][j]) % mod;
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}