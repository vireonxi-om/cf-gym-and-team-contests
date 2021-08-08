// Problem: Cutting Cheese
// URL: https://codeforces.com/gym/447801/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC ch[k][0] 
#define RC ch[k][1]
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

const int N = 600010;
const int M = 610000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, s;
vector<PDD> sp;
double ans[110], v;

int dcmp(double x) {
	if (x < -eps) return -1;
	else if (x > eps) return 1;
	return 0;
}

double vol(double r, double h) {
	return pi * (3 * r - h) * h * h / 3;
}

double work(double l1, double l2, int i) {
	double r = sp[i].se, x = sp[i].fi;
	double d1 = x - l1, d2 = l2 - x;
	int t1 = dcmp(fabs(d1) - r), t2 = dcmp(fabs(d2) - r);
	int t = 0;
	if (dcmp(d1) < 0) {
		d1 = - d1; t = 1 - t;
	}
	if (dcmp(d2) < 0) {
		d2 = - d2; t = 1 - t;
	}
	if (t1 >= 0 && t2 >= 0) {
		if (t) return 0;
		else return 4 * pi * r * r * r / 3;
	}
	if (t1 < 0 && t2 < 0) {
		double v1 = vol(r, r - d1), v2 = vol(r, r - d2);
		if (t) {
			return max(v1, v2) - min(v1, v2);
		}
		else {
			return 4 * pi * r * r * r / 3 - v1 - v2;
		}
	}
	double d = min(d1, d2);
	double v = vol(r, r - d);
	if (t) return v;
	else return 4 * pi * r * r * r / 3 - v;
}

int main()
{
	IO;
	cin >> n >> s;
	double rx, zx;
	repn(i, 1, n) {
		cin >> rx; cin >> zx; cin >> zx; cin >> zx;
		sp.pb(mp(zx, rx)); 
	}
	double a = 1e5;
	v = a * a * a;
	rep(i, 0, n) v -= 4 * pi * sp[i].se * sp[i].se * sp[i].se / 3;
	v /= s;
	
	repn(i, 1, s) {
		double l = ans[i - 1], r = a;
		repn(t, 1, 200) {
			double mid = (l + r) / 2;
			double vcur = (mid - ans[i - 1]) * 1e5 * 1e5;
			rep(j, 0, n) {
				vcur -= work(ans[i - 1], mid, j);
			}
			if (vcur >= v) r = mid;
			else l = mid;
		}
		ans[i] = l;
	}
	repn(i, 1, s) {
		cout << fixed << setprecision(9) << (ans[i] - ans[i - 1]) / 1000 << "\n";
	}
	return 0;
}