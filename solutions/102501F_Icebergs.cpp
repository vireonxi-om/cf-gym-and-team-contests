// Problem: Icebergs
// URL: https://codeforces.com/gym/102501/problem/F
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
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

struct Point {
	LL x, y;
	Point(LL x = 0, LL y = 0) : x(x), y(y) {}
	void input() {
		cin >> x >> y;
	}
	Point operator - (const Point & R) const {
		return Point(x - R.x , y - R.y);
	}
	LL operator ^ (const Point & R) const {
		return x * R.y - y * R.x;
	}
}p[N];
int T, n;
LL ans;
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n) p[i].input();
		Point tmp = Point(0, 0);
		rep(i, 0, n) p[i] = p[i] - tmp;
		LL res = 0;
		rep(i, 0, n) {
			Point x = p[i];
			Point y = p[(i + 1) % n];
			res += x ^ y;
		}
		ans += abs(res);
	}
	cout << ans / 2 << endl;
	return 0;
}