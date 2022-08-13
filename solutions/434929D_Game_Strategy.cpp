// Problem: Game Strategy
// URL: https://codeforces.com/gym/434929/problem/D
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
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int pw(int b, int p) {
	if (p == 0) return 1;
	int res = pw(b, p / 2);
	return (p % 2) ? b * res * res : res * res;
}

int n, ans[25], res[25][25];
vector<int> op[25], tmp;


int main() {
	IO; 
	cin >> n;
	int m;
	string s;
	//cout << pw(2, 0) << " " << pw(2, 3) << " " << pw(2, 4) << "\n";
	rep(i, 0, n) {
		cin >> m;
		repn(j, 1, m) {
			cin >> s;
			int now = 0;
			for (auto x : s) {
				now += pw(2, x - 'a');
			}
			op[i].pb(now);
		}
	}
	rep(i, 0, n) {
		int cur = 1, now = pw(2, i);
		rep(j, 0, n) ans[j] = -1;
		ans[i] = 0;
		while (1) {
			tmp.clear();
			rep(j, 0, n) {
				if (ans[j] != -1) continue;
				bool yes = false;
				for (auto x : op[j]) {
					if ((x | now) > now) continue;
					yes = true;
				}
				if (yes) tmp.pb(j);				
			}
			if (tmp.size() == 0) break;
			for (auto id : tmp) {
				ans[id] = cur;
				now += pw(2, id);
			} 
			cur ++;
		}
		rep(j, 0, n) res[j][i] = ans[j];
	}
	rep(i, 0, n) {
		rep(j, 0, n) cout << res[i][j] << " "; 
		cout << "\n";
	} 
	return 0;
}

