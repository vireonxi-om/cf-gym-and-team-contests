// Problem: Gambler's Ruin
// URL: https://codeforces.com/gym/104065/problem/D
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18 + 10;
const double eps = 1e-9;

int n;
LL sum[N];
vector<pair<double, LL>> a, b;
LL bx, by;
double res;
int na;

int dcmp(double x) {
	if (x < -eps) return -1;
	else if (x > eps) return 1;
	else return 0;
}

double cal(int xi, int yi) {
	double x, y;
	LL sx, sy;
	if (xi < 0) {
		x = 1; sx = bx;
	}
	else {
		x = 1 / (-a[xi].fi);
		sx = bx + sum[xi];
	}
	if (yi > na - 1) {
		y = 1; sy = by;
	}
	else {
		y = 1 / (1 + a[yi].fi);
		sy = by + sum[na - 1];
		if (yi) sy -= sum[yi - 1];
	}
	double cur = sx + sy - max(sx * x, sy * y);
	//res = max(res, cur);
	return cur;
}

int main() {
	IO;
	cin >> n;
	double p; LL c; 
	repn(i, 1, n) {
		cin >> p >> c;
		if (p == 0) { by += c; continue;}
		if (p == 1) { bx += c; continue;}
		a.pb(mp(-p, c));
	} 
	sort(all(a));
	na = a.size();
	rep(i, 0, na) {
		LL cur = a[i].se;
		while (i + 1 < na && dcmp(a[i + 1].fi - a[i].fi) == 0) {
			i ++; cur += a[i].se;
		}
		b.pb(mp(a[i].fi, cur));
	}
	a.clear();
	for (auto pr : b) a.pb(pr);
	na = a.size(); 
	if (na) sum[0] = a[0].se;
	rep(i, 1, na) sum[i] = sum[i - 1] + a[i].se;
	
	res = bx + by - max(bx, by);
	
	int l = 0, r = na - 1, ans = na;
	while (l <= r) {
		int mid = (l + r) / 2;
		double y = 1 / (1 + a[mid].fi);
		LL sy = sum[na - 1] + by;
		if (mid) sy -= sum[mid - 1];
		if (dcmp(sy * y - bx) <= 0) {
			ans = mid; r = mid - 1;
		}
		else l = mid + 1;
	} 
	res = max(res, cal(-1, ans));
	if (ans) {
		res = max(res, cal(-1, ans - 1));
	}
	rep(i, 0, na) {
		//while (i + 1 < na && dcmp(a[i + 1].fi - a[i].fi) == 0) i ++;
		LL sx = sum[i] + bx;
		double x = 1 / (-a[i].fi);
		int l = i + 1, r = na - 1, ans = na;
		while (l <= r) {
			int mid = (l + r) / 2;
			double y = 1 / (1 + a[mid].fi);
			LL sy = sum[na - 1] - sum[mid - 1] + by;
			if (dcmp(sy * y - sx * x) <= 0) {
				ans = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		res = max(res, cal(i, ans));
		if (ans - 1 > i) res = max(res, cal(i, ans - 1));
	}
	cout << fixed << setprecision(10) << res << "\n";
	return 0;
}
