// Problem: Stock Analysis
// URL: https://codeforces.com/gym/102920/problem/I
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

const int N = 210000;
const int M = 4100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF=1e18;
const double eps = 1e-9;

int n, m, cnt;
struct node {
	int l, r, op, id;
	LL w;
	friend bool operator < (node a, node b) {
		if (a.w != b.w) return a.w < b.w;
		return a.op < b.op;
	}
}b[M];
LL ans[N], sum[N], a[N];
int lowbit(int x) {
	return x & -x;
}
LL f[2100][2100];
void add(int x, int y, LL z) {
	for (int i = x; i < 2100; i += lowbit(i))
		for (int j = y; j < 2100; j += lowbit(j)) 
			f[i][j] = max(f[i][j], z);
}
LL get(int x, int y) {
	LL res = -INF;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			res = max(res, f[i][j]);
	return res;
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	repn(i, 1, n) repn(j, 1, n) f[i][j] = -INF;
	repn(i, 1, n) {
		repn(j, i, n) {
			cnt++;
			b[cnt].l = n + 1 - i;
			b[cnt].r = j;
			b[cnt].w = sum[j] - sum[i - 1];
		}
	}
	repn(i, 1, m) {
		int l, r;
		LL w;
		cin >> l >> r >> w;
		cnt++;
		b[cnt].l = n + 1 - l;
		b[cnt].r = r;
		b[cnt].op = 1;
		b[cnt].id = i;
		b[cnt].w = w;
	}
	sort(b + 1, b + cnt + 1);
	repn(i, 1, cnt) {
		int op = b[i].op;
		if (op == 0) add(b[i].l, b[i].r, b[i].w);
		else ans[b[i].id] = get(b[i].l, b[i].r);
	}
	repn(i, 1, m) {
		if (ans[i] == -INF) cout << "NONE\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}