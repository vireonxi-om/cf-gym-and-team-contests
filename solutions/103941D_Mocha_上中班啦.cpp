// Problem: Mocha 上中班啦
// URL: https://codeforces.com/gym/103941/problem/D
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
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

const long double pi = acos(-1.0);
inline int dcmp(long double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    long double x, y;
    Point (long double x = 0 , long double y = 0) : x(x) , y(y) {}
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
    Point operator * (const long double& R) const {
        return Point(x * R, y * R);
    }
    Point operator / (const long double& R) const {
        return Point(x / R, y / R);
    }
    long double operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    long double operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    long double len() {
        return sqrt(*this % *this);
    }
    long double angle() {
        return atan2(y, x);
    }
}p[N], a[5], l;
// 两个向量的夹角，不分正负[0,pi)
long double Angle(Point A, Point B) {
    return acos((A % B) / A.len() / B.len());
}
// 点到线段距离，就是上面的代码判断一下P在AB上投影的位置。
long double DistancePointToSegment(Point P, Point A, Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A , v2 = P - A , v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
long double DistancePointToLine(Point P, Point A, Point B) {
    Point v = B - A;
    return (v ^ (P - A)) / v.len();
}

long double th[3], v[5];
vector<pair<long double, int>> it;

int main() {
    IO;
    int n;
    cin >> n; 
    repn(i, 1, n) {
        cin >> p[i].x >> p[i].y;
    }
    cin >> p[0].x >> p[0].y;
    repn(i, 1, 4) cin >> a[i].x >> a[i].y;
    l.x = a[1].x - a[2].x;
    l.y = a[1].y - a[2].y;
    long double d[3];
    d[1] = fabs(DistancePointToLine(p[0], a[1], a[2]));
    d[2] = fabs(DistancePointToLine(p[0], a[3], a[4]));
    repn(i, 1, n) {
        long double dis = fabs(DistancePointToLine(p[i], a[1], a[2]));
        long double dis2 = fabs(DistancePointToLine(p[i], p[0], p[0] + l));
        p[i].x -= p[0].x;
        p[i].y -= p[0].y;
        long double pl = p[i].len();
        if (dcmp(pl) == 0) {
            it.pb(mp(0, 1));
            it.pb(mp(2 * pi, 0));
            continue;
        }
        //cout << i << "\n" << d[1] << " " << d[2] << " "<< pl << " " << dis << "\n";
        repn(i, 1, 2) {
            if (dcmp(d[i] - pl) >= 0) th[i] = 0;
            else th[i] = acos(d[i] / pl);
        }
        long double pth = Angle(l, p[i]);
        if (dcmp(dis - d[1] - dis2) == 0) pth = 2 * pi - pth;
        //cout << pth << "\n";
        v[1] = 3*pi / 2 + th[2] - pth, v[2] = pi / 2 - th[1] - pth;
        v[3] = pi / 2 + th[1] - pth, v[4] = 3 * pi / 2 - th[2] - pth;
        repn(i, 1, 4) if (dcmp(v[i]) < 0) v[i] += 2 * pi;
        if (dcmp(v[1] - v[2]) >= 0) {
            it.pb(mp(v[1], 1));
            it.pb(mp(2 * pi, 0));
            it.pb(mp(0, 1));
            it.pb(mp(v[2], 0));
        }
        else {
            it.pb(mp(v[1], 1));
            it.pb(mp(v[2], 0));
        } 
        if (dcmp(v[3] - v[4]) >= 0) {
            it.pb(mp(v[3], 1));
            it.pb(mp(2 * pi, 0));
            it.pb(mp(0, 1));
            it.pb(mp(v[4], 0));
        }
        else {
            it.pb(mp(v[3], 1));
            it.pb(mp(v[4], 0));
        } 
    }
    sort(all(it));
    long double cnt = 0, st = -1;
    int num = 0;
    for (auto x : it ){
        if (x.se == 1) {
            num ++;
            if (num == n) st = x.fi;
        }
        else {
            if (num == n) cnt += x.fi - st;
            num --;
        }
    }
    cnt = cnt * 360 / (2 * pi);
    cout << fixed << setprecision(8) << cnt << "\n";
    return 0;
}



