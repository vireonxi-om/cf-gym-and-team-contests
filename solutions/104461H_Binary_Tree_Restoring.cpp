// Problem: Binary Tree Restoring
// URL: https://codeforces.com/gym/104461/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 110000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int n, a[N], b[N], cnt[N], ans[N];

void work(int la, int lb, int ra, int rb) {
	if (ra <= la) return;
	if (a[la + 1] == b[lb + 1]) {
		ans[a[la + 1]] = a[la];
		cnt[a[la]] ++; 
		work(la + 1, lb + 1, ra, rb);
	}
	else {
		int pa = la + 1, pb = lb + 1; 
		while (a[pa] != b[lb + 1]) pa ++;
		while (b[pb] != a[la + 1]) pb ++;
		int l1 = pa - la - 1, l2 = pb - lb - 1;
		ans[a[la + 1]] = a[la]; ans[a[pa]] = a[la];
		cnt[a[la]] += 2;
		work(la + 1, pb, pa - 1, lb + l1 + l2);
		work(pa, lb + 1, la + l1 + l2, pb - 1);
		if (pa + l2 <= ra) {
			int pos = a[la]; 
			while (cnt[pos] == 2) pos = ans[pos];
			ans[a[pa + l2]] = pos;
			cnt[pos] ++;
			work(la + l1 + l2 + 1, lb + l1 + l2 + 1, ra, rb);
		} 
		
	}
}

void solve() {
	cin >> n;
	repn(i, 1, n) {
		cnt[i] = 0;
		ans[i] = 0;
	}
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) cin >> b[i];
	work(1, 1, n, n);
	repn(i, 1, n) {
		if (i != n) cout << ans[i] << " ";
		else cout << ans[i] << "\n";
	}
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}
