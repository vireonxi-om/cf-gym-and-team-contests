// Problem: Airport Construction
// URL: https://codeforces.com/gym/482684/problem/A
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
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;


const int N = 210;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const LD eps = 1e-13, pi = acos(-1.0);

mt19937_64 Rand((unsigned long long) new char);
#define rand Rand

inline int dcmp(LD x) {
	return (x > eps) - (x < -eps);
}
struct Point {
	LD x, y;
	Point (LD x = 0, LD y = 0) : x(x), y(y) {}
	bool operator < (const Point& R) const {
		if (dcmp(x - R.x) == 0) return dcmp(y - R.y) < 0;
		return dcmp(x - R.x) < 0;
	}
	bool operator == (const Point& R) const {
		return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
	}
	Point operator + (const Point& R) const {
		return Point(x + R.x, y + R.y);
	}
	Point operator - (const Point& R) const {
		return Point(x - R.x, y - R.y);
	}
	Point operator * (const LD& R) const {
		return Point(x * R, y * R);
	}
	Point operator / (const LD& R) const {
		return Point(x / R, y / R);
	}
	LD operator ^ (const Point& R) const {
		return x * R.y - y * R.x;
	}
	LD operator % (const Point& R) const {
		return x * R.x + y * R.y;
	}
	LD len() {
		return sqrtl(*this % *this); 
	}
	LD angle() {
		return atan2(y, x);
	}
};

bool OnSegment(Point P, Point a1, Point a2) {
	LD len = (P - a1).len();
	if (dcmp(len) == 0) return true;
	a1 = a1 -  P; a2 = a2 - P;
	return dcmp((a1 ^ a2) / len) == 0 && dcmp(a1 % a2) <= 0; 
}

bool pointInPolygon(Point P, Point *p, int n) {
	repn(i, 1, n) {
		if (OnSegment(P, p[i], p[i + 1])) return -1;
	}
	int res = 0;
	repn(i, 1, n) {
		Point a = p[i], b = p[i + 1];
		if (a.y > b.y) swap(a, b);
		if (dcmp((a - P) ^ (b - P)) < 0 && dcmp(a.y - P.y) < 0 && dcmp(b.y - P.y) >= 0) res ^= 1;
	}
	return res;
}
LD GetLineIntersection(Point P, Point v, Point Q, Point w) {
	Point u = P - Q;
	if (dcmp((v ^ w)) == 0) return -1;
	LD t1 = (w ^ u) / (v ^ w);
	return t1;
}
int PointOnLine(Point P, Point A, Point B) {
	if (dcmp((B - A) ^ (P - A)) == 0) return 1;
	return 0;
}

int n;
Point poly[N];
vector<LD> its;

int main() {
	IO;
	cin >> n;
	int x, y;
	repn(i, 1, n) {
		cin >> x >> y;
		poly[i].x = x; poly[i].y = y;
	}
	poly[n + 1] = poly[1];
	LD ans = 0;
	repn(i, 1, n) {
		repn(j, i + 1, n) {
			LD lenij = (poly[j] - poly[i]).len();
			Point ij = (poly[j] - poly[i]);
			its.clear(); 
			repn(k, 1, n) {
				int nxt = k + 1; 
				if (nxt > n) nxt = 1;
				if (PointOnLine(poly[k], poly[i], poly[j])) {
					LD cur = ((poly[k] - poly[i]) % ij) / lenij / lenij;
					its.pb(cur);
					continue;
				}
				LD itl = GetLineIntersection(poly[k], poly[nxt] - poly[k], poly[i], ij);
				if (dcmp(itl) < 0) continue;
				if (dcmp(itl - 1) >= 0) continue;
				LD cur = GetLineIntersection(poly[i], ij, poly[k], poly[nxt] - poly[k]);
				its.pb(cur);
			}
			sort(all(its));
			if (lenij * (its[SZ(its) - 1] - its[0]) < ans) continue;
			//cout << i << " " << j << "\n";
			//for (auto it : its) cout << it << " ";
			//cout << "\n";
			bool can = true;
			// Point dir = ij / lenij * eps * 100000;
			int l = 0, r = its.size() - 1;
			while (dcmp(its[l]) < 0) l ++;
			while (dcmp(its[r] - 1) > 0) r --;
			rep(k, l + 1, r) {
				Point now = poly[i] + ij * its[k];
				Point nowl = poly[i] + ij * (its[k - 1] + its[k]) / 2;
				Point nowr = poly[i] + ij * (its[k + 1] + its[k]) / 2;
				bool y1 = pointInPolygon(nowr, poly, n), y2 = pointInPolygon(nowl, poly, n);
				if (!y1 || !y2) {
					can = false;
					break;
				}
			}
			Point now = poly[i] + ij * (its[l] + its[r]) / 2;
			if (!pointInPolygon(now, poly, n)) continue;
			if (!can) continue;
			int ansl = -1, ansr = -1;
			while (l >= 0) {
				//if (i == 1 && j == 4) cout << pointInPolygon(now + dir, poly, n) << "\n";
				//if (i == 1 && j == 4) cout << fixed << setprecision(11) << (now + dir).x << " " << (now + dir).y << "\n"; 
				// if (!pointInPolygon(now + dir, poly, n)) break;
				ansl = l;
				if (l == 0) break;
				Point now = poly[i] + ij * (its[l] + its[l - 1]) / 2;
				//if (i == 1 && j == 4) cout << pointInPolygon(now - dir, poly, n) << "\n";
				if (!pointInPolygon(now, poly, n)) break;
				l --;
			}
			//if (i == 1 && j == 4) cout << "\n";
			while (r < its.size()) {
				//if (i == 1 && j == 4) cout << pointInPolygon(now - dir, poly, n) << "\n";
				// if (!pointInPolygon(now - dir, poly, n)) break;
				ansr = r;
				if (r == SZ(its) - 1) break;
				Point now = poly[i] + ij * (its[r] + its[r + 1]) / 2;
				//if (i == 1 && j == 4) cout << pointInPolygon(now + dir, poly, n) << "\n";
				if (!pointInPolygon(now, poly, n)) break;
				r ++;
			}
			if (ansl < 0 || ansr < 0) continue;
			ans = max(ans, lenij * (its[ansr] - its[ansl]));
		}
	}
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}
/*
6
0 20
40 0
40 20
50 70
30 50
0 50
*/



