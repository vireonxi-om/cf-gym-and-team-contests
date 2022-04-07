// Problem: Xingqiu's Joke
// URL: https://codeforces.com/gym/103470/problem/J
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, a, b;
int p[N], cnt, ans;

map<PII, int> S;
priority_queue<int> q;

int dfs(int x, int d) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (S.count(mp(x, d))) return S[mp(x, d)];
	int res = x - 1;
	repn(i, 1, cnt) {
		int prim = p[i];
		if (d % prim == 0) {
			if (x % prim == 0) res = min(res, 1 + dfs(x / prim, d / prim));
			else {
				// up
				int cost1 = (x / prim + 1) * prim - x + 1;
				// down
				int cost2 = x - x / prim * prim + 1;
				res = min(res, cost1 + dfs(x / prim + 1, d / prim));	
				res = min(res, cost2 + dfs(x / prim, d / prim));
			}
		}
	}
	return S[mp(x, d)] = res;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		int d = b - a;
		cnt = 0;
		for (int i = 2; i * i <= d; i++) {
			if (d % i == 0) {
				p[++cnt] = i;
				while (d % i == 0) d /= i;
			}
		}
		if (d > 1) p[++cnt] = d;
		S.clear();
		cout << dfs(a, b - a) << "\n";
	}
	return 0;
}