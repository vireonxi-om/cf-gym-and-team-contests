// Problem: Two Buildings
// URL: https://codeforces.com/gym/102920/problem/L
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, a[N], b[N];
LL h[N];
int t1, t2;
LL ans;
LL cal(int i, int j) {
	return (h[a[i]] + h[b[j]]) * (b[j] - a[i]);
}
void work(int l1, int r1, int l2, int r2) {
	if (l1 > r1 || l2 > r2) return;
	int mid = (l1 + r1) / 2;
	int pos = l2;
	LL mx = cal(mid, pos);
	repn(i, l2 + 1, r2) {
		if (a[mid] < b[i]) {
			LL tmp = cal(mid, i);
			if (mx < tmp) mx = tmp, pos = i;
		}
	}
	ans = max(ans, cal(mid, pos));
	work(l1, mid - 1, l2, pos);
	work(mid + 1, r1, pos, r2);
}
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) cin >> h[i];
	repn(i, 1, n) if (t1 == 0 || h[i] > h[a[t1]]) a[++t1] = i;
	pern(i, 1, n) if (t2 == 0 || h[i] > h[b[t2]]) b[++t2] = i;
	reverse(b + 1, b + 1 + t2);
	work(1, t1, 1, t2);
	cout << ans << endl;
	return 0;
}