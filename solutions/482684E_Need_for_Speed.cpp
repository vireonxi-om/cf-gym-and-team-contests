// Problem: Need for Speed
// URL: https://codeforces.com/gym/482684/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

int n;
double t, d[N], s[N];
double cal(double c) {
	double sum = 0;
	repn(i, 1, n) sum += d[i] / (s[i] + c);
	return sum;
}
int main() {
	IO;
	cin >> n >> t;
	repn(i, 1, n) cin >> d[i] >> s[i];
	double l = -1e15, r = 1e15, ans;
	repn(i, 1, n) l = max(l, -s[i]);
	repn(rnd, 1, 1000) {
		double mid = (l + r) / 2;
		if (cal(mid) <= t) r = mid, ans = mid;
		else l = mid;
	}
	cout << fixed << setprecision(15) << ans << "\n";
	return 0;
}