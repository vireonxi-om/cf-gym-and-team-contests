// Problem: Rock-Paper-Scissors Pyramid
// URL: https://codeforces.com/gym/104065/problem/M
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
const LL INF = 1e18 + 10;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n; 
string s;

void solve() {
	cin >> s; n = s.length();
	int cur = 0, mx = 0, mp = 0;
	rep(i, 1, n) {
		if (s[i] == s[i - 1]) continue;
		if (s[i] == 'S' && s[i - 1] == 'P') cur ++;
		else if (s[i] == 'P' && s[i - 1] == 'R') cur ++;
		else if (s[i] == 'R' && s[i - 1] == 'S') cur ++;
		else cur --;
		if (cur > mx) {
			mx = cur; mp = i;
		}
	}
	cout << s[mp] << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}
