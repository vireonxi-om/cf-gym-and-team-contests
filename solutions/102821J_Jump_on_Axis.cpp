// Problem: Jump on Axis
// URL: https://codeforces.com/gym/102821/problem/J
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
const int M = 11000000;
const int mod = 1e9+7;
const int inf = 10000000;
const double eps = 1e-9;

int T, k, cnt;
int a[4][N], sum[4][N], num[4];
int ys[M];
LL f[N], inv[N], ff[N];
LL C(int n, int m) {
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}
int main()
{
	f[0] = 1;
	rep(i, 1, N)
		f[i] = (f[i - 1] * i) % mod;
	ff[1] = ff[0] = inv[1] = inv[0] = 1;  
	rep(i, 2, N) {
    	inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    	ff[i] = inv[i];
	}
	rep(i, 2, N)
		inv[i] = (inv[i - 1] * inv[i]) % mod;
	IO;
	repn(i, 1, 3) {
		a[i][0] = 0;
		a[i][1] = i;
		sum[i][1] = i;
		num[i] = 1;
		while (1) {
			num[i]++;
			a[i][num[i]] = a[i][num[i] - 1] + 3;
			sum[i][num[i]] = sum[i][num[i] - 1] + a[i][num[i]];
			if (sum[i][num[i]] > inf) break;
		}
	}
	memset(ys, -1, sizeof(ys));
	repn(i, 0, num[1]) {
		ys[sum[1][i]] = i;
	}
	cin >> T;
	while (T--) {
		cin >> k;
		int ans = 1e9, way = 0;
		for (int i = 0; i <= num[2] && sum[2][i] <= k; i++) {
			for (int j = 0; j <= num[3] && sum[3][j] + sum[2][i] <= k; j++) {
				int left = k - sum[2][i] - sum[3][j];
				if (ys[left] == -1) continue;
				int num = i + j + ys[left];
				LL tmp = C(num, i) * C(num - i, j) % mod;
				if (num < ans) ans = num;
				way = (way + tmp) % mod;
			}
		}
		printf("Case %d: %d %d\n", ++cnt, ans, way);
	}			
	return 0;
}