// Problem: Nusret Gökçe
// URL: https://codeforces.com/gym/104114/problem/N
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
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, a[N];

int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		a[i + 1] = max(a[i + 1], a[i] - m);
	}
	per(i, 1, n) {
		a[i] = max(a[i], a[i + 1] - m);
	}
	repn(i, 1, n) cout << a[i] << " ";
	cout << "\n";
	return 0;
}



