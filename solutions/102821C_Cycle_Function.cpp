// Problem: Cycle Function
// URL: https://codeforces.com/gym/102821/problem/C
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
const double inf = 1e18;
const double eps = 1e-7;

int T, n, m, cas;
double x[N], c[N], d[N], a, b;
double pre[N], suf[N];
int main()
{
	IO;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %lf %lf", &n, &m, &a, &b);
		repn(i, 1, n) scanf("%lf", &x[i]);
		repn(i, 1, m) scanf("%lf %lf", &c[i], &d[i]);
		sort(x + 1, x + n + 1);
		pre[0] = suf[n + 1] = 0;
		repn(i, 1, n) pre[i] = pre[i - 1] + x[i];
		pern(i, 1, n) suf[i] = suf[i + 1] + x[i];
		printf("Case %d:\n", ++cas);
		x[n + 1] = inf;
		x[0] = -inf;
		repn(i, 1, m) {
			double ans = 0;
			
			// f(g(x)) - x
			{
				double na = a * c[i];
				double nb = a * d[i] + b;
				double ma = na - 1;
				double mb = -nb;
				if (abs(ma) > eps) {
					if (ma > 0) {
						double thresh = mb / ma;
						int pos = lower_bound(x + 1, x + n + 2, thresh) - x;
						pos--;
						// >
						ans -= nb * (pos);
						ans += nb * (n - pos);
						 
						ans -= ma * pre[pos];
						ans += ma * suf[pos + 1];
					}
					else {
						double thresh = mb / ma;
						int pos = lower_bound(x + 1, x + n + 2, thresh) - x;
						pos--;
						// <
						ans += nb * (pos);
						ans -= nb * (n - pos);
						
						ans += ma * pre[pos];
						ans -= ma * suf[pos + 1];
					}
				}
				else {
					ans += abs(nb) * n;
				}
			}
			
			// g(f(x)) - x
			{
				double na = a * c[i];
				double nb = b * c[i] + d[i];
				double ma = na - 1;
				double mb = -nb;
				if (abs(ma) > eps) {
					if (ma > 0) {
						double thresh = mb / ma;
						int pos = lower_bound(x + 1, x + n + 2, thresh) - x;
						pos--;
						// >
						ans -= nb * (pos);
						ans += nb * (n - pos);
						 
						ans -= ma * pre[pos];
						ans += ma * suf[pos + 1];
					}
					else {
						double thresh = mb / ma;
						int pos = lower_bound(x + 1, x + n + 2, thresh) - x;
						pos--;
						// <
						ans += nb * (pos);
						ans -= nb * (n - pos);
						
						ans += ma * pre[pos];
						ans -= ma * suf[pos + 1];
					}
				}
				else {
					ans += abs(nb) * n;
				}
			}
			
			
			printf("%.10f\n", ans);
		}
	}
	return 0;
}