// Problem: Improve SPAM
// URL: https://codeforces.com/gym/102428/problem/I
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int du[N], pp[N], ansb;
LL ansa;
vector<int> g[N];
queue<int> que;
LL dp[N];
void dfs(int x) {
	pp[x] = 1;
	for (auto y: g[x]) {
		du[y]++;
		if (!pp[y]) dfs(y);
	}
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			g[i].pb(x);
		}
	}
	dfs(1);
	que.push(1);
	dp[1] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (now > m) {
			ansb++;
			ansa = (ansa + dp[now]) % mod;
		}
		for (auto y: g[now]) {
			dp[y] = (dp[y] + dp[now]) % mod;
			du[y]--;
			if (du[y] == 0) que.push(y);
		}
	}
	cout << ansa << " " << ansb << "\n";
	return 0;
}