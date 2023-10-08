// Problem: AppendAppendAppend
// URL: https://codeforces.com/gym/104114/problem/A
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

const int N = 510000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

string s, t;
int nxt[N][26];



int main() {
	IO;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	rep(j, 0, 26) nxt[n][j] = -1;
	per(i, 0, n) {
		rep(j, 0, 26) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	int cur = 0, pos = 0, ans = 1;
	while (pos < m) {
		if (cur >= n) {
			cur = 0; ans ++; continue;
		}
		if (nxt[cur][t[pos] - 'a'] == -1) {
			cur = 0; ans ++; continue;
		} 
		cur = nxt[cur][t[pos] - 'a'] + 1; pos ++;
	}
	cout << ans << "\n";
	return 0;
}



