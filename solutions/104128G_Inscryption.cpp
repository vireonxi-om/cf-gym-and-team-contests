// Problem: Inscryption
// URL: https://codeforces.com/gym/104128/problem/G
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

const int N = 510000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;

void solve() {
	int cnt3 = 0, sum = 1, num = 1;
	cin >> n;
	int cur;
	bool can = true;
	repn(i, 1, n) {
		cin >> cur;
		if (cur == 0) {
			if (num >= 2) {
				cnt3 ++; num --;
			}
			else {
				sum ++; num ++;
			}
		}
		else if (cur == 1) {
			sum ++; num ++;
		}
		else {
			if (num >= 2) {
				num --;
			}
			else if (cnt3) {
				cnt3 --; sum ++; num += 2;
				num --; 
			}
			else {
				can = false;
			}
		}
	}
	if (!can) cout << -1 << "\n";
	else {
		int t = __gcd(sum, num);
		sum /= t; num /= t;
		cout << sum << " " << num << "\n";
	}
} 

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



