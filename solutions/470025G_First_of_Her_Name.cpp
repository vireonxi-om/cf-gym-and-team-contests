// Problem: First of Her Name
// URL: https://codeforces.com/gym/470025/problem/G
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;
const int maxn = 4100000;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, q, lpos[N];
struct SAM {
	struct node {
		int ch[26], par, val;
		node (int val = 0) : par(0), val(val) { memset(ch, 0, sizeof(ch)); }
	} sam[maxn];
	int m;
	int sz[maxn], rs[maxn], h[maxn], b[maxn], du[maxn];
	int append(int w, int last) {
		int p = last, np, q, nq;
		sam[last = np = ++m] = node(sam[p].val + 1);
		rs[np] = 1;
		while (p && sam[p].ch[w] == 0) sam[p].ch[w] = np, p = sam[p].par;
		if (p == 0) { sam[np].par = 1; return last; }
		q = sam[p].ch[w];
		if (sam[p].val + 1 == sam[q].val) sam[np].par = q;
		else {
			sam[nq = ++m] = sam[q];
			sam[nq].val = sam[p].val + 1;
			sam[q].par = sam[np].par = nq;
			while (p && sam[p].ch[w] == q) sam[p].ch[w] = nq, p = sam[p].par;
		}
		return last;
	}
	void init() {
		queue<int> que;
		repn(i, 1, m) if (sam[i].par) du[sam[i].par]++;
		repn(i, 1, m) if (du[i] == 0) que.push(i);
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			rs[sam[u].par] += rs[u];
			du[sam[u].par]--;
			if (du[sam[u].par] == 0) que.push(sam[u].par);
		}
		// repn(i, 1, m) cout << rs[i] << endl; 
	}
	int ask(string s) {
		int u = 1;
		for (auto x: s) {
			if (sam[u].ch[x - 'A']) u = sam[u].ch[x - 'A'];
			else return 0;
		}
		return rs[u];
	}
}A;

int main() {
	IO;
	cin >> n >> q;
	A.sam[A.m = 1] = SAM::node(0);
	lpos[0] = 1;
	repn(i, 1, n) {
		string s;
		int p;
		cin >> s >> p;
		int x = s[0] - 'A';
		lpos[i] = A.append(x, lpos[p]);
	}
	A.init();
	while (q--) {
		string s;
		cin >> s;
		reverse(all(s));
		cout << A.ask(s) << "\n";
	}
	return 0;
}