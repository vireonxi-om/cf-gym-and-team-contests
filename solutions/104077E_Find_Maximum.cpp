// Problem: Find Maximum
// URL: https://codeforces.com/gym/104077/problem/E
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
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;
LL a[50];

LL ask(LL l, LL r) {
	if (l == r) {
		LL ans = 0;
		if (l == 0) ans = 1;
		while (l > 0) {
			ans += (l % 3);
			l /= 3; ans ++;
		}
		return ans;
	}
	if (l / 3 == r / 3) return ask(r, r);
	LL a = l / 3, b = (r - 3) / 3, ans = 0;
	if (a == 0){
		a ++;
		ans = 3;
	} 
	if (a <= b) ans = ask(a, b) + 3;
	ans = max(ans, ask(r, r));
	return ans;
}

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		LL l, r;
		cin >> l >> r;
		cout << ask(l, r) << "\n";
	}
	/*
	a[0] = 1;
	rep(i, 1, 50) {
		if (i % 3) a[i] = a[i - 1] + 1;
		else a[i] = a[i / 3] + 1;
	}
	repn(i, 1, 49) {
		repn(j, i, 49) {
			LL cur = 0;
			repn(k, i, j) cur = max(cur, a[k]);
			if (ask(i, j) != cur) cout << i << " " << j << "\n" << ask(i, j) << "\n";
		}
	}
	*/
	return 0;
}



