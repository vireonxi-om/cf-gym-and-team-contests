// Problem: Evolution in Parallel
// URL: https://codeforces.com/gym/447801/problem/E
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

const int N = 4100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
string s[N];
int check(int x, int y) {
	int n = s[x].size(), m = s[y].size(), cur = 0;
	rep(i, 0, n) {
		if (cur == m) return 0;
		while (s[y][cur] != s[x][i]) {
			cur++;
			if (cur == m) return 0;
		}
		cur++;
	}
	return 1;
}
vector<int> f[N];
int a[N], num, que[N], head = 1, tail;
vector<int> ans[2];
int cmp(int x, int y) {
	return s[x].size() < s[y].size();
}
int main() {
	IO;
	cin >> n;
	repn(i, 0, n) cin >> s[i];
	repn(i, 1, n) if (!check(i, 0)) {
		cout << "impossible\n";
		return 0;
	}
	repn(i, 1, n) a[i] = i;
	sort(a + 1, a + n + 1, cmp);
	repn(i, 1, n) {
		int id = a[i];
		if (num == 0) ans[0].pb(id), num = 1;
		else if (num == 1) {
			if (check(ans[0][ans[0].size() - 1], id)) ans[0].pb(id);
			else ans[1].pb(id), num = 2;
		}
		else {
			int f0 = check(ans[0][ans[0].size() - 1], id);
			int f1 = check(ans[1][ans[1].size() - 1], id);
			if (f0 && f1) {
				// que[++tail] = id;
				if (head > tail) que[++tail] = id;
				else if (check(que[tail], id)) que[++tail] = id;
				else {
					ans[0].pb(id);
					while (head <= tail) ans[1].pb(que[head]), head++;
				}
			}
			else if (!f0 && !f1) {
				cout << "impossible\n";
				return 0;
			}
			else if (f0) {
				ans[0].pb(id);
				while (head <= tail) ans[1].pb(que[head]), head++;
			}
			else {
				ans[1].pb(id);
				while (head <= tail) ans[0].pb(que[head]), head++;
			}
		}
	}
	while (head <= tail) ans[0].pb(que[head]), head++;
	cout << ans[0].size() << " " << ans[1].size() << "\n";
	for (auto x: ans[0]) cout << s[x] << "\n";
	for (auto x: ans[1]) cout << s[x] << "\n";
	return 0;
}