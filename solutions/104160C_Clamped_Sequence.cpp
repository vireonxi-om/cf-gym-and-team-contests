// Problem: Clamped Sequence
// URL: https://codeforces.com/gym/104160/problem/C
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

const int N = 5100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, d;
LL a[N], ans;
LL cal(LL l, LL r, LL x) {
	if (x < l) return l;
	if (x > r) return r;
	return x;
}
void work(LL l, LL r) {
	LL res = 0;
	repn(i, 2, n) res += abs(cal(l, r, a[i]) - cal(l, r, a[i - 1]));
	ans = max(ans, res);
}
int main() {
	IO;
	cin >> n >> d;
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) {
		work(a[i], a[i] + d);
		work(a[i] - d, a[i]);
	}
	cout << ans << "\n";
	return 0;
}