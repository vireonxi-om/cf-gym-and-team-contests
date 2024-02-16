// Problem: Master of Both
// URL: https://codeforces.com/gym/104090/problem/K
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
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, q, num[M], ch[M][26], pos = 1, root = 1;
LL f[26][26], sum; 
string s;
int main() {
	IO;
	cin >> n >> q;
	repn(i, 1, n) {
		cin >> s;
		int cur = root;
		rep(i, 0, s.size()) {
			int c = s[i] - 'a';
			rep(j, 0, 26) if (j != c) f[c][j] += num[ch[cur][j]];
			if (ch[cur][c]) cur = ch[cur][c];
			else cur = ch[cur][c] = ++pos;
			num[cur] += 1;
		}
		rep(i, 0, 26) sum += num[ch[cur][i]];
	}
	while (q--) {
		cin >> s;
		LL ans = sum;
		rep(i, 0, 26) {
			rep(j, i + 1, 26) {
				ans += f[s[i] - 'a'][s[j] - 'a'];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}