// Problem: Where Am I?
// URL: https://codeforces.com/gym/468812/problem/L
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 20000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int x, y;
vector<PII> a;
string s[110];
vector<int> b[110][110];
vector<PII> tmp;
PII idx[N];
int cmp(PII x, PII y) {
	return b[x.fi][x.se] < b[y.fi][y.se];
}
int main() {
	cin >> x >> y;
	swap(x, y);
	int tot = 0;
	rep(i, 0, x) {
		cin >> s[i];
		for (auto ch : s[i]) if (ch == 'X') tot ++;
	}
	int d = 1;
	a.pb(mp(0, 0));
	while (d < 250) {
		repn(i, 1, d) a.pb(mp(-1, 0));
		repn(i, 1, d) a.pb(mp(0, 1));
		d ++;
		repn(i, 1, d) a.pb(mp(1, 0));
		repn(i, 1, d) a.pb(mp(0, -1));
		d ++;
	}
	int pos = 0;
	rep(i, 0, x) {
		rep(j, 0, y) {
			idx[ ++pos] = mp(i, j);
			PII cur = mp(i, j);
			int cnt = 0, sum = 0;
			for (auto pr : a) {
				cur.fi += pr.fi; cur.se += pr.se;
				if (cur.fi < 0 || cur.fi >= x || cur.se < 0 || cur.se >= y) sum ++;
				else if (s[cur.fi][cur.se] == '.') sum ++;
				else {
					if (sum) {
						b[i][j].pb(sum); sum = 0;
					}
					b[i][j].pb(-1);
					cnt ++;
				}
				if (cnt >= tot) break;
			}
		}
	}
	sort(idx + 1, idx + x * y + 1, cmp);
	int lst = 0, now, mx = 0, sum = 0;
	repn(i, 1, x * y) {
		if (i == x * y) now = 0;
		else {
			int pos = 0;
			now = 0;
			while (b[idx[i].fi][idx[i].se][pos] == b[idx[i + 1].fi][idx[i + 1].se][pos]) {
				now += abs(b[idx[i].fi][idx[i].se][pos]); pos ++;
			}
			int n1 = b[idx[i].fi][idx[i].se][pos], n2 = b[idx[i + 1].fi][idx[i + 1].se][pos];
			if (n1 > 0 && n2 > 0) now += min(n1, n2);
		}
		int res = max(now, lst);
		if (res > mx) {
			tmp.clear(); mx = res;
			tmp.pb(mp(x - idx[i].fi, idx[i].se + 1));
		}
		else if (res == mx) tmp.pb(mp(x - idx[i].fi, idx[i].se + 1));
		sum += res;
		
		lst = now;
	}
	double avg = (double) sum / x / y;
	cout << fixed << setprecision(10) << avg << "\n";
	cout << mx << "\n";
	sort(all(tmp));
	for (auto pr : tmp) cout << "(" << pr.se << "," << pr.fi << ") ";
	cout << "\n";
	return 0;
}
