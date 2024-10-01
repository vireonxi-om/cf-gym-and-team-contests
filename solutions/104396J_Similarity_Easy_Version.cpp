// Problem: Similarity (Easy Version)
// URL: https://codeforces.com/gym/104396/problem/J
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
typedef long double LD;
 
const int N = 310000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;
 
string s[60];
int n;

void solve() {
	cin >> n;
	repn(i, 1, n) cin >> s[i];
	int ans = 0;
	repn(i, 1, n) {
		repn(j, 1, n) {
			if (i == j) continue;
			int li = s[i].length(), lj = s[j].length();
			int mx_ij = 0;
			rep(k, 0, li) {
				int st = 0, cur = 0, mx = 0;
				rep(t, 0, lj) {
					if (k + t >= li) break;
					if (s[i][k + t] == s[j][t]) {
						if (st) cur ++;
						else {
							st = 1; cur = 1;
						}
						mx = max(mx, cur);
					}
					else {
						if (st) {
							cur = 0; st = 0;
						}
					}
				}
				mx_ij = max(mx_ij, mx);
			}
			ans = max(ans, mx_ij);
		}
	}
	cout << ans << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}

