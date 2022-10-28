// Problem: Forever Young
// URL: https://codeforces.com/gym/452521/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

LL y, l, ans = 10;
typedef __int128 int128;
int a[N];
int check(LL b) {
	int flag = 0, cnt = 0;
	LL x = y;
	while (x) {
		cnt++;
		a[cnt] = x % b;
		if (a[cnt] >= 10) return 0;
		x /= b;
	}
	LL res = 0;
	pern(i, 1, cnt) res = res * 10 + a[i];
	return res >= l;
}
LL cal2(LL a, LL b, LL c, int128 x) {
	if (x * x > y) return y + 1;
	int128 res = a * x * x + b * x + c;
	res = min(res, (int128)y + 1);
	return res;
}
int main() {
	IO;
	// cout << 1000001LL * 1000001 * 8 + 1000001 * 7 + 5 << endl;
	cin >> y >> l;
	// >= 4 digits
	repn(b, 10, 1000000) if (check(b)) ans = max(ans, (LL)b);
	// = 3 digits
	repn(i, 1, 9) repn(j, 0, 9) repn(k, 0, 9) {
		if (i * 100 + j * 10 + k < l) continue;
		LL a = i, b = j, c = k, x = 0;
		LL al = 10, ar = y;
		while (al <= ar) {
			LL mid = (al + ar) / 2;
			if (cal2(a, b, c, mid) >= y) ar = mid - 1, x = mid;
			else al = mid + 1;
		}
		if (cal2(a, b, c, x) == y) ans = max(ans, x);
	}
	
	// = 2 digits;
	repn(i, 1, 9) repn(j, 0, 9) {
		if (i * 10 + j < l) continue;
		if ((y - j) % i == 0) {
			LL x = (y - j) / i;
			ans = max(ans, x);
		}
	}
	cout << ans << "\n";
	return 0;
}