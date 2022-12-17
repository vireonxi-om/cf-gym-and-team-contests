// Problem: Optimization for UltraNet
// URL: https://codeforces.com/gym/102835/problem/H
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

int n, m, f[N], sz[N], pp[M];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct edge {
	int x, y, w;
	friend bool operator < (edge a, edge b) {
		return a.w < b.w;
	}
}a[M];
LL ans;
int check(int mid) {
	repn(i, 1, n) f[i] = i, sz[i] = 1;
	int num = n;
	repn(i, 1, m) pp[i] = 0;
	repn(i, mid, m) {
		int x = a[i].x, y = a[i].y;
		int fx = find(x), fy = find(y);
		if (fx != fy) f[fx] = fy, num--, pp[i] = 1;
	}
	return num == 1;
}
			
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	sort(a + 1, a + m + 1);
	int l = 1, r = m, pos;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, pos = mid;
		else r = mid - 1;
	}
	check(pos);
	repn(i, 1, n) f[i] = i, sz[i] = 1;
	pern(i, 1, m) {
		if (pp[i]) {
			int x = a[i].x, y = a[i].y;
			LL w = a[i].w;
			int fx = find(x), fy = find(y);
			ans += w * (LL)sz[fx] * (LL)sz[fy];
			sz[fy] += sz[fx];
			f[fx] = fy;
		}
	}
	cout << ans << endl;
	return 0;
}