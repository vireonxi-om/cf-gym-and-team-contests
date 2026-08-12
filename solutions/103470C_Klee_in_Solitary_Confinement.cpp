// Problem: Klee in Solitary Confinement
// URL: https://codeforces.com/gym/103470/problem/C
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

int n, k, num;
unordered_map<int, int> S;
vector<int> f[N];
int a[N], b[N], c[N], cnt, ans;
int main() {
	IO;
	cin >> n >> k;
	if (k == 0) {
		int ans = 0;
		repn(i, 1, n) {
			int x;
			cin >> x;
			S[x]++;
			ans = max(ans, S[x]);
		}
		cout << ans << "\n";
		return 0;
	}
	repn(i, 1, n) {
		int x;
		cin >> x;
		if (!S.count(x)) S[x] = ++num, a[num] = x;
		if (!S.count(x + k)) S[x + k] = ++num, a[num] = x + k;
		f[S[x]].pb(i);
		c[i] = S[x];
	}
	repn(i, 1, num) {
		int x = a[i];
		int y = a[i] + k;
		if (!S.count(y)) continue;
		int idx = S[x], idy = S[y];
		cnt = 0;
		int cnt = f[idx].size() + f[idy].size();
		int hx = 0, hy = 0;
		repn(j, 1, cnt) {
			if (hx == f[idx].size()) b[j] = f[idy][hy++];
			else if (hy == f[idy].size()) b[j] = f[idx][hx++];
			else if (f[idx][hx] < f[idy][hy]) b[j] = f[idx][hx++];
			else b[j] = f[idy][hy++];
		}
		int res = -inf, mn = 0, cur = 0;
		repn(j, 1, cnt) {
			if (c[b[j]] == idx) cur++;
			else cur--;
			res = max(res, cur - mn);
			mn = min(mn, cur);
		}
		ans = max(ans, res + (int)f[idy].size());
	}
	cout << ans << "\n";
	return 0;
}