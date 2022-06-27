// Problem: Cockroaches
// URL: https://codeforces.com/gym/102055/problem/I
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
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int T, n, cas;
vector<int> r[N], c[N];
int nr[N], nc[N];
struct point {
	int x,y;
	void read() {
		cin >> x >> y;
	}
}p[N];
map<int,int> S;
int cc[N], num;
int mx;
LL ans;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cas++;
		cin >> n;
		repn(i, 1, n) p[i].read(), cc[i] = p[i].x;
		sort(cc + 1, cc + 1 + n);
		S.clear();
		S[cc[1]] = num = 1;
		repn(i, 2, n) {
			if (cc[i] != cc[i - 1]) S[cc[i]] = ++num;
		}
		repn(i, 1, n) p[i].x = S[p[i].x], cc[i] = p[i].y;
		sort(cc + 1, cc + 1 + n);
		S.clear();
		S[cc[1]] = num = 1;
		repn(i, 2, n) {
			if (cc[i] != cc[i - 1]) S[cc[i]] = ++num;
		}
		repn(i, 1, n) p[i].y = S[p[i].y];
		repn(i, 1, n) nc[i] = nr[i] = 0, r[i].clear(), c[i].clear();
		repn(i, 1, n) {
			int x = p[i].x, y = p[i].y;
			nr[x]++, nc[y]++;
			r[x].pb(y);
		}
		int mxr = 0, mxc = 0, nmxr = 0, nmxc = 0;
		repn(i, 1, n) {
			mxr = max(mxr, nr[i]);
			mxc = max(mxc, nc[i]);
		}
		repn(i, 1, n) {
			if (nr[i] == mxr) nmxr++;
			if (nc[i] == mxc) nmxc++;
		}
		int flag = 0;
		repn(i, 1, n) {
			if (nr[i] == mxr) {
				int nn = 0;
				for (auto y: r[i])
					if (nc[y] == mxc) nn++;
				if (nn != nmxc) flag = 1;
			}
		}
		mx = 0, ans = 0;
		if (flag) {
			mx = mxr + mxc;
			repn(i, 1, n) {
				if (nr[i] == mxr) {
					int nn = 0;
					for (auto y: r[i])
						if (nc[y] == mxc) nn++;
					ans += nmxc - nn;
				}
			}
			if (mxr == 1 && mxc == 1) ans /= 2;
		}
		else {
			mx = mxr + mxc - 1;
			if (mxc == 1 && mxr == 1) ans = 1;
			else if (mxc == 1) ans = nmxr;
			else if (mxr == 1) ans = nmxc;
			else ans = nmxc * nmxr;
			int nsxc = 0, nsxr = 0;
			if (mxr > 1) {
				LL res = 0;
				repn(i, 1, n) {
					if (nr[i] == mxr - 1) {
						int nn = 0;
						for (auto y: r[i])
							if (nc[y] == mxc) nn++;
						res += nmxc - nn;
					}
				}
				if (mxr == 2 && mxc == 1) ans += res / 2;
				else ans += res;
			}
			if (mxc > 1) {
				LL res = 0;
				repn(i, 1, n) if (nc[i] == mxc - 1) nsxc++;
				repn(i, 1, n) {
					if (nr[i] == mxr) {
						int nn = 0;
						for (auto y: r[i])
							if (nc[y] == mxc - 1) nn++;
						res += nsxc - nn;
					}
				}
				if (mxr == 1 && mxc == 2) ans += res / 2;
				else ans += res;
			}
		}
		cout << "Case " << cas << ": " << mx << " " << ans << "\n";
	}	
	return 0;
}