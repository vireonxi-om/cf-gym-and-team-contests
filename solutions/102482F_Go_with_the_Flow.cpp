// Problem: Go with the Flow
// URL: https://codeforces.com/gym/102482/problem/F
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
typedef unsigned long long ull;
typedef long double LD;
typedef pair<int, int> PII;

const int N = 2600;
const int M = 210000;
const int mod = 1e9 + 7;
const int inf  = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int n, pos, ans, len[N], mn, mx, pp[2][M];
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		string s;
		cin >> s;
		len[i] = s.size();
		mn = max(mn, len[i]);
		mx += len[i] + 1;
	}
	repn(i, mn, mx) {
		int p = 0, cur = 0, head = 1;
		vector<int> tmp[2];
		while (head <= n) {
			if (cur + len[head] + (cur > 0) <= i) {
				if (cur) {
					pp[p ^ 1][cur + 1] = max(pp[p][cur], max(pp[p][cur + 1], pp[p][cur + 2])) + 1;
					if (pp[p ^ 1][cur + 1] > ans) ans = pp[p ^ 1][cur + 1], pos = i;
					tmp[p ^ 1].pb(cur + 1);
				}
				cur += len[head] + (cur > 0);
			}
			else {
				for (auto x: tmp[p]) pp[p][x] = 0;
				tmp[p].clear();
				p ^= 1;
				cur = len[head];
			}
			head++;
		}
		for (auto x: tmp[0]) pp[0][x] = 0;
		for (auto x: tmp[1]) pp[1][x] = 0;
		tmp[0].clear(), tmp[1].clear();
	}
	cout << pos << " " << ans << "\n";
	return 0;
}