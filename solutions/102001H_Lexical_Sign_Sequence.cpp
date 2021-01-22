// Problem: Lexical Sign Sequence
// URL: https://codeforces.com/gym/102001/problem/H
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, k;
int ans[N], a[N], b[N], c[N], num[N];
int sum[2][N], mn[M], lz[M];
void update(int k) {
	mn[k] = min(mn[LC], mn[RC]);
}
void pushdown(int k) {
	if (lz[k]) {
		mn[LC] -= lz[k], mn[RC] -= lz[k];
		lz[LC] += lz[k], lz[RC] += lz[k];
		lz[k] = 0;
	}
}
void build(int k, int l, int r) {
	if (l == r) {
		mn[k] = inf;
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void changep(int k, int l, int r, int a, int x) {
	if (l == r) {
		mn[k] = x;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(k);
	if (a <= mid) changep(LC, l, mid, a, x);
	else changep(RC, mid + 1, r, a, x);
	update(k);
}
vector<int> st[N], ed[N];
int main()
{
	IO;
	cin >> n >> k;
	repn(i, 1, n) {
		cin >> ans[i];
		if (ans[i] == 0) sum[0][i] = sum[0][i - 1] + 1;
		else sum[0][i] = sum[0][i - 1];
		if (ans[i] == 1) sum[1][i] = sum[1][i - 1] + 1;
		else sum[1][i] = sum[1][i - 1];
	}
	int flag = 0;
	repn(i, 1, k) {
		cin >> a[i] >> b[i] >> c[i];
		st[a[i]].pb(i), ed[b[i]].pb(i);
		int len = b[i] - a[i] + 1;
		int l = 0, r = len, pos = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (mid - (len - mid) >= c[i]) r = mid - 1, pos = mid;
			else l = mid + 1;
		}
		if (pos == -1) {
			flag = 1;
			break;
		}
		int left = sum[0][b[i]] - sum[0][a[i] - 1];
		int cur = sum[1][b[i]] - sum[1][a[i] - 1];
		num[i] = left - (pos - cur);
		if (num[i] < 0) flag = 1;
	}
	if (flag) {
		cout << "Impossible\n";
		return 0;
	}
	if (k) build(1, 1, k);
	else mn[1] = inf;
	repn(i, 1, n) {
		for (auto x: st[i]) {
			changep(1, 1, k, x, num[x]);
		}
		if (ans[i] == 0) {
			if (mn[1] == 0) ans[i] = 1;
			else {
				ans[i] = -1;
				lz[1] += 1, mn[1] -= 1;
			}
		}
		for (auto x: ed[i]) {
			changep(1, 1, k, x, inf);
		}
	}
	repn(i, 1, n) {
		cout << ans[i];
		if (i != n) cout << " ";
		else cout << "\n";
	}
	return 0;
}