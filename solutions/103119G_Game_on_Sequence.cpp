// Problem: Game on Sequence
// URL: https://codeforces.com/gym/103119/problem/G
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

const int N = 256;
const int M = 410000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, a[M];
vector<int> g[N], b;
int dp[256];
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> a[i];
		g[a[i]].pb(i);
	}
	while (m--) {
		int op, k;
		cin >> op >> k;
		if (op == 1) {
			a[++n] = k;
			g[k].pb(n);
		}
		else {
			int val = a[k];
			if (g[val][g[val].size() - 1] != k) cout << "Grammy\n";
			else {
				b.clear();
				memset(dp, -1, sizeof(dp));
				rep(i, 0, 256) if (g[i].size() > 0) b.pb(g[i][g[i].size() - 1]);
				sort(all(b));
				reverse(all(b));
				for (auto x: b) {
					int flag = 0;
					int val = a[x];
					rep(i, 0, 8) {
						int nxt = val ^ (1 << i);
						if (dp[nxt] == -1) continue;
						if (dp[nxt] == 1) continue;
						flag = 1;
						break;
					}
					dp[val] = flag;
				}
				if (dp[val]) cout << "Grammy\n";
				else cout << "Alice\n";
			}
		}
	}
	return 0;
}