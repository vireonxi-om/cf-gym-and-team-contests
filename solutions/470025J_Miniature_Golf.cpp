// Problem: Miniature Golf
// URL: https://codeforces.com/gym/470025/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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

const int N = 510;
const int M = 11000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, f[N][M];
LL sum[N];
vector<PII> eve;
void add(int l, int r) {
	eve.pb({l, 1});
	eve.pb({r + 1, -1});
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		repn(j, 1, m) cin >> f[i][j], sum[i] += f[i][j];
		sort(f[i] + 1, f[i] + m + 1);
	}
	repn(i, 1, n) {
		eve.clear();
		repn(j, 1, n) if (j != i) {
			LL si = sum[i];
			LL sj = sum[j];
			int ti = m, tj = m, cur = inf;
			LL l, r;
			while (cur >= 1) {
				if (tj == 0 || f[i][ti] >= f[j][tj]) l = f[i][ti];
				else l = f[j][tj];
				r = cur;
				if (l <= r) {
					int ni = m - ti, nj = m - tj;
					if (ni == nj) {
						if (si < sj) add(l, r);
					}
					else if (ni < nj) {
						if (si >= sj);
						else {
							LL t = (sj - si - 1) / (nj - ni);
							add(max(r - t, l), r);
						}
					}
					else {
						if (si < sj) add(l, r);
						else {
							LL t = (si - sj) / (ni - nj) + 1;
							if (r - t >= l) add(l, r - t);
						}
					}
					si -= (r - l + 1) * ni;
					sj -= (r - l + 1) * nj;
				}
				if (tj == 0 || f[i][ti] >= f[j][tj]) ti--;
				else tj--;
				cur = l - 1;
			}
		}
		sort(all(eve));
		int cur = 0, mx = 0;
		for (auto p: eve) cur += p.se, mx = max(mx, cur);
		cout << n - mx << "\n";
	}
	return 0;
}