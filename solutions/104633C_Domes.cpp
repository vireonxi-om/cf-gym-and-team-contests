// Problem: Domes
// URL: https://codeforces.com/gym/104633/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n - 1); i >= a; i--)
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
const int M = 21000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);

#define rand Rand

#define PT LD
const LD EPS = 1e-10, pi = acos(-1.0);
template<class T>
inline int dcmp(T x) {
    return (x > EPS) - (x < -EPS);
}
template<class T>
struct BPoint {
    T x, y;
    BPoint(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator < (const BPoint& R) const {
        if (dcmp(x - R.x) == 0) return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const BPoint& R) const {
        return dcmp(y - R.y) == 0 && dcmp(x - R.x) == 0;
    }
    BPoint operator + (const BPoint& R) const {
        return BPoint(x + R.x, y + R.y);
    }
    BPoint operator - (const BPoint& R) const {
        return BPoint(x - R.x, y - R.y);
    }
    BPoint operator * (const T& R) const {
        return BPoint(x * R, y * R);
    }
    BPoint operator / (const T& R) const {
        return BPoint(x / R, y / R);
    }
    T operator ^ (const BPoint& R) const {
        return x * R.y - y * R.x;
    }
    T angle() {
        return atan2(y, x);
    }
};
#define Point BPoint<PT>
struct Line {
    Point P, V;
    PT angle;
    Line(){}
    Line (Point A, Point B) {
        P = A, V = B - A;
        angle = atan2(V.y, V.x);
    }
    bool operator < (const Line& R) const {
        if (dcmp(angle - R.angle) != 0) {
                return dcmp(angle - R.angle) < 0;
        }
        return dcmp((R.V ^ (P - R.P))) > 0;
    }
    Point point(PT t) {
        return P + V * t;
    }
};
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    PT t1 = (w^u) / (v ^ w);
    return P + v * t1;
}
inline PT OnLeft(Point P, Point A, Point B) {
    return (B - A) ^ (P - A);
}
typedef std::vector<Point> Polygon;
Polygon Convex2D(vector<Point>& p) {
    sort(all(p));
    Polygon s;
    if (SZ(p) <= 1) return p;
    rep(i, 0, SZ(p)) {
        while (SZ(s) > 1 && OnLeft(p[i], s[SZ(s) - 2], s[SZ(s) - 1]) <= 0) s.pop_back();
        s.eb(p[i]);
    }
    int tmp = s.size();
    per(i, 0, SZ(p) - 1) {
        while (SZ(s) > tmp && OnLeft(p[i], s[SZ(s) - 2], s[SZ(s) - 1]) <= 0) s.pop_back();
        s.eb(p[i]);
    }
    if (p.size() > 1) s.pop_back();
    return s;
}
PT PolygonArea(Point *p, int n) {
    PT area = 0;
    rep(i, 1, n - 1) {
        area += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
    }
    return fabs(area/2);
}
int HalfPlaneInt(Line* L, int n, Point* Poly) {
    Point p[M];
    Line q[M];
    sort(L, L + n);
    int top = 0, bot = 0;
    q[0] = L[0];
    rep(i, 1, n) {
        while (top < bot && dcmp(OnLeft(p[bot - 1], L[i].P, L[i].P + L[i].V)) <= 0) -- bot;
        while (top < bot && dcmp(OnLeft(p[top], L[i].P, L[i].P + L[i].V)) <= 0) ++top;
        q[++bot] = L[i];
        if (dcmp(L[i].angle - q[bot - 1].angle) == 0) {
            --bot;
            if (dcmp(OnLeft(L[i].P, q[bot].P, q[bot].P + q[bot].V)) > 0) {
                    /*
                    cout << "!\n";
                    cout << L[i].P.x << " " << L[i].P.y << " " << L[i].V.x << " " << L[i].V.y << "\n";
                    cout << q[bot].P.x << " " << q[bot].P.y << " " << q[bot].V.x << " " << q[bot].V.y << "\n";
                    */
                    q[bot] = L[i];
            }
        }
        if (top < bot) {
            p[bot - 1] = GetLineIntersection(q[bot - 1].P, q[bot - 1].V, q[bot].P, q[bot].V);;
        }
    }
    while (top < bot && dcmp(OnLeft(p[bot - 1], q[top].P, q[top].P + q[top].V)) <= 0) --bot;
    if (bot - top <= 1) return 0;
    p[bot] = GetLineIntersection(q[bot].P, q[bot].V, q[top].P, q[top].V);
    int m = 0;
    repn(i, top, bot) Poly[m++] = p[i];
    return m;
}

int n, b[N];
PT dx, dy;
Point ap[M];
Line ln[M];
vector<Point> p;
Polygon poly;

int main() {
    IO;
    cin >> dx >> dy >> n;
    double x, y;
    rep(i, 0, n) {
        cin >> x >> y;
        p.pb(Point(x, y));
    }
    int pos = 0;
    rep(i, 0, n) {
        cin >> b[i];
        rep(j, 0, i) {
            ln[pos ++] = Line(p[b[i] - 1], p[b[j] - 1]);
        }
    }
    ln[pos ++] = Line(Point(0, 0), Point(dx, 0));
    ln[pos ++] = Line(Point(dx, 0), Point(dx, dy));
    ln[pos ++] = Line(Point(dx, dy), Point(0, dy));
    ln[pos ++] = Line(Point(0, dy), Point(0, 0));
    int m = HalfPlaneInt(ln, pos, ap);
    //rep(i, 0, pos) cout << ln[i].P.x << " " << ln[i].P.y << " " << ln[i].V.x << " " << ln[i].V.y << "\n";
    //rep(i, 0, m) cout << ap[i].x << " " << ap[i].y << "\n";
    cout << fixed << setprecision(12) << PolygonArea(ap, m) << "\n";
    return 0;
}
