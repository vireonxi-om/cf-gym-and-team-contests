// Problem: Knights of the Frozen Throne
// URL: https://codeforces.com/gym/103202/problem/E
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
LL a, b[N];
vector<int> tmp, delta, way;
map<int, int> times;
LL res, ans;
map<int, vector<int> > f;
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		int k, last = 0;
		cin >> k;
		repn(j, 1, k) {
			int x;
			cin >> x;
			if (x != last) tmp.pb(x);
			if (j > 1 && x != last) {
				delta.pb(x - last + 1);
				f[x - last + 1].pb(x);
			}
			
			last = x;
		}
	}
	cin >> a;
	repn(i, 1, n) cin >> b[i], b[i] *= i;
	for (auto x: tmp) {
		times[x]++;
		res += b[times[x]] - b[times[x] - 1];
	}
	LL num = tmp.size();
	ans = res + a * num;
	way.pb(1);
	sort(all(delta));
	tmp.clear();
	if (delta.size() == 0);
	else tmp.pb(delta[0]);
	rep(i, 1, delta.size()) if (delta[i] != delta[i - 1]) tmp.pb(delta[i]);
	for (auto x: tmp) {
		res += a * (x - 1) * f[x].size();
		num -= f[x].size();
		for (auto y: f[x]) {
			times[y]--;
			res += b[times[y]] - b[times[y] + 1];
		}
		if (ans > res + a * num * x) ans = res + a * num * x, way.clear();
		if (ans == res + a * num * x) way.pb(x);
	}
	
	cout << ans << " " << way.size() << "\n";
	for (auto x: way) cout << x << " ";
	return 0;
}