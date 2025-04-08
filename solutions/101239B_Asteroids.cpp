// Problem: Asteroids
// URL: https://codeforces.com/gym/101239/problem/B
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
typedef long double LD;
 
const int N = 51000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const long long INF = (long long)1e18;
const double eps = 1e-10 , pi = acos(-1.0);

namespace PointDouble{
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
};
struct Line {
	Point P, V; //P + Vt
    double angle;
    Line () {}
    Line (Point A , Point B) {
        P = A , V = B - A;
        angle = atan2(V.y , V.x);
    }
    bool operator < (const Line& R) const {
        return angle < R.angle;
    }
    Point point(double t) {
        return P + V * t;
    }
};

int Convex2D(Point p[], int stk[], int used[], Point h[], int n) {
	// n, Points p[N] (will be sorted), int stk[N] & used[N]
	// Point h[1, ..., ans + 1] = convex hull with start point repeated at the end.
	int tp = 0;
	sort(p + 1, p + 1 + n); 
	stk[++tp] = 1;
	for (int i = 2; i <= n; ++i) {
		while (tp >= 2 && dcmp((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
			used[stk[tp--]] = 0;
		used[i] = 1;  
		stk[++tp] = i;
	}
	int tmp = tp;  
	for (int i = n - 1; i > 0; --i){
	    if (used[i]) continue;
	    while (tp > tmp && dcmp((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
	    	used[stk[tp--]] = 0;
	    used[i] = 1;
	    stk[++tp] = i;
	}
	for (int i = 1; i <= tp; ++i) h[i] = p[stk[i]];
	return tp - 1;
}

Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
//exclude intersection of endpoint-endpoint or endpoint-line
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2);
    }
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//include all intersections 
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2) || max(a1, b1) == min(a2, b2);
    }
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}

inline bool Onleft(Line L , Point P) {
    return dcmp((L.V ^ (P - L.P))) > 0;
}

//typedef vector<Point> Polygon;
double ConvexPolygonArea(Point *p, int n) {
	double area = 0; 
	rep(i, 1, n - 1) {
		area += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
	}
	return fabs(area / 2);
}
//find halfplane intersection. Note: consider the left plane of each line. 
int HalfPlaneIntersection(Line* L , int n , Point* Poly) {
	Point p[100];
    Line q[100];
    sort(L , L + n);
    int top = 0 , bot = 0;
    q[0] = L[0];
    for (int i = 1 ; i < n ; ++ i) {
        while (top < bot && !Onleft(L[i] , p[bot - 1])) -- bot;
        while (top < bot && !Onleft(L[i] , p[top])) ++ top;
        q[++ bot] = L[i];
        if (dcmp(L[i].V ^ q[bot - 1].V) == 0) {
            -- bot;
            if (Onleft(q[bot] , L[i].P))
                q[bot] = L[i];
        }
        if (top < bot)
            p[bot - 1] = GetLineIntersection(q[bot - 1].P, q[bot - 1].V, q[bot].P, q[bot].V);
        //cout << "tb: " << top << " " << bot << "\n";
        //for (int i = top ; i <= bot ; ++ i) cout << p[i].x << " " << p[i].y << "\n";;
    }
    while (top < bot && !Onleft(q[top] , p[bot - 1])) -- bot;
    if (bot - top <= 1) return 0;
    p[bot] = GetLineIntersection(q[bot].P, q[bot].V, q[top].P, q[top].V);
    int m = 0;
    for (int i = top ; i <= bot ; ++ i) Poly[m ++] = p[i];
    return m;
}

}

namespace PointLL{

struct Point {
    LL x, y;
    Point (LL x = 0 , LL y = 0) : x(x) , y(y) {}
    void input() {
        cin >> x >> y; 
    }
    bool operator < (const Point& R) const {
        if (x - R.x == 0)
            return (y - R.y) < 0;
        return (x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return (x - R.x) == 0 && (y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator * (const LL& R) const {
        return Point(x * R, y * R);
    }
    /*
    Point operator / (const double& R) const {
        return Point(x / R, y / R);
    }
    */
    LL operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    LL operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    LL slen() {
        return *this % *this;
	}
    /*
    double len() {
        return sqrt(*this % *this);
	}
    double angle() {
        return atan2(y, x);
    } */
};
}



using namespace PointDouble;

Point a[15], b[15], c[15];
int na, nb, xa, ya, vx, vy; 
Point v;
vector<double> t;

double IntersectionTime(Point P, Point v, Point Q, Point w) {
	if ((v ^ w) == 0) return 0;
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    if (t1 < 0) return -1;
    else return t1;
}
Point Poly[30];
Line L[30];
double cal(double t1) {
	double res = -1;
	repn(i, 1, nb) c[i] = b[i] + v * t1;
	c[nb + 1] = c[1];
	repn(i, 1, na) {
		repn(j, 1, nb) {
			if (SegmentIntersection(a[i], a[i + 1], c[j], c[j + 1])) res = 0;
		}
	} 
	if (dcmp(res) < 0) return res;
	repn(i, 1, na){
		L[i - 1] = Line(a[i + 1], a[i]);
	}
	repn(i, 1, nb) {
		L[i + na - 1] = Line(c[i + 1], c[i]);
	}
	int n = HalfPlaneIntersection(L, na + nb, Poly);
	res = ConvexPolygonArea(Poly, n);
	return res;
}


int main() {
	cin >> na; 
	repn(i, 1, na) {
		cin >> a[i].x >> a[i].y;
	}
	a[na + 1] = a[1];
	cin >> xa >> ya >> nb;
	repn(i, 1, nb) {
		cin >> b[i].x >> b[i].y;
	}
	cin >> vx >> vy;
	vx -= xa; vy -= ya;
	v.x = vx; v.y = vy;
	repn(i, 1, na) {
		repn(j, 1, nb) {
			double t1 = IntersectionTime(b[j], v, a[i], a[i + 1] - a[i]);
			if (dcmp(t1) > 0) t.pb(t1); 
		}
	}
	sort(all(t));
	if (t.size() <= 1) {
		cout << "never\n"; return 0;
	}
	double ans = -1, tans = t[(int)t.size() - 1]; 
	rep(i, 0, t.size() - 1) {
		double l = t[i], r = t[i + 1];
		double len = (r - l) / 3, m1 = l + len, m2 = r - len;
		repn(k, 1, 300) {
			double len = (r - l) / 3, m1 = l + len, m2 = r - len;
			double f1 = cal(m1), f2 = cal(m2);
			if (dcmp(f1 - f2) >= 0) {
				r = m2; 
				if (dcmp(f1 - ans) > 0) {
					ans = f1; tans = m1;
				}
				else if (dcmp(f1 - ans) == 0) {
					tans = min(tans, m1);
				}
			} 
			else {
				l = m1;
				if (dcmp(f2 - ans) > 0) {
					ans = f2; tans = m2;
				}
				else if (dcmp(f2 - ans) == 0) {
					tans = min(tans, m2);
				}
			} 
		}
	}
	if (dcmp(ans) < 0) cout << "never\n";
	else cout << fixed << setprecision(7) << tans << "\n";
	return 0;
}
/*
4
0 0 0 1 1 1 1 0 1 0
4
2 0 3 0 3 -1 2 -1 -1 0
*/