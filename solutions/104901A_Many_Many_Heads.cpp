// Problem: Many Many Heads
// URL: https://codeforces.com/gym/104901/problem/A
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
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 510000;
const int M = 1;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
string s;

void solve() {
	cin >> s;
	n = s.length();
	int cur = -1, cnt = 0, sum = 0; 
	bool can = true;
	rep(i, 0, n) {
		int now = 0;
		if (s[i] == '[' || s[i] == ']') {
			now = 1;
		}
		if (now == cur) {
			cnt ++;
			if (cnt >= 3) can = false;
			if (cnt == 2) sum ++;
		} 
		else {
			cur = now; cnt = 1;
		}
	}
	if (!can || sum >= 3) cout << "No\n";
	else cout << "Yes\n";
} 

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}