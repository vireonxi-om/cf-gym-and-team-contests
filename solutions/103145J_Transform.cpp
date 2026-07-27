// Problem: Transform
// URL: https://codeforces.com/gym/103145/problem/J
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

const double pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}
struct Point {
    double x , y , z;
    Point () {x = y = z = 0;}
    Point (double _x , double _y , double _z) {
        x = _x , y = _y , z = _z;
    }
    void input() {
        cin >> x >> y >> z;
    }
    bool operator < (const Point &R) const {
        if (dcmp(x - R.x) != 0)
            return x < R.x;
        if (dcmp(y - R.y) != 0)
            return y < R.y;
        return z < R.z;
    }
    bool operator == (const Point &R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0 && dcmp(z - R.z) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x , y + R.y , z + R.z);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y , z - R.z);
    }
    Point operator * (const double& R) const {
        return Point(x * R , y * R , z * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R , y / R , z / R);
    }
    double operator % (const Point& R) const {
        return x * R.x + y * R.y + z * R.z;
    }
    Point operator ^ (const Point& R) const {
        return Point(y * R.z - z * R.y , z * R.x - x * R.z , x * R.y - y * R.x);
    }
    inline double len() {
        return sqrt(*this % *this);
    }
    Point normalize() {
    	Point a = *this;
    	double l = a.len();
    	a.x /= l;
    	a.y /= l;
    	a.z /= l;
    	return a;
    }
}p1, p2, p, q; 


//a点绕Ob向量逆时针旋转弧度angle. cossin可预先计算
Point Rotate(Point a, Point b, double angle) {
    static Point e1 ,e2 , e3;
    b = b / b.len() , e3 = b;
    double lens = a % e3;
    e1 = a - e3 * lens;
    if (dcmp(e1.len()) > 0)
        e1 = e1 / e1.len();
    else
        return a;
    e2 = e1 ^ e3;
    double x1 = a % e2 , y1 = a % e1 , x2 , y2;
    x2 = x1 * cos(angle) - y1 * sin(angle);
    y2 = x1 * sin(angle) + y1 * cos(angle);
    return e3 * lens + e1 * y2 + e2 * x2;
}
/**
   绕任意轴（过原点）逆时针旋转（注意要把轴向量归一化，不然会在“点在轴上”这个情况下出问题）
   rotate x y z d 
   | (1-cos(d))*x*x+cos(d)     (1-cos(d))*x*y+sin(d)*z   (1-cos(d))*x*z-sin(d)*y   0 |
   | (1-cos(d))*y*x-sin(d)*z   (1-cos(d))*y*y+cos(d)     (1-cos(d))*y*z+sin(d)*x   0 |
   | (1-cos(d))*z*x+sin(d)*y   (1-cos(d))*z*y-sin(d)*x   (1-cos(d))*z*z+cos(d)     0 |
   |           0                          0                           0            1 |
**/
int T;
double r;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		p1.input();
		p2.input();
		cin >> r;
		r = r / 180 * pi;
		p1 = p1.normalize();
		p = Rotate(p2, p1, r);
		q = Rotate(p2, p1, -r);
		if (p.z > q.z) printf("%.10f %.10f %.10f\n", p.x, p.y, p.z);
		else printf("%.10f %.10f %.10f\n", q.x, q.y, q.z);
	}
	return 0;
}