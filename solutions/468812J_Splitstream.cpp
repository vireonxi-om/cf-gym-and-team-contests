// Problem: Splitstream
// URL: https://codeforces.com/gym/468812/problem/J
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int m, n, q;
int tp[N], len[N], cnt;
struct node {
	int op, s1, s2; // 0 - merge, 1 - split l, 2 - split r
}src[N];
int cal(int x) {
	if (len[x] != -1) return len[x];
	if (x == 1) return len[x] = m;
	int op = src[x].op;
	if (op == 0) {
		int len1 = cal(src[x].s1);
		int len2 = cal(src[x].s2);
		return len[x] = len1 + len2;
	}
	else if (op == 1) {
		int l = cal(src[x].s1);
		return len[x] = (l + 1) / 2;
	}
	else {
		int l = cal(src[x].s1);
		return len[x] = l / 2;
	}
}
int ask(int x, int k) {
	if (x == 1) return k;
	int op = src[x].op;
	if (op == 0) {
		int len1 = len[src[x].s1];
		int len2 = len[src[x].s2];
		if (len1 >= len2) {
			if (k <= len2 * 2) {
				int l = (k + 1) / 2;
				if (k & 1) return ask(src[x].s1, l);
				else return ask(src[x].s2, l);
			}
			else {
				k -= len2 * 2;
				return ask(src[x].s1, len2 + k);
			}
		}
		else {
			if (k <= len1 * 2) {
				int l = (k + 1) / 2;
				if (k & 1) return ask(src[x].s1, l);
				else return ask(src[x].s2, l);
			}
			else {
				k -= len1 * 2;
				return ask(src[x].s2, len1 + k);
			}
		}
	}
	else if (op == 1) {
		return ask(src[x].s1, k * 2 - 1);
	}
	else {
		return ask(src[x].s1, k * 2);
	}
}
int main() {
	IO;
	memset(len, -1, sizeof(len));
	cin >> m >> n >> q;
	repn(i, 1, n) {
		string op;
		int u, v, w;
		cin >> op >> u >> v >> w;
		if (op == "S") {
			src[v] = {1, u, 0};
			src[w] = {2, u, 0};
		}
		else src[w] = {0, u, v};
	}
	rep(i, 2, N) if (src[i].s1) len[i] = cal(i);
	while (q--) {
		int id, k;
		cin >> id >> k;
		if (k > len[id]) {
			cout << "none\n";
			continue;
		}
		cout << ask(id, k) << "\n";
	}
	return 0;
}