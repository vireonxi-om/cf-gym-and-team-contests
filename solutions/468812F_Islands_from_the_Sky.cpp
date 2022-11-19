// Problem: Islands from the Sky
// URL: https://codeforces.com/gym/468812/problem/F
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

const int N = 110;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

const double pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    double x, y;
    Point (double x = 0 , double y = 0) : x(x) , y(y) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    bool operator < (const Point& R) const {
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
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
    Point operator * (const double& R) const {
        return Point(x * R, y * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R, y / R);
    }
    double operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    double operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
    double angle() {
        return atan2(y, x);
    }
}p[N][N], st[N], ed[N], vec[N], tmp[N];
int len[N];
bool OnSegment(Point P, Point a1, Point a2) {
    double len = (P - a1).len();
    if (dcmp(len) == 0) return true;
    a1 = a1 - P , a2 = a2 - P;
    return dcmp((a1 ^ a2) / len) == 0 && dcmp(a1 % a2) <= 0;
}
Point Rotate(Point A, double rad) {
    double Sin = sin(rad) , Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin , A.x * Sin + A.y * Cos);
}
bool pointInPolygon(Point P , Point *p , int n) {
    for (int i = 0 ; i < n ; ++ i)
        if (OnSegment(P , p[i] , p[i + 1]))
            return 1;
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        Point a = p[i] , b = p[i + 1];
        if (a.y > b.y) swap(a , b);
        if (dcmp((a - P) ^ (b - P)) < 0 && dcmp(a.y - P.y) < 0 && dcmp(b.y - P.y) >= 0)
            res ^= 1;
    }
    return res;
}
int n, m;
double stz[N], edz[N];
int check(double x) {
	double coef = tan(x);
	repn(i, 1, n) {
		int flag = 0;
		repn(j, 1, m) {
			int ff = 0;
			tmp[0] = st[j] - vec[j] * stz[j] * coef;
			tmp[1] = st[j] + vec[j] * stz[j] * coef;
			tmp[2] = ed[j] + vec[j] * edz[j] * coef;
			tmp[3] = ed[j] - vec[j] * edz[j] * coef;
			// if (rand() & 1) reverse(tmp, tmp + 4);
			if (((tmp[0] - tmp[1]) ^ (tmp[1] - tmp[2])) < 0) reverse(tmp, tmp + 4);
			tmp[4] = tmp[0];
			rep(k, 0, len[i]) if (!pointInPolygon(p[i][k], tmp, 4)) {
				ff = 1;
				break;
			}
			if (ff == 1) continue;
			flag = 1;
			break;
		}
		if (flag == 0) return 0;
	}
	return 1;
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> len[i];
		rep(j, 0, len[i]) cin >> p[i][j].x >> p[i][j].y;
		// reverse(p[i], p[i] + len[i]);
	}
	repn(i, 1, m) {
		cin >> st[i].x >> st[i].y >> stz[i] >> ed[i].x >> ed[i].y >> edz[i];
		vec[i] = ed[i] - st[i];
		vec[i] = Rotate(vec[i], pi / 2);
		vec[i] = vec[i] / vec[i].len();
	}
	double l = 0, r = pi / 2 - 0.0000001, ans = -1;
	repn(rnd, 1, 100) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid, ans = mid;
		else l = mid;
	}
	if (ans < 0) cout << "impossible\n";
	else cout << fixed << setprecision(15) << (ans / pi * 180);
	return 0;
}