// Problem: Mobile Robot
// URL: https://codeforces.com/gym/102920/problem/G
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
LL d, a[N];
int check1(LL x) {
	LL l = a[1] - x, r = a[1] + x;
	repn(i, 2, n) {
		LL cl = a[i] - x, cr = a[i] + x;
		LL al = l + d, ar = r + d;
		l = max(cl, al);
		r = min(cr, ar);
	}
	return l <= r;
}
int check2(LL x) {
	LL l = a[1] - x, r = a[1] + x;
	repn(i, 2, n) {
		LL cl = a[i] - x, cr = a[i] + x;
		LL al = l - d, ar = r - d;
		l = max(cl, al);
		r = min(cr, ar);
	}
	return l <= r;
}
int main()
{
	IO;
	cin >> n >> d; d *= 2;
	repn(i, 1, n) cin >> a[i], a[i] *= 2;
	LL l = 0, r = 1e17, ans;
	while (l <= r) {
		LL mid = (l + r) / 2;
		if (check1(mid) || check2(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	LL d = ans / 2;
	cout << d;
	if (ans % 2) cout << ".5";
	else cout << ".0";
	return 0;
}