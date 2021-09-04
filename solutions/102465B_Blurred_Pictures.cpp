// Problem: Blurred Pictures
// URL: https://codeforces.com/gym/102465/problem/B
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

int n, a[N], b[N], l[N], r[N];
int mx[M], lz[M];
int update(int k) {
	mx[k] = max(mx[LC], mx[RC]);
}
void pushdown(int k) {
	if (lz[k]) {
		mx[LC] += lz[k], mx[RC] += lz[k];
		lz[LC] += lz[k], lz[RC] += lz[k];
		lz[k] = 0;
	}
}
void build(int k, int l, int r) {
	lz[k] = mx[k] = 0;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
}
void change(int k, int l, int r, int a, int b, int c) {
	if (l == a && r == b) {
		mx[k] += c;
		lz[k] += c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(k);
	if (b <= mid) change(LC, l, mid, a, b, c);
	else if (a > mid) change(RC, mid + 1, r, a, b, c);
	else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
	update(k);
}
int check(int x) {
	build(1, 0, n);
	repn(i, 1, n) {
		if (i - x >= 1 && l[i - x] <= r[i - x]) {
			change(1, 0, n, l[i - x], r[i - x], -1);
		}
		if (b[i] - a[i] + 1 >= x) {
			l[i] = a[i];
			r[i] = b[i] - x + 1;
			change(1, 0, n, l[i], r[i], 1);
		}
		else l[i] = 1, r[i] = 0;
		if (mx[1] == x) return 1;
	}
	return 0;
}
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i] >> b[i];
	// repn(i, 1, n) a[i] = 0, b[i] = n;
	int l = 1, r = n, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}