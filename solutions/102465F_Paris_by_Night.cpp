// Problem: Paris by Night
// URL: https://codeforces.com/gym/102465/problem/F
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

const int N = 4100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

LL ans;
double pi = acos(-1.0);
struct point {
	int x, y, w;
	double ang1, ang2;
	double angle() {
		return atan2((double)y, (double)x);
	}
	double angle2() {
		double v = ang1;
		if (v < eps) return abs(v);
		return pi - v;
	}
	friend bool operator < (point &a, point &b) {
		return a.ang2 < b.ang2;
	}
}p[N], q[N];
int n, m;
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> p[i].x >> p[i].y >> p[i].w;
		ans += p[i].w;
	}
	repn(i, 1, n) {
		m = 0;
		repn(j, 1, n) {
			if (i != j) {
				q[++m] = {p[j].x - p[i].x, p[j].y - p[i].y, p[j].w};
				q[m].ang1 = q[m].angle();
				q[m].ang2 = q[m].angle2();
			}
		}
		sort(q + 1, q + m + 1);
		int cur = -1;
		LL sum1 = 0, sum2 = 0;
		repn(j, 1, m) {
			if (q[j].y == 0) cur = j;
			else if (q[j].y > 0) sum1 += q[j].w;
			else sum2 += q[j].w;
		}
		if (cur != -1) ans = min(ans, abs(sum1 - sum2));
		repn(j, 1, m) {
			if (j == cur);
			else {
				if (cur != -1) {
					if (q[cur].ang1 > eps) sum2 += q[cur].w;
					else sum1 += q[cur].w;
				}
				cur = j;
				if (q[j].ang1 > eps) sum1 -= q[j].w;
				else sum2 -= q[j].w;
			}
			ans = min(ans, abs(sum1 - sum2));
		}
	}
	cout << ans << endl;
	return 0;
}