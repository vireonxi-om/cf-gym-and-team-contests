// Problem: A Color Game
// URL: https://codeforces.com/gym/102835/problem/E
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

const int N = 510;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int f[N][N], g[N][N];
string s;
int main()
{
	IO;
	cin >> s >> m;
	n = s.size();
	pern(i, 1, n) {
		f[i][i] = 1;
		repn(j, i + 1, n) {
			f[i][j] = -1;
			if (s[j - 1] == s[i - 1] && f[i][j - 1] != -1) f[i][j] = max(f[i][j], f[i][j - 1] + 1);
			rep(k, i, j) if (g[k + 1][j]) f[i][j] = max(f[i][j], f[i][k]);
		}
		repn(j, i, n) if (f[i][j] >= m) g[i][j] = 1;
	}
	if (g[1][n]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}