// Problem: Magic Multiplication 
// URL: https://codeforces.com/gym/104270/problem/D
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, m, l;
string s;
int a[N], b[N], flag;
int check() {
	int cur = 0;
	repn(i, 1, n) repn(j, 1, m) {
		if (cur == l) return 0;
		int x = s[cur] - '0', y;
		if (cur == l - 1) y = -1;
		else y = x * 10 + s[cur + 1] - '0';
		if (a[i] != -1 && b[j] != -1) {
			if (a[i] * b[j] == x) cur += 1;
			else if (a[i] * b[j] == y) cur += 2;
			else return 0;
		}
		else if (a[i] != -1) {
			int flag = 0;
			rep(k, 0, 10) {
				if (k * a[i] == x) {
					flag = 1;
					b[j] = k;
					cur += 1;
					break;
				}
				if (k * a[i] == y) {
					flag = 1;
					b[j] = k;
					cur += 2;
					break;
				}
			}
			if (!flag) return 0;
		}
		else if (b[j] != -1) {
			int flag = 0;
			rep(k, 0, 10) {
				if (k * b[j] == x) {
					flag = 1;
					a[i] = k;
					cur += 1;
					break;
				}
				if (k * b[j] == y) {
					flag = 1;
					a[i] = k;
					cur += 2;
					break;
				}
			}
			if (!flag) return 0;
		}
		else assert(false);
	}
	return cur == l;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cin >> s;
		l = s.size();
		if ((LL)n * m > l) {
			cout << "Impossible\n";
			continue;
		}
		flag = 0;
		rep(i, 1, 10) {
			repn(j, 1, n) a[j] = -1;
			repn(j, 1, m) b[j] = -1;
			a[1] = i;
			if (check()) {
				flag = 1;
				repn(j, 1, n) cout << a[j];
				cout << " ";
				repn(j, 1, m) cout << b[j];
				cout << "\n";
				break;
			}
		}
		if (!flag) cout << "Impossible\n";
	}
	return 0;
}