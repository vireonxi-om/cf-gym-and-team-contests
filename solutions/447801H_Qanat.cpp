// Problem: Qanat
// URL: https://codeforces.com/gym/447801/problem/H
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
const double pi = acos(-1.0);

double w, h;
int n;
double x[N], tmp[N];

int main()
{
	IO;
	cin >> w >> h >> n;
	double t = w / h, num = (2 * t * t) / (t * t - 1);
	tmp[1] = 1; tmp[2] = num;
	repn(i, 3, n + 1) {
		tmp[i] = num * tmp[i - 1] - tmp[i - 2];
	}
	x[1] = w / tmp[n + 1]; x[0] = 0;
	repn(i, 2, n) {
		x[i] = num * x[i - 1] - x[i - 2];
	}
	x[n + 1] = w;
	double ans = 0;
	repn(i, 1, n + 1) {
		double len = (x[i - 1] / t + x[i] - x[i - 1] + x[i] / t) / 2;
		ans += len * len; 
	}
	repn(i, 1, n) {
		double len = x[i] / t; ans -= len * len / 2; 
	}
	cout << fixed << setprecision(8) << ans << "\n";
	repn(i, 1, min(10, n)) cout << fixed << setprecision(8) << x[i] << "\n";
	return 0;
}