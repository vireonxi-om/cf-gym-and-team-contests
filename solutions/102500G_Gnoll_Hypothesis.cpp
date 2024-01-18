// Problem: Gnoll Hypothesis
// URL: https://codeforces.com/gym/102500/problem/G
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const int INF = 1e8;
const double eps = 1e-9;

int n, k;
double a[N], dp[N];
int main() {
	IO;
	cin >> n >> k;
	dp[0] = (double)k / (double)n;
	int all = n - 1, left = k - 1;
	rep(i, 1, n) {
		dp[i] = dp[i - 1] * max(0.0, (double)(all - left) / (double)all);
		all--;
	}
	repn(i, 1, n) cin >> a[i], a[i + n] = a[i];
	repn(i, 1, n) {
		double sum = 0, p = dp[0];
		int cnt = 0;
		pern(j, i + 1, i + n) {
			sum += dp[cnt] * a[j];
			cnt++;
		}
		printf("%.10f", sum);
		if (i != n) printf(" ");
		else printf("\n");
	}
	return 0;
}