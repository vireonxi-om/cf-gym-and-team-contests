// Problem: Heap Partition
// URL: https://codeforces.com/gym/104461/problem/F
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, a[N], num[N], col[N];
set<PII> S;
vector<int> arr[N];
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		repn(i, 1, n) num[i] = 0, arr[i].clear();
		S.clear();
		int ans = 0;
		repn(i, 1, n) {
			int x;
			cin >> x;
			a[i] = x;
			if (S.size() == 0) {
				ans++;
				col[i] = ans;
				S.insert(mp(x, i));
			}
			else {
				auto it = S.upper_bound(mp(x + 1, 0));
				if (it == S.begin()) {
					ans++;
					col[i] = ans;
					S.insert(mp(x, i));
				}
				else {
					it--;
					int id = (*it).se;
					col[i] = col[id];
					S.erase(it);
					num[id]++;
					if (num[id] < 2) S.insert(mp(a[id], id));
					S.insert(mp(x, i));
				}
			}
			arr[col[i]].pb(i);
		}
		cout << ans << "\n";
		repn(i, 1, ans) {
			cout << arr[i].size();
			for (auto x: arr[i]) cout << " " << x;
			cout << "\n";
		}
	}
	return 0;
}