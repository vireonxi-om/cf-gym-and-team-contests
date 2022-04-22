// Problem: Seven Segment Display
// URL: https://codeforces.com/gym/104461/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int a[16] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
int T, n, b[8];
string s;
int cal(char x) {
	if (x >= '0' && x <= '9') return x - '0';
	return x - 'A' + 10;
}
LL sum[10], num[10], ans;
void add(int pos) {
	b[pos]++;
	while (b[pos] == 16) {
		b[pos] = 0;
		if (pos == 0) break;
		pos--;
		b[pos]++;
	}
}
int main() {
	IO;
	cin >> T;
	num[0] = 1;
	rep(i, 1, 10) num[i] = num[i - 1] * 16;
	rep(i, 0, 16) sum[1] += a[i];
	repn(i, 2, 8) sum[i] = sum[i - 1] / (i - 1) * 16 * i;
	while (T--) {
		cin >> n >> s;
		rep(i, 0, 8) b[i] = cal(s[i]);
		ans = 0;
		while (n) {
			int cnt = 0;
			per(i, 0, 8) if (b[i] == 0) cnt++; else break;
			while (n < num[cnt]) cnt--;
			LL res = 0;
			n -= num[cnt];
			rep(i, 0, 8 - cnt) res += a[b[i]];
			res *= num[cnt];
			res += sum[cnt];
			add(7 - cnt);
			ans += res;
		}
		cout << ans << "\n";
	}
	return 0;
}