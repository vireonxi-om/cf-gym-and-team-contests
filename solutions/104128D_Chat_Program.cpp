// Problem: Chat Program
// URL: https://codeforces.com/gym/104128/problem/D
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, k, m;
LL c, d, a[N];
int f[N];
int check(LL x) {
	repn(i, 1, n) f[i] = 0;
	repn(i, 1, n) {
		LL mx;
		if (i <= m) mx = i - 1;
		else mx = m - 1;
		if (a[i] >= x) f[1]++;
		else if (a[i] + c + mx * d >= x) {
			f[max(1, i - m + 1)]++;
			if (a[i] + c >= x) f[i + 1]--;
			else {
				LL res = x - c - a[i];
				res = (res + d - 1) / d;
				f[i - res + 1]--;
			}
		}
	}
	int num = 0;
	repn(i, 1, n - m + 1) {
		num += f[i];
		if (num >= k) return 1;
	}
	return 0;
}
int main() {
	IO;
	cin >> n >> k >> m >> c >> d;
	repn(i, 1, n) cin >> a[i];
	LL l = 0, r = 1e17, ans;
	while (l <= r) {
		LL mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}