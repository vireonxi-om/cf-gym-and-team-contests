// Problem: Mission Improbable
// URL: https://codeforces.com/gym/482684/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
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

const int N = 110;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

int n, m;
LL a[N][N], sum, ans, row[N], col[N];
vector<PII> tmp;
set<int> S;

int b[N], c[N];
int uN, vN, g[N][N], linker[N];
bool used[N];
bool dfs(int u) {
	rep(v, 0, vN) if (g[u][v] && !used[v]) {
		used[v] = true;
		if (linker[v] == -1 || dfs(linker[v])) {
			linker[v] = u;
			return true;
		}
	}
	return false;
}
int hungary() {
	int res = 0;
	memset(linker, -1, sizeof(linker));
	rep(u, 0, uN) {
		memset(used, 0, sizeof(used));
		if (dfs(u)) res++;
	}
	return res;
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) repn(j, 1, m) {
		cin >> a[i][j], sum += a[i][j], row[i] = max(row[i], a[i][j]), col[j] = max(col[j], a[i][j]);
		S.insert(a[i][j]);
		ans += (a[i][j] > 0);
	}
	for (auto v: S) {
		if (v <= 1) continue;
		uN = vN = 0;
		repn(i, 1, n) if (row[i] == v) b[uN++] = i;
		repn(i, 1, m) if (col[i] == v) c[vN++] = i;
		rep(i, 0, uN) rep(j, 0, vN) g[i][j] = (a[b[i]][c[j]] > 0);
		ans += (uN + vN - hungary()) * (LL)(v - 1);
	}
	
	cout << sum - ans << "\n";
	return 0;
}