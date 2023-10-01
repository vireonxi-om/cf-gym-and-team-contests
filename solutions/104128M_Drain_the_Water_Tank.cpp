// Problem: Drain the Water Tank
// URL: https://codeforces.com/gym/104128/problem/M
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
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
const double pi = acos(-1.0);
inline int dcmp(LD x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    LD x , y;
    Point (LD x = 0 , LD y = 0) : x(x) , y(y) {}
    void input() {
        cin >> x >> y;
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
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const double& R) const {
        return Point(x * R , y * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R , y / R);
    }
    LD operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    LD operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
}p[N];
bool SegmentProperIntersection(Point a1 , Point a2 , Point b1 , Point b2) {
    LD c1 = (a2 - a1) ^ (b1 - a1);
    LD c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2);
    }
    LD c3 = (b2 - b1) ^ (a1 - b1);
    LD c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
int ans;
int main() {
	IO;
	cin >> n;
	rep(i, 0, n) p[i].input();
	rep(i, 0, n) {
		int pre = (i - 1 + n) % n, nxt = (i + 1) % n;
		if (p[pre].y < p[i].y + eps) continue;
		while (dcmp(p[i].y - p[nxt].y) == 0) nxt = (nxt + 1) % n;
		if (p[nxt].y < p[i].y + eps) continue;
		Point st = p[i] - Point(0, 0.00001);
		Point ed = st - Point(1, 0.0000001) * 10000000;
		int cnt = 0;
		rep(j, 0, n) {
			int x = j, y = (x + 1) % n;
			if (x == i || y == i) continue;
			if (SegmentProperIntersection(st, ed, p[x], p[y])) cnt++;
		}
		if (cnt % 2 == 0) ans++;
	}
	cout << ans << "\n";
	return 0;
}