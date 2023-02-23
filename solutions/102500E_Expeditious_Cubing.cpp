// Problem: Expeditious Cubing
// URL: https://codeforces.com/gym/102500/problem/E
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 410000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const int INF = 1e8;
const double eps = 1e-9;

double t[10], nt[10], s;
int check(double x) {
	repn(i, 1, 4) nt[i] = t[i];
	nt[5] = x;
	sort(nt + 1, nt + 5 + 1);
	double sum = 0;
	repn(i, 2, 4) sum += nt[i];
	sum /= 3;
	return sum < s + eps;
}
int main() {
	IO;
	repn(i, 1, 4) cin >> t[i];
	cin >> s;
	double l = 0.5, r = 20.5;
	rep(i, 0, 1000) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	if (l < 1 - eps) printf("impossible\n");
	else if (l > 20 + eps) printf("infinite\n");
	else printf("%.2f\n", l);
	return 0;
}