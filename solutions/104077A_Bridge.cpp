// Problem: Bridge
// URL: https://codeforces.com/gym/104077/problem/A
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

int n, m, q;
struct SplayNode {
	int data, size, c[2], fa, rev;
}tree[M];
int SplaySum;

void downdate(int x) {
	if (!tree[x].rev) return;
	tree[x].rev = 0, tree[tree[x].c[0]].rev ^= 1, tree[tree[x].c[1]].rev ^= 1;
	swap(tree[x].c[0], tree[x].c[1]);
}
void update(int x) {
	tree[x].size = tree[tree[x].c[0]].size + tree[tree[x].c[1]].size + 1;
}
void rotate(int x, int p) {
	int y = tree[x].fa;
	if (tree[x].c[p]) tree[tree[x].c[p]].fa = y;
    tree[y].c[p ^ 1] = tree[x].c[p], tree[x].c[p] = y;
    tree[x].fa = tree[y].fa, tree[y].fa = x;
    if (tree[x].fa) {
		if (y == tree[tree[x].fa].c[0]) tree[tree[x].fa].c[0] = x;
        else tree[tree[x].fa].c[1] = x;
    }
    update(y), update(x);
}
void splay(int &root, int x, int p) {
	while (tree[x].fa != 0) {
		int y = tree[x].fa, z = tree[y].fa;
		downdate(z), downdate(y), downdate(x);
		if (z == 0 || (tree[z].fa == 0 && p)) {
			if (p && z == 0) break;
			if (tree[y].c[0] == x) rotate(x, 1);
			else rotate(x, 0);
			break;
		}
		int a = y == tree[z].c[0] ? 1: 0, b = x == tree[y].c[0] ? 1: 0;
		if (a ^ b)  rotate(x, b), rotate(x, a);
		else rotate(y, a), rotate(x, b);
	}
	if (!p) root = x;
}
void maintain(int x) { while (x != 0) update(x), x = tree[x].fa; }
void init(int x, int sum) {
    tree[sum].data = x, tree[sum].fa = 0, tree[sum].size = 1;
    tree[sum].c[0] = 0, tree[sum].c[1] = 0, tree[sum].rev = 0;
}

void insert(int &root, int x) {
	init(x, ++SplaySum);
	if (root == 0) { root = SplaySum; return; }
	int y = root;
	while (tree[y].c[1]) y = tree[y].c[1];
	splay(root, y, 0), downdate(y);
	if (tree[y].c[1] == 0) tree[y].c[1] = SplaySum, tree[SplaySum].fa = y;
	else {
		y = tree[y].c[1]; downdate(y);
		while (tree[y].c[0]) { y = tree[y].c[0]; downdate(y);}
		tree[y].c[0] = SplaySum, tree[SplaySum].fa = y;
	}
	maintain(SplaySum), splay(root, SplaySum, 0);
}
int a[N], b[N], op[N], pos, rt[N];
set<int> row[N];
map<PII, int> S;
void setp(int x, int y) {
	row[x].insert(y);
}
int main() {
	IO;
	cin >> n >> m >> q;
	repn(i, 1, n) setp(i, m + 1), setp(i, 1);
	repn(i, 1, q) {
		cin >> op[i];
		if (op[i] == 1) {
			cin >> a[i] >> b[i];
			setp(a[i], b[i]);
			setp(a[i] + 1, b[i]);
			setp(a[i], b[i] + 1);
			setp(a[i] + 1, b[i] + 1);
		}
		else cin >> a[i];
	}
	repn(i, 1, n) {
		auto it = row[i].begin();
		while (it != row[i].end()) {
			insert(rt[i], i);
			S[mp(i, *it)] = SplaySum;
			it++;
		}
	}
	repn(i, 1, q) {
		if (op[i] == 1) {
			int idx = S[mp(a[i], b[i] + 1)], idy = S[mp(a[i] + 1, b[i] + 1)];
			int ids = S[mp(a[i], b[i])], idt = S[mp(a[i] + 1, b[i])];
			int rs = ids, rt = idt;
			while (tree[rs].fa) rs = tree[rs].fa;
			while (tree[rt].fa) rt = tree[rt].fa;
			assert(idx > 0), assert(idy > 0), assert(ids > 0), assert(idt > 0);
			splay(rs, idx, 0);
			splay(rt, idy, 0);
			splay(rs, ids, 1);
			splay(rt, idt, 1);
			swap(tree[ids].fa, tree[idt].fa);
			swap(tree[idx].c[0], tree[idy].c[0]);
			update(idx), update(idy);
		}
		else {
			int cur = S[mp(a[i], 1)];
			while (tree[cur].fa) cur = tree[cur].fa;
			while (tree[cur].c[1]) cur = tree[cur].c[1];
			cout << tree[cur].data << "\n";
		}
	}
	return 0;
}