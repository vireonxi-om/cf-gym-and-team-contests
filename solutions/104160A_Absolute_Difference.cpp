// Problem: Absolute Difference
// URL: https://codeforces.com/gym/104160/problem/A
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, flaga, flagb;
PII ca[N], cb[N];
pair<LD, LD> a[N], b[N];
LD ans, sum1, len1, sum2, len2, lena, lenb;
inline void cal(LD la, LD ra, LD lb, LD rb) {
	LD pa = (ra - la) / lena;
	LD pb = (rb - lb) / lenb;
	LD ex;
	if (abs(la - lb) < eps && abs(ra - rb) < eps) ex = (ra - la) / 3;
	else {
		LD ca = (ra + la) / 2;
		LD cb = (rb + lb) / 2;
		ex = abs(ca - cb);
	}
	ans += pa * pb * ex;
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> ca[i].fi >> ca[i].se;
	sort(ca + 1, ca + n + 1);
	repn(i, 1, n) a[i] = ca[i];
	repn(i, 1, m) cin >> cb[i].fi >> cb[i].se;
	sort(cb + 1, cb + m + 1);
	repn(i, 1, m) b[i] = cb[i];
	repn(i, 1, n) lena += a[i].se - a[i].fi;
	repn(i, 1, m) lenb += b[i].se - b[i].fi;
	b[m + 1] = a[n + 1] = mp(inf + 10, inf + 10);
	b[0] = a[0] = mp(-inf - 10, -inf - 10);
	if (lena < eps) flaga = 1, lena = n;
	if (lenb < eps) flagb = 1, lenb = m;
	repn(i, 2, n) sum2 += (a[i].fi + a[i].se) / 2 * max(a[i].se - a[i].fi, (LD)flaga), len2 += max(a[i].se - a[i].fi, (LD)flaga);
	int cur = 1;
	repn(i, 1, m) {
		while (cur <= n && b[i].fi > a[cur].se + eps) {
			sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
			len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
			cur++;
			sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
			len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
		}
		LD p;
		if (flagb) p = 1.0 / m;
		else p = (b[i].se - b[i].fi) / lenb;
		LD cx = (b[i].fi + b[i].se) / 2;
		// left
		if (cur > 1) ans += p * (cx - sum1 / max(len1, (LD)1.0)) * len1 / lena;
		// mid
		while (1) {
			if (cur == n + 1) break;
			if (a[cur].fi > b[i].se + eps) {
				LD cy = (a[cur].fi + a[cur].se) / 2;
				LD px;
				if (flaga) px = 1.0 / lena;
				else px = (a[cur].se - a[cur].fi) / lena;
				ans += abs(cy - cx) * px * p;
				break;
			}
			if (flaga && flagb) {
				ans += abs(a[cur].fi - b[i].fi) / lena / lenb;
				sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
				len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
				cur++;
				sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
				len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
			}
			else if (flaga) {
				if (b[i].fi - eps < a[cur].fi && b[i].se + eps > a[cur].fi) {
					LD cx1 = (b[i].fi + a[cur].fi) / 2;
					LD px1 = (a[cur].fi - b[i].fi) / lenb;
					LD cx2 = (a[cur].fi + b[i].se) / 2;
					LD px2 = (b[i].se - a[cur].fi) / lenb;
					ans += abs(cx1 - a[cur].fi) * px1 / lena + abs(cx2 - a[cur].fi) * px2 / lena;
					sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
					cur++;
					sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
				}
				else {
					LD cx = (b[i].fi + b[i].se) / 2;
					ans += abs(cx - a[cur].fi) * p / lena;
					sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
					cur++;
					sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
				}
			}
			else if (flagb) {
				if (a[cur].fi - eps < b[i].fi && a[cur].se + eps > b[i].fi) {
					LD cy1 = (a[cur].fi + b[i].fi) / 2;
					LD py1 = (b[i].fi - a[cur].fi) / lena;
					LD cy2 = (b[i].fi + a[cur].se) / 2;
					LD py2 = (a[cur].se - b[i].fi) / lena;
					ans += abs(cy1 -b[i].fi) * py1 * p + abs(cy2 -b[i].fi) * py2 * p;
					break;
				}
				else {
					LD cy = (a[cur].fi + a[cur].se) / 2;
					ans += abs(cy - b[i].fi) * p * (a[cur].se - a[cur].fi) / lena;
					sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
					cur++;
					sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
					len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
				}
			}
			else {
				if (a[cur].fi < b[i].fi + eps) {
					if (a[cur].se < b[i].se + eps) {
						cal(a[cur].fi, b[i].fi, b[i].fi, b[i].se);
						cal(b[i].fi, a[cur].se, b[i].fi, a[cur].se);
						cal(b[i].fi, a[cur].se, a[cur].se, b[i].se);
						sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
						len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
						cur++;
						sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
						len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
					}
					else {
						cal(a[cur].fi, b[i].fi, b[i].fi, b[i].se);
						cal(b[i].fi, b[i].se, b[i].fi, b[i].se);
						cal(b[i].se, a[cur].se, b[i].fi, b[i].se);
						break;
					}
				}
				else {
					if (a[cur].se < b[i].se + eps) {
						cal(a[cur].fi, a[cur].se, b[i].fi, a[cur].fi);
						cal(a[cur].fi, a[cur].se, a[cur].fi, a[cur].se);
						cal(a[cur].fi, a[cur].se, a[cur].se, b[i].se);
						sum1 += (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
						len1 += max(a[cur].se - a[cur].fi, (LD)flaga);
						cur++;
						sum2 -= (a[cur].fi + a[cur].se) / 2 * max(a[cur].se - a[cur].fi, (LD)flaga);
						len2 -= max(a[cur].se - a[cur].fi, (LD)flaga);
					}
					else {
						cal(a[cur].fi, a[cur].se, b[i].fi, a[cur].fi);
						cal(a[cur].fi, b[i].se, a[cur].fi, b[i].se);
						cal(b[i].se, a[cur].se, a[cur].fi, b[i].se);
						break;
					}
				}
			}
		}
		// right
		if (cur < n) ans += p * (sum2 / max(len2, (LD)1.0) - cx) * len2 / lena;
	}
	printf("%.15f\n", (double)ans);
	return 0;
}