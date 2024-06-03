// Problem: Inventory
// URL: https://codeforces.com/gym/102821/problem/I
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

int T, cnt, n, k;
int x[N];
double ans;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n >> k;
		repn(i, 1, n) cin >> x[i];
		double sum = 1.0;
		repn(i, 2, n) {
			double ratio = sqrt((double)x[i] / (double)x[1]);
			sum += ratio;
		}
		sum = k / sum;
		repn(i, 1, n) {
			double ratio = sqrt((double)x[i] / (double)x[1]);
			double v = sum * ratio;
			ans += x[i] / v;
		}
		printf("Case %d: %.10f\n", ++cnt, ans);
	}
	return 0;
}