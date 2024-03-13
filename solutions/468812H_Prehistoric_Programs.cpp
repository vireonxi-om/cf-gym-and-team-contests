// Problem: Prehistoric Programs
// URL: https://codeforces.com/gym/468812/problem/H
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, a[N], b[N], ans[N], m;
struct node {
	int a, b, id;
	friend bool operator < (node a, node b) {
		return a.a < b.a;
	}
};
vector<node> arr;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		int cnt = 0;
		string s;
		cin >> s;
		int l = s.size();
		rep(j, 0, l) {
			if (s[j] == '(') cnt++;
			else {
				cnt--;
				if (cnt <= 0) a[i] = max(a[i], abs(cnt));
			}
		}
		b[i] = cnt;
	}
	repn(i, 1, n) if (b[i] >= 0) {
		arr.pb({a[i], b[i], i});
	}
	sort(all(arr));
	int cur = 0;
	for (auto p: arr) {
		if (p.a > cur) {
			cout << "impossible\n";
			return 0;
		}
		cur += p.b;
		ans[++m] = p.id;
	}
	arr.clear();
	repn(i, 1, n) if (b[i] < 0) {
		arr.pb({a[i] + b[i], -b[i], i});
		cur += b[i];
	}
	if (cur != 0) {
		cout << "impossible\n";
		return 0;
	}
	sort(all(arr));
	m = n + 1;
	for (auto p: arr) {
		if (p.a > cur) {
			cout << "impossible\n";
			return 0;
		}
		cur += p.b;
		ans[--m] = p.id;
	}
	repn(i, 1, n) cout << ans[i] << "\n";
	return 0;
}