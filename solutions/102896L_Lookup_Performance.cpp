// Problem: Lookup Performance
// URL: https://codeforces.com/gym/102896/problem/L
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, q, mn[N], mx[N], ch[N][2], b[N], num;
struct node {
	int l, r, op, id;
	friend bool operator < (node a, node b) {
		if (a.r != b.r) return a.r < b.r;
		return a.op < b.op;
	}
}a[M];
int m;
void dfs(int x) {
	mn[x] = mx[x] = b[x];
	if (ch[x][0]) {
		dfs(ch[x][0]);
		mn[x] = min(mn[x], mn[ch[x][0]]);
		mx[x] = max(mx[x], mx[ch[x][0]]);
	}
	else m++;
	if (ch[x][1]) {
		dfs(ch[x][1]);
		mn[x] = min(mn[x], mn[ch[x][1]]);
		mx[x] = max(mx[x], mx[ch[x][1]]);
	}
	else m++;
	a[++num] = {inf - mn[x] + 1, mx[x], 0, 0};
	a[++num] = {inf - mn[x] + 1, mx[x], 0, 0};
}
int ans[N], c[M], nn;
map<int, int> S;
int v[M];
int lowbit(int x) {
	return x & -x;
}
int get(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += v[i];
	return res;
}
void add(int x) {
	for (int i = x; i < M; i += lowbit(i)) v[i]++;
}
int main()
{
	IO;
	cin >> n;
	m = n;
	repn(i, 1, n) {
		cin >> ch[i][0] >> ch[i][1] >> b[i];
	}
	dfs(1);
	cin >> q;
	repn(i, 1, q) {
		int l, r;
		cin >> l >> r;
		// [l, r]
		a[++num] = {inf - l + 1, r, 1, i};
		// [-inf, l - 1];
		if (l - 1 >= -inf) a[++num] = {inf - (-inf) + 1, l - 1, 1, i};
		// [r + 1, inf];
		if (r + 1 <= inf) a[++num] = {inf - (r + 1) + 1, inf, 1, i};
	}
	repn(i, 1, num) c[i] = a[i].l;
	sort(c + 1, c + 1 + num);
	S[c[1]] = nn = 1;
	repn(i, 2, num) if (c[i] != c[i - 1]) S[c[i]] = ++nn;
	sort(a + 1, a + num + 1);
	repn(i, 1, num) {
		int op = a[i].op, l = S[a[i].l], id = a[i].id;
		if (op == 0) add(l);
		else ans[id] += get(l);
	}
	repn(i, 1, q) cout << m - ans[i] << "\n";
	return 0;
}