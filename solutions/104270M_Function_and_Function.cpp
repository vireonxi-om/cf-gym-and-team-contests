// Problem: Function and Function
// URL: https://codeforces.com/gym/104270/problem/M
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
typedef pair<LL, int> PLI;
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

int T, x, k, val[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int change(int x) {
	if (x == 0) return val[0];
	int sum = 0;
	while (x) sum += val[x % 10], x /= 10;
	return sum;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> x >> k;
		while (k) {
			x = change(x);
			k--;
			if (x == 1) {
				if (k & 1) x = 0;
				break;
			}
		}
		cout << x << "\n";
	}
	return 0;
}