// Problem: Serval 的俳句
// URL: https://codeforces.com/gym/103941/problem/E
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
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n;
string s;
int num[26], st = 0;
string ans;
int main() {
	IO;
	cin >> n;
	cin >> s;
	rep(i, 0, n) {
		num[s[i] - 'a']++;
		if (st == 0) {
			if (num[s[i] - 'a'] == 5) {
				rep(j, 0, 5) ans += s[i];
				memset(num, 0, sizeof(num));
				st = 1;
			}
		}
		else if (st == 1) {
			if (num[s[i] - 'a'] == 7) {
				rep(j, 0, 7) ans += s[i];
				memset(num, 0, sizeof(num));
				st = 2;
			}
		}
		else {
			if (num[s[i] - 'a'] == 5) {
				rep(j, 0, 5) ans += s[i];
				memset(num, 0, sizeof(num));
				break;
			}
		}
	}
	if (ans.size() == 17) cout << ans << "\n";
	else cout << "none\n";
	return 0;
}