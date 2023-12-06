// Problem: Future Generation
// URL: https://codeforces.com/gym/102001/problem/J
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

const int N = 16;
const int M = 1 << 15;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, len[N], num[N];
string s[N];
vector<string> g[N];
int dp[N][M], head[N][N];
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> s[i];
		len[i] = s[i].size();
		rep(j, 1, 1 << len[i]) {
			string tmp = "";
			rep(k, 0, len[i])
				if (j >> k & 1) tmp += s[i][k];
			g[i].pb(tmp);
		}
		sort(all(g[i]));
		num[i] = g[i].size();
	}
	memset(dp, -1, sizeof(dp));
	rep(i, 0, num[1]) {
		dp[1][i] = g[1][i].size();
	}
	rep(i, 1, n) {
		rep(j, 0, num[i]) {
			if (dp[i][j] == -1) continue;
			repn(k, 1, len[i + 1]) {
				while (head[i + 1][k] < num[i + 1] && (g[i + 1][head[i + 1][k]] <= g[i][j] || g[i + 1][head[i + 1][k]].size() != k)) head[i + 1][k]++;
				if (head[i + 1][k] != num[i + 1]) dp[i + 1][head[i + 1][k]] = max(dp[i + 1][head[i + 1][k]], dp[i][j] + k);
			}
		}
	}
	int ans = -1;
	rep(i, 0, num[n]) ans = max(ans, dp[n][i]);
	cout << ans << "\n";
	return 0;
}