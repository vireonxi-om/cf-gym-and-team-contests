// Problem: Secret Chamber at Mount Rushmore
// URL: https://codeforces.com/gym/482684/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);
#define rand Rand

int n, m, pp[26][26];
int main() {
	IO;
	cin >> n >> m;
	rep(i, 0, 26) pp[i][i] = 1;
	repn(i, 1, n) {
		string s, t;
		cin >> s >> t;
		pp[s[0] - 'a'][t[0] - 'a'] = 1;
	}
	rep(k, 0, 26) rep(i, 0, 26) rep(j, 0, 26) if (pp[i][k] && pp[k][j]) pp[i][j] = 1;
	while (m--) {
		string s, t;
		cin >> s >> t;
		if (s.size() == t.size()) {
			int flag = 0;
			rep(i, 0, SZ(s)) if (!pp[s[i] - 'a'][t[i] - 'a']) flag = 1;
			if (flag) cout << "no\n";
			else cout << "yes\n";
		}
		else cout << "no\n";
	}
	return 0;
}