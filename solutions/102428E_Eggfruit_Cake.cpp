// Problem: Eggfruit Cake
// URL: https://codeforces.com/gym/102428/problem/E
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, l, sum[N];
string s;
char t[N];
set<int> S;
vector<int> g[N];
int main()
{
	IO;
	cin >> s;
	cin >> l;
	n = s.size();
	repn(i, 1, 2 * n) {
		t[i] = s[(i - 1) % n];
		if (t[i] == 'E') sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
	}
	g[0].pb(0);
	LL ans = 0;
	repn(i, 1, 2 * n) {
		for (auto x: g[sum[i] - 1]) {
			if (x < n) S.insert(x);
		}
		g[sum[i] - 1].clear();
		while (S.size() > 0) {
			auto it = S.begin();
			if (i - (*it) > l) S.erase(*it);
			else break;
		}
		ans += S.size();
		g[sum[i]].pb(i);
	}
	cout << ans << endl;
	return 0;
}