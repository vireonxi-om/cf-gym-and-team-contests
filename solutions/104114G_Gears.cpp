// Problem: Gears
// URL: https://codeforces.com/gym/104114/problem/G
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

const int N = 510000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;
int la = 0, lb = 0;
LL x[N], d[N], a[N], b[N], r[N];
vector<LL> cur;
bool yes = false;
LL R1 = -1;
vector<pair<LL, int>> res, rad;
int ans[N];

void try_num(LL r1) {
	cur.clear();
	repn(i, 1, la) cur.pb(a[i] - r1);
	repn(i, 1, lb) cur.pb(b[i] + r1);
	sort(all(cur));
	//cout << r1 << "\n";
	//repn(i, 1, n) cout << cur[i - 1] << " " << r[i] << "\n";
	repn(i, 1, n) {
		if (cur[i - 1] != r[i]) return;
	}
	R1 = r1;
	return;
}

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> x[i];
	repn(i, 2, n) d[i] = x[i] - x[i - 1];
	repn(i, 2, n) d[i] -= d[i - 1];
	repn(i, 1, n){
		cin >> r[i];
		rad.pb(mp(r[i], i));
	} 
	for (int i = 1; 2 * i <= n; i ++) {
		a[i] = d[2 * i]; la = i;
	}
	for (int i = 1; 2 * i - 1 <= n; i ++) {
		b[i] = d[2 * i - 1]; lb = i;
	}
	sort(a + 1, a + la + 1); sort(b + 1, b + lb + 1);
	sort(r + 1, r + n + 1);
	if (a[1] > r[1]) try_num(a[1] - r[1]);
	if (b[1] < r[1]) try_num(r[1] - b[1]);
	try_num(r[1]);
	//cout << R1 << "\n";
	repn(i, 1, n) {
		LL num = d[i];
		if (i % 2) num += R1;
		else num -= R1;
		res.pb(mp(num, i));
	}
	sort(all(res));
	sort(all(rad));
	rep(i, 0, n) ans[res[i].se] = rad[i].fi;
	repn(i, 1, n) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}



