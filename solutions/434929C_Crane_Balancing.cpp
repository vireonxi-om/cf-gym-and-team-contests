// Problem: Crane Balancing
// URL: https://codeforces.com/gym/434929/problem/C
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

const int N = 1100000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

vector<PII> p;
int n; 

int pd(PII p1, PII p2) {
	return p1.fi * p2.se - p1.se * p2.fi;
}

int main() {
	IO; 
	cin >> n;
	int l1 = 3000, r1 = -3000;
	int n1, n2;
	repn(i, 1, n) {
		cin >> n1 >> n2;
		p.pb(mp(n1, n2));
		if (n2 == 0) {
			l1 = min(l1, n1); 
			r1 = max(r1, n1); 
		}
	}
	p.pb(p[0]);
	int sums = 0;
	LL sumx = 0;
	rep(i, 0, n) {
		sums += pd(p[i], p[i + 1]);
		sumx += (LL) pd(p[i], p[i + 1]) * (p[i].fi + p[i + 1].fi);
	}
	LD s1 = (LD) sums / 2, x1 = (LD) sumx / (3 * sums);
	if (s1 < eps) s1 = -s1;
	LD x2 = p[0].fi, l = l1, r = r1;
	//cout << s1 << " " << x1 << "\n";
	bool ans = false;
	if (p[0].fi < l1) {
		LD a = (r - x1) * s1 / (x2 - r);
		LD b = (l - x1) * s1 / (x2 - l);
		if (b - a > -eps && b > -eps) {
			ans = true;
			a = max(a, (LD)eps);
			cout << (int)floor(a + eps) << " .. " << (int)ceil(b - eps) << "\n";
		}
	}
	else if (p[0].fi > l1 && p[0].fi < r1) {
		LD a = (r - x1) * s1 / (x2 - r);
		LD b = (l - x1) * s1 / (x2 - l);
		ans = true;
		a = max(a, b);
		a = max(a, (LD)eps);
		cout << (int)floor(max(a, b) + eps) << " .. inf" << "\n";
	}
	else if (p[0].fi > r1) {
		LD a = (l - x1) * s1 / (x2 - l);
		LD b = (r - x1) * s1 / (x2 - r);
		if (b - a > -eps && b > -eps) {
			ans = true;
			a = max(a, (LD)eps);
			cout << (int)floor(a + eps) << " .. " << (int)ceil(b - eps) << "\n";
		}
	}
	else if (p[0].fi == l1) {
		LD a = (r - x1) * s1 / (l - r);
		if (x1 - l > -eps) {
			ans = true;
			a = max(a, (LD)eps);
			cout << (int)floor(a + eps) << " .. inf" << "\n";
		}
	}
	else {
		LD a = (l - x1) * s1 / (r - l);
		if (x1 - r < eps) {
			ans = true;
			a = max(a, (LD)eps);
			cout << (int)floor(a + eps) << " .. inf" << "\n";
		}
	}
	if (!ans) cout << "unstable\n";
	return 0;
}

