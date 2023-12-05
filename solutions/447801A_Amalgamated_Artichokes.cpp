// Problem: Amalgamated Artichokes
// URL: https://codeforces.com/gym/447801/problem/A
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

double q, a, b, c, d;
int n;
 
double f(int i) {
	return q * (sin(a * i + b) + cos(c * i + d) + 2);
}

int main()
{
	IO;
	cin >> q >> a >> b >> c >> d >> n;
	double mx = f(1), ans = 0;
	repn(i, 2, n) {
		ans = max(ans, mx - f(i));
		mx = max(mx, f(i));
	} 
	cout << fixed << setprecision(9) << ans << "\n";
	return 0;
}