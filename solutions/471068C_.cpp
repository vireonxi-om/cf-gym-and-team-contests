// Problem: 
// URL: https://codeforces.com/gym/471068/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 260000;
const int M = 1100;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int x, y, k;

void solve(){
	cin >> x >> y >> k;
	if (x <= y) {
		int n1 = 11 * y - 9 * x, n2 = 2 * x + 11 * y;
		n1 = n1 * k;
		int t = (n1 + n2 - 1) / n2;
		cout << k - t << "\n";
	}
	else {
		cout << k << "\n";
	}
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T)  {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
