// Problem: Leverage MDT
// URL: https://codeforces.com/gym/102428/problem/L
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
int a[N][N], sum[N][2][N];
string s;
int check(int x) {
	repn(j, 1, m - x + 1) {
		int now = 0;
		repn(i, 1, n) {
			int val = 0;
			if (sum[i][0][j + x - 1] - sum[i][0][j - 1] == x) val = 1;
			if (sum[i][1][j + x - 1] - sum[i][1][j - 1] == x) val = 1;
			if (val) now++;
			else now = 0;
			if (now >= x) return 1;
		}
	}
	return 0;
}
			
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		cin >> s;
		repn(j, 1, m) {
			if (s[j - 1] == 'G') a[i][j] = 1;
			else a[i][j] = 0;
			sum[i][0][j] = sum[i][0][j - 1];
			sum[i][1][j] = sum[i][1][j - 1];
			sum[i][a[i][j]][j] = sum[i][a[i][j]][j - 1] + 1;
		}
	}
	int l = 1, r = min(n, m), ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans * ans << endl;
	return 0;
}