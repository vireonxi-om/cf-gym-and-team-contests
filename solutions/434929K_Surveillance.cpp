// Problem: Surveillance
// URL: https://codeforces.com/gym/434929/problem/K
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
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
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 2100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

const int B = 22;
int n, m, f[N][B], ans = inf;

int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int a, b;
		cin >> a >> b;
		if (b < a) b += n;
		f[a][0] = max(f[a][0], b + 1);
	}
	repn(i, 2, n + n) f[i][0] = max(f[i][0], f[i - 1][0]);
	repn(i, 1, 20) repn(j, 1, n + n) f[j][i] = f[f[j][i - 1]][i - 1];
	repn(i, 1, n) {
		int cur = i, res = 0;
		per(j, 0, 20) if (f[cur][j] < i + n) cur = f[cur][j], res += 1 << j;
		cur = f[cur][0], res++;
		if (cur >= i + n) ans = min(ans, res);
	}
	if (ans == inf) cout << "impossible\n";
	else cout << ans << "\n";
	return 0;
}