// Problem: Swap Space
// URL: https://codeforces.com/gym/452521/problem/L
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 9-64)
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
typedef pair<LL, LL> PLL;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 1100000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-15;
const double pi = acos(-1.0);

vector<PLL> a, b;
int n;

bool check(LL tot) {
	for (auto pr : a) {
		if (tot < pr.fi) return false;
		tot -= pr.se;
	}
	for (auto pr: b) tot += pr.se;
	if (tot < 0) return false;
	for (auto pr: b) {
		if (tot < pr.fi) return false;
		tot -= pr.se;
	}
	return true;
}

int main() {
	IO;
	cin >> n; 
	int num1, num2;
	LL sum = 0;
	repn(i, 1, n) {
		cin >> num1 >> num2;
		sum += num1;
		if (num2 - num1 < 0) b.pb(mp(num2, num2 - num1));
		else a.pb(mp(num1, num1 - num2));
	}
	sort(all(a)); sort(all(b));
	LL l = 1, r = sum, ans = sum;
	while (l <= r) {
		LL mid = (l + r) / 2;
		if(check(mid)) {
			ans = min(ans, mid); r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << "\n";
	return 0;
	
}