// Problem: Pho Restaurant
// URL: https://codeforces.com/problemset/problem/1938/H
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
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

const int N = 110000;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, ans, yes = 1, a[N], b[N], flag[2], num[2];
string s;
vector<int> nxt, res;

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> s;
		for (auto x : s) {
			if (x == '0') {
				a[i] ++;
			}
			else b[i] ++;
		}
		if (a[i] < b[i]) {
			flag[1] ++;
			num[0] += a[i];
			ans += a[i];
			nxt.pb(b[i] - a[i]);
		}
		else if (b[i] < a[i]) {
			flag[0] ++;
			num[1] += b[i]; 
			ans += b[i];
			nxt.pb(a[i] - b[i]);
		}
		else {
			res.pb(i);
		}
	}
	for (auto i : res) {
		if (flag[0] + 1 == n) {
			flag[1] ++;
			ans += a[i];
		}
		else {
			flag[0] ++;
			ans += a[i];
		}
	}
	if (num[0] && flag[1] == n || num[1] && flag[0] == n) {
		sort(all(nxt));
		ans += nxt[0];
	}
	cout << ans << "\n";
	return 0;
}