// Problem: The Boomsday Project
// URL: https://codeforces.com/gym/103202/problem/H
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

const int N = 310000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;
int n, m, r, allq;
vector<LL> f[N];
int d[N], t[N], c[N];
PII a[N], pos[N];
LL ans = 1e18;
int main()
{
	IO;
	cin >> n >> m >> r;
	repn(i, 1, n) cin >> d[i] >> t[i] >> c[i], d[i]--;
	repn(i, 1, m) cin >> a[i].fi >> a[i].se, allq += a[i].se;
	sort(a + 1, a + m + 1);
	LL sum = 0;
	int num = 0;
	repn(i, 1, m) {
		f[i].resize(a[i].se + 1);
		repn(j, 0, a[i].se) {
			if (j) {
				sum += r;
				num++;
			}
			pos[num] = mp(i, j);
			f[i][j] = sum;
		}
	}
	sum = 0;
	a[m + 1] = mp((2e9) + 10, 0); 
	repn(i, 1, m) {
		rep(k, 0, a[i].se) {
			repn(j, 1, n) {
				if (k + t[j] < a[i].se) f[i][k + t[j]] = min(f[i][k + t[j]], f[i][k] + c[j]);
			}
			f[i][k + 1] = min(f[i][k + 1], f[i][k] + r);
		}
		if (i == m) {
			ans = min(ans, f[i][a[i].se]);
		}
		else f[i + 1][0] = min(f[i + 1][0], f[i][a[i].se]);
		repn(j, 1, n) {
			int valid = a[i].fi + d[j];
			int date = upper_bound(a + 1, a + 2 + m, mp(valid, 2 * inf)) - a;
			date--;
			repn(k, max(a[i].se - t[j], 0), a[i].se) {
				LL cost = f[i][k] + c[j];
				if (sum + k + t[j] >= allq) {
					if (a[m].fi > a[i].fi + d[j]) {
						f[date + 1][0] = min(f[date + 1][0], cost);
					}
					else ans = min(ans, cost);
				}
				else {
					PII nxt = pos[sum + k + t[j]];
					int day = nxt.fi;
					int idx = nxt.se;
					if (a[day].fi > a[i].fi + d[j]) {
						f[date + 1][0] = min(f[date + 1][0], cost);
					}
					else {
						f[day][idx] = min(f[day][idx], cost);
					}
				}
			}
		}
		sum += a[i].se;
	}
	cout << ans << endl;
	return 0;
}