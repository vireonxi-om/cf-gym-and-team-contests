// Problem: 
// URL: https://codeforces.com/gym/471068/problem/G
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

const int N = 2100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, k, f[N][N], pre[N][N], ans, cas, l[N], r[N];
deque<int> que[N];
vector<int> g[N];
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		repn(i, 1, n) g[i].clear();
		repn(i, 1, m) cin >> l[i] >> r[i];
		
		repn(i, 1, m) {
			int leni = r[i] - l[i] + 1;
			int flag = 0;
			repn(j, 1, m) {
				if (i == j) continue;
				int lenj = r[j] - l[j] + 1;
				if (leni >= lenj) continue;
				if (l[i] >= l[j] && r[i] <= r[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) g[r[i]].pb(l[i]);
		}
		memset(pre, 0, sizeof(pre));
		memset(f, 0, sizeof(f));
		repn(i, 1, m) while (!que[i].empty()) que[i].pop_front();
		repn(i, 1, n) {
			for (auto l: g[i]) {
				int len = i - l + 1, r = i;
				repn(j, 1, k) f[i][j] = max(f[i][j], pre[l - 1][j - 1] + len);
				repn(j, 2, k) {
					while (!que[j - 1].empty()) {
						if (que[j - 1].front() < l) que[j - 1].pop_front();
						else break;
					}
					if (!que[j - 1].empty()) {
						int id = que[j - 1].front();
						f[i][j] = max(f[i][j], f[id][j - 1] + r - id);
					}
				}
			}
			repn(j, 1, k) {
				while (!que[j].empty()) {
					int id = que[j].back();
					if (f[id][j] - id <= f[i][j] - i) que[j].pop_back();
					else break;
				}
				que[j].push_back(i);
				pre[i][j] = max(pre[i - 1][j], f[i][j]);
			}
		}
		ans = 0;
		repn(i, 1, n) ans = max(ans, f[i][k]);
		cout << "Case #" << ++cas << ": " << ans << "\n";
	}
	return 0;
}