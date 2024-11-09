// Problem: Circular DNA
// URL: https://codeforces.com/gym/470025/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 1100000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int n, ans[N]; 
vector<PII> a[N], b;
int pr[N], lf[N], rt[N];

int snum(string s) {
	int b = 1, num = 0;
	per(i, 0, s.length()) {
		num += (s[i] - '0') * b;
		b *= 10;
	}
	return num;
}

int main() {
	cin >> n;
	string s;
	repn(i, 1, n) {
		cin >> s;
		int num = 1;
		if (s[0] == 's') num = 0;
		a[snum(s.substr(1))].pb(mp(num, i));
	}
	int T = 1e6;
	repn(id, 1, T) {
		int tot = a[id].size();
		if (!tot) continue;
		repn(j, 0, tot) {
			pr[j] = lf[j] = rt[j] = 0;
		}
		int s0 = 0, s1 = 0;
		int cur = 0, cnt = 0;
		rep(j, 0, tot) {
			if (a[id][j].fi) {
				s1 ++;
				if (cnt) cnt --;
				else cur ++; 
			}
			else {
				s0 ++;
				cnt ++;
			}
			pr[j] = cur;
		}
		int n1 = 0, n2 = 0;
		per(j, 0, tot) {
			if (a[id][j].fi) n1 ++;
			else {
				if (n1) n1 --; 
				else n2 ++;
			}
			lf[j] = n2; rt[j] = n1;
		}
		if (s1 != s0) continue;
		if (pr[tot - 1] == 0) {
			b.pb(mp(a[id][tot - 1].se + 1, a[id][0].se));
		} 
		rep(j, 0, tot - 1) {
			if (!rt[j + 1] && lf[j + 1] == pr[j]) {
				b.pb(mp(a[id][j].se + 1, a[id][j + 1].se));
			}
		}
	}
	for (auto x : b) {
		if (x.fi == n + 1) x.fi = 1;
		if (x.fi > x.se) {
			ans[x.fi] ++; ans[n + 1] --; 
			x.fi = 1;
		}
		ans[x.fi] ++; ans[x.se + 1] --;
	}
	int cur = 0, mx = 0, pos = 1;
	repn(i, 1, n) {
		cur += ans[i];
		if (cur > mx) {
			mx = cur; pos = i;
		}
	}
	cout << pos << " " << mx << "\n";
	return 0;
}
