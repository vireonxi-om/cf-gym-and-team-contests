// Problem: Lowbit
// URL: https://codeforces.com/gym/103145/problem/D
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

const int N = 110000;
const int M = 410000;
const LL mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, n, q, a[N];
LL sum[M], lz[M];
int num[M];
void update(int k) {
	num[k] = num[LC] + num[RC];
	sum[k] = (sum[LC] + sum[RC]) % mod;
}
void pushdown(int k) {
	if (lz[k] > 1) {
		sum[LC] = sum[LC] * lz[k] % mod;
		sum[RC] = sum[RC] * lz[k] % mod;
		lz[LC] = lz[LC] * lz[k] % mod;
		lz[RC] = lz[RC] * lz[k] % mod;
		lz[k] = 1;
	}
}
void build(int k, int l, int r) {
	lz[k] = 1;
	if (l == r) {
		sum[k] = a[l];
		num[k] = __builtin_popcount(a[l]) - 1;
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
LL ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return sum[k];
	int mid = (l + r) / 2;
	pushdown(k);
	LL res = 0;
	if (b <= mid) res = ask(LC, l, mid, a, b);
	else if (a > mid) res = ask(RC, mid + 1, r, a, b);
	else res = (ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b)) % mod;
	update(k);
	return res;
}
LL lowbit(LL x) {
	return x & -x;
}

void add(int k, int l, int r, int a, int b) {
	if ((l == r) || (l == a && r == b && num[k] == 0)) {
		if (num[k] == 0) sum[k] = sum[k] * 2LL % mod, lz[k] = lz[k] * 2LL % mod;
		else sum[k] = sum[k] + lowbit(sum[k]), lz[k] = lz[k] * 2LL % mod;
		if (l == r && num[k] > 0) num[k] = __builtin_popcount(sum[k]) - 1;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(k);
	if (b <= mid) add(LC, l, mid, a, b);
	else if (a > mid) add(RC, mid + 1, r, a, b);
	else add(LC, l, mid, a, mid), add(RC, mid + 1, r, mid + 1, b);
	update(k);
}
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		repn(i, 1, n) cin >> a[i];
		build(1, 1, n);
		cin >> q;
		while (q--) {
			int op, l, r;
			cin >> op >> l >> r;
			if (op == 1) {
				add(1, 1, n, l, r);
			}
			else {
				cout << ask(1, 1, n, l, r) << "\n";
			}
		}
	}
	return 0;
}