// Problem: Down We Dig
// URL: https://codeforces.com/gym/102896/problem/D
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

const int N = 310000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
string s[N];
vector<int> g[N];
int dp[N][256];
int st[20];
int check(int x, int y) {
	int dis = y - x;
	int comm = 0;
	rep(i, 0, 8) if (s[x][i] == s[y][i]) comm++;
	return comm >= dis;
}
int dfs(int row, int state) {
	if (dp[row][state] != -1) return dp[row][state];
	int flag = 0;
	for (auto x: g[row]) {
		if ((state >> x & 1) == 0) flag = 1;
	}
	if (row == 1) {
		if (flag) return dp[row][state] = 1;
		else return dp[row][state] = 2;
	}
	return dp[row][state] = dfs(row - 1, ((state * 2) & 255) + flag);
}
int main()
{
	IO;
	cin >> n;
	repn(i, 1, min(n, 8)) {
		cin >> s[i];
		repn(j, max(1, i - 8), i - 1) {
			if (check(j, i)) g[j].pb(i - j - 1);
		}
		memset(st, 0, sizeof(st));
		pern(j, 1, i) {
			for (auto x: g[j]) {
				if (st[j + 1 + x] == 0) st[j] = 1;
			}
		}
		if (st[1] == 0) cout << "2";
		else cout << "1";
	}
	memset(dp, -1, sizeof(dp));
	repn(i, 9, n) {
		cin >> s[i];
		repn(j, max(1, i - 8), i - 1) {
			if (check(j, i)) g[j].pb(i - j - 1);
		}
		memset(st, 0, sizeof(st));
		int bias = i - 8;
		pern(j, 1, 8) {
			for (auto x: g[bias + j]) {
				if (st[j + 1 + x] == 0) st[j] = 1;
			}
		}
		int state = 0;
		rep(j, 1, 8) if (st[j]) state |= 1 << (j - 1);
		cout << dfs(bias, state);
	}
	cout << "\n";
	return 0;
}