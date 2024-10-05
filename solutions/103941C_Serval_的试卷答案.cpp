// Problem: Serval 的试卷答案
// URL: https://codeforces.com/gym/103941/problem/C
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
const int M = 310000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, q;
string s;
int lz[M], sum[M];
struct node {
	int adj[4][4];
	void shift() {
		int nadj[4][4];
		rep(i, 0, 4) rep(j, 0, 4) {
			nadj[(i + 1) & 3][(j + 1) & 3] = adj[i][j];
		}
		rep(i, 0, 4) rep(j, 0, 4) adj[i][j] = nadj[i][j];
	}
}tr[M];
node operator + (node a, node b) {
	node res;
	rep(i, 0, 4) rep(j, 0, 4) res.adj[i][j] = a.adj[i][j] + b.adj[i][j];
	return res;
}
void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void pushdown(int k) {
	if (lz[k]) {
		lz[k] &= 3;
		repn(i, 1, lz[k]) tr[LC].shift(), tr[RC].shift();
		lz[LC] += lz[k], lz[RC] += lz[k];
		lz[k] = 0;
	}
}
int askc(int k, int l, int r, int a) {
	if (l == r) return sum[k];
	int mid = (l + r) / 2;
	if (a <= mid) return sum[k] + askc(LC, l, mid, a);
	else return sum[k] + askc(RC, mid + 1, r, a);
}
void changec(int k, int l, int r, int a, int b) {
	if (l == a && r == b) {
		sum[k]++;
		return;
	}
	int mid = (l + r) / 2;
	if (b <= mid) changec(LC, l, mid, a, b);
	else if (a > mid) changec(RC, mid + 1, r, a, b);
	else changec(LC, l, mid, a, mid), changec(RC, mid + 1, r, mid + 1, b);
}
void renew(int k, int l, int r, int a) {
	if (l == r) {
		memset(tr[k].adj, 0, sizeof(tr[k].adj));
		if (r == n) return;
		int x = askc(1, 1, n, a) & 3;
		int y = askc(1, 1, n, a + 1) & 3;
		tr[k].adj[x][y] = 1;
		return;
	}
	pushdown(k);
	int mid = (l + r) / 2;
	if (a <= mid) renew(LC, l, mid, a);
	else renew(RC, mid + 1, r, a);
	update(k);
}
void changea(int k, int l, int r, int a, int b) {
	if (l == a && r == b) {
		tr[k].shift();
		lz[k]++;
		return;
	}
	pushdown(k);
	int mid = (l + r) / 2;
	if (b <= mid) changea(LC, l, mid, a, b);
	else if (a > mid) changea(RC, mid + 1, r, a, b);
	else changea(LC, l, mid, a, mid), changea(RC, mid + 1, r, mid + 1, b);
	update(k);
}
node aska(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return tr[k];
	pushdown(k);
	int mid = (l + r) / 2;
	node res;
	if (b <= mid) res = aska(LC, l, mid, a, b);
	else if (a > mid) res = aska(RC, mid + 1, r, a, b);
	else res = aska(LC, l, mid, a, mid) + aska(RC, mid + 1, r, mid + 1, b);
	update(k);
	return res;
}
LL f[N], inv[N], ff[N];
LL C(int n, int m) {
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}
int main() {
	// freopen("input.txt", "r", stdin);
	IO;
	f[0] = 1;
	rep(i, 1, N)
		f[i] = (f[i - 1] * i) % mod;
	ff[1] = ff[0] = inv[1] = inv[0] = 1;  
	rep(i, 2, N) {
    	inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    	ff[i] = inv[i];
	}
	rep(i, 2, N)
		inv[i] = (inv[i - 1] * inv[i]) % mod;
	cin >> n >> q;
	cin >> s;
	repn(i, 1, n) {
		int c = s[i - 1] - 'A';
		rep(j, 0, c) changec(1, 1, n, i, i);
	}
	rep(i, 1, n) {
		renew(1, 1, n, i);
	}
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			changec(1, 1, n, l, r);
			if (l < r) changea(1, 1, n, l, r - 1);
			if (l != 1) renew(1, 1, n, l - 1);
			if (r != n) renew(1, 1, n, r);
			// repn(i, 1, n) renew(1, 1, n, i);
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;
			int num = 0;
			if (k > r - l + 1) {
				cout << "0\n";
				continue;
			}
			if (l == r) {
				if (k == 1) cout << "1\n";
				else cout << "0\n";
				continue;
			}
			node res = aska(1, 1, n, l, r - 1);
			rep(i, 0, 4) repn(j, 0, i) num += res.adj[i][j];
			if (num > k - 1) {
				cout << "0\n";
				continue;
			}
			int len = r - l;
			cout <<  C(len - num, k - 1 - num) << "\n";
		}
	}
	return 0;
}