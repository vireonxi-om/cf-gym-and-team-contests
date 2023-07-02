// Problem: Perfect Palindrome
// URL: https://codeforces.com/gym/104128/problem/I
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

int n, cnt[30];
string s;

void solve() {
	cin >> s;
	n = s.length();
	repn(i, 0, 26) cnt[i] = 0;
 	for(auto x : s) cnt[x - 'a'] ++;
 	int m = 0;
	repn(i, 0, 25) m = max(m, cnt[i]);
	cout << n - m << "\n";
} 

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



