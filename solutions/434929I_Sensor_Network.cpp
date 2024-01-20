// Problem: Sensor Network
// URL: https://codeforces.com/gym/434929/problem/I
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

const int N = 110;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand
#define list my

bitset<128> ans, res, g[N];

int n, d;
int x[N], y[N], p[N];
int sqr(int x) {
	return x * x;
}
int main() {
	IO;
	cin >> n >> d;
	repn(i, 1, n) cin >> x[i] >> y[i];
	repn(i, 1, n) repn(j, 1, n) if (i != j) {
		if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= sqr(d)) g[i].set(j);
	}
	repn(i, 1, n) p[i] = i;
	while(1.*clock() / CLOCKS_PER_SEC <= 1.9){
		random_shuffle(p + 1, p + n + 1);
		res.reset();
		res.set(p[1]);
		repn(i, 2, n) if ((g[p[i]] & res) == res) res.set(p[i]);
		if (res.count() > ans.count()) ans = res;
	}
	cout << ans.count() << "\n";
	repn(i, 1, n) if (ans.test(i)) cout << i << " ";
	return 0;
}