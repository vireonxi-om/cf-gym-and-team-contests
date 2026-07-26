// Problem: Edit Distance
// URL: https://codeforces.com/gym/102001/problem/A
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
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

string s;
int n0, n1, n;
int main()
{
	IO;
	cin >> s;
	n = s.size();
	rep(i, 0, n) {
		if (s[i] == '0') n0++;
		else n1++;
	}
	if (n0 == n1) {
		if (s[0] == '0') {
			cout << "1";
			rep(i, 1, n) cout << "0";
			cout << "\n";
		}
		else {
			cout << "0";
			rep(i, 1, n) cout << "1";
			cout << "\n";
		}
	}
	else if (n0 > n1) {
		rep(i, 0, n) cout << "1";
		cout << "\n";
	}
	else {
		rep(i, 0, n) cout << "0";
		cout << "\n";
	}
	return 0;
}