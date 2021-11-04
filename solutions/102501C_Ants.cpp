// Problem: Ants
// URL: https://codeforces.com/gym/102501/problem/C
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
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
int pp[M];
string s;
int cal(string &s) {
	if (s[0] == '-') return -1;
	int res = 0;
	rep(i, 0, s.size()) {
		res = res * 10 + s[i] - '0';
		if (res > 1000000) return -1;
	}
	return res;
}
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		int val = cal(s);
		if (val != -1) pp[val] = 1;
	}
	repn(i, 0, 1000000) {
		if (!pp[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}