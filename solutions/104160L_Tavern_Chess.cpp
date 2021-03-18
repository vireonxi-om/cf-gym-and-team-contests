// Problem: Tavern Chess
// URL: https://codeforces.com/gym/104160/problem/L
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

const int N = 210000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, a[15][15][2]; 
double alice = 0, bob = 0, ti = 0;

void att(int t, int n1, int m1, int dep, double p) {
	//check if end, update ans
	int a1 = 0, b1 = 0;
	repn(i, 1, n) if (a[dep][i][1] > 0) a1 ++;
	repn(i, n + 1, n + m) if (a[dep][i][1] > 0) b1 ++;
	if (a1 == 0 && b1 == 0) {
		ti += p;
		return;
	}
	else if (a1 == 0) {
		bob += p;
		return;
	}
	else if (b1 == 0) {
		alice += p; 
		return;
	}
	//iterate possible attack
		//update next a[], next n1, m1, t, p, dep, 
	repn(i, 1, n + m) {
		repn(j, 0, 1) a[dep + 1][i][j] = a[dep][i][j];
	}
	if (t == 0) {
		while (n1 <= n && a[dep][n1][1] <= 0) n1 ++;
		if (n1 > n) n1 = 1;
		while (n1 <= n && a[dep][n1][1] <= 0) n1 ++;
		int cnt = b1;
		repn(j, n + 1, n + m) {
			if (a[dep][j][1] <= 0) continue;
			a[dep + 1][j][1] -= a[dep][n1][0];
			a[dep + 1][n1][1] -= a[dep][j][0];
			att(1, n1 + 1, m1, dep + 1, p / cnt);
			a[dep + 1][j][1] += a[dep][n1][0];
			a[dep + 1][n1][1] += a[dep][j][0];
		}
	}
	else {
		while (m1 <= n + m && a[dep][m1][1] <= 0) m1 ++;
		if (m1 > n + m) m1 = n + 1;
		while (m1 <= n + m && a[dep][m1][1] <= 0) m1 ++;
		int cnt = a1;
		repn(j, 1, n) {
			if (a[dep][j][1] <= 0) continue;
			a[dep + 1][j][1] -= a[dep][m1][0];
			a[dep + 1][m1][1] -= a[dep][j][0];
			att(0, n1, m1 + 1, dep + 1, p / cnt);
			a[dep + 1][j][1] += a[dep][m1][0];
			a[dep + 1][m1][1] += a[dep][j][0];
		}
	}
	
}

int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> a[0][i][0];
		a[0][i][1] = a[0][i][0];
	}
	repn(i, n + 1, n + m) {
		cin >> a[0][i][0];
		a[0][i][1] = a[0][i][0];
	}
	if (n > m) att(0, 1, n + 1, 0, 1);
	else if (m > n) att(1, 1, n + 1, 0, 1);
	else {
		att(0, 1, n + 1, 0, 0.5);
		att(1, 1, n + 1, 0, 0.5);
	} 
	cout << fixed << setprecision(12) << alice << "\n" << bob << "\n" << ti << "\n";
	return 0;	
}



