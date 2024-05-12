// Problem: Comma Sprinkler
// URL: https://codeforces.com/gym/102482/problem/B
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
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> PII;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf  = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int st, n, m, sf[M], ef[M], pp[M], idx[M], cp[M][2];
string s, t[M];
map<string, int> S;
vector<int> h[M];
queue<PII> que;
int main() {
	IO;
	while (cin >> s) {
		n++;
		t[n] = s;
		if (st == 0) sf[n] = 1, st = 1;
		if (s[s.size() - 1] == '.') t[n] = s.substr(0, s.size() - 1), ef[n] = 1, st = 0;
		if (s[s.size() - 1] == ',') t[n] = s.substr(0, s.size() - 1), pp[n] = 1;
		if (!S.count(t[n])) idx[n] = S[t[n]] = ++m;
		else idx[n] = S[t[n]];
		h[idx[n]].pb(n);
	}
	repn(i, 1, n) {
		if (!pp[i]) continue;
		int id = idx[i];
		if (!cp[id][1]) que.push(mp(id, 1)), cp[id][1] = 1;
		id = idx[i + 1];
		if (!cp[id][0]) que.push(mp(id, 0)), cp[id][0] = 1;
	}
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		int id = now.fi, tp = now.se;
		if (tp == 0) {
			for (auto x: h[id]) {
				if (sf[x]) continue;
				if (pp[x - 1]) continue;
				pp[x - 1] = 1;
				if (!cp[idx[x - 1]][1]) que.push(mp(idx[x - 1], 1)), cp[idx[x - 1]][1] = 1;
			}
		}
		else {
			for (auto x: h[id]) {
				if (ef[x]) continue;
				if (pp[x]) continue;
				pp[x] = 1;
				if (!cp[idx[x + 1]][0]) que.push(mp(idx[x + 1], 0)), cp[idx[x + 1]][0] = 1;
			}
		}
	}
	repn(i, 1, n) {
		cout << t[i];
		if (pp[i]) cout << ",";
		else if (ef[i]) cout << ".";
		cout << " \n"[i == n];
	}
	return 0;
}