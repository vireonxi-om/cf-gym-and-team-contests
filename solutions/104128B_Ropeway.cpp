// Problem: Ropeway
// URL: https://codeforces.com/gym/104128/problem/B
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


const int N = 510000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T, n, k, m;
LL a[N], pre[N], suf[N];
const int MAX=610000;
LL stmx[MAX][32], stmn[MAX][32];
int preLog2[MAX];

void st_prepare(int n, LL *array) {
	preLog2[1] = 0;
	repn(i, 2, n + 1) {
		preLog2[i] = preLog2[i - 1];
		if ((1 << preLog2[i] + 1) == i) preLog2[i]++;
	}
	pern(i, 0, n) {
		stmx[i][0] = stmn[i][0] = array[i];
		for (int j = 1; (i + (1 << j) - 1) <= n; j++) {
			stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1 << j - 1)][j - 1]);
			stmn[i][j] = min(stmn[i][j - 1], stmn[i + (1 << j - 1)][j - 1]);
		}
	}
}
LL query_max(int l, int r) {
	int len = r - l + 1, k = preLog2[len];
	return max(stmx[l][k], stmx[r - (1 << k) + 1][k]);
}
LL query_min(int l, int r) {
	int len = r - l + 1, k = preLog2[len];
	return min(stmn[l][k], stmn[r - (1 << k) + 1][k]);
}
string s;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		repn(i, 1, n) cin >> a[i];
		cin >> s;
		pre[0] = 0, suf[n + 1] = 0;
		priority_queue<PLI> q;
		q.push(mp(0, 0));
		repn(i, 1, n) {
			while (q.top().se + k < i) q.pop();
			pre[i] = -q.top().fi + a[i];
			if (s[i - 1] == '1') while (!q.empty()) q.pop();
			q.push(mp(-pre[i], i));
		}
		while (!q.empty()) q.pop();
		q.push(mp(0, n + 1));
		pern(i, 1, n) {
			while (q.top().se - k > i) q.pop();
			suf[i] = -q.top().fi + a[i];
			if (s[i - 1] == '1') while (!q.empty()) q.pop();
			q.push(mp(-suf[i], i));
		}
		st_prepare(n, pre);
		cin >> m;
		while (m--) {
			int x, v;
			cin >> x >> v;
			LL ans = pre[x] + suf[x] - a[x] - a[x] + v;
			if (s[x - 1] == '0') {
				int pos = 0;
				repn(i, max(1, x - k), x) if (s[i - 1] == '1') pos = i;
				repn(i, x + 1, min(x + k, n + 1)) { 
					int l = max(i - k, pos), r = x - 1;
					if (l <= r) ans = min(ans, query_min(l, r) + suf[i]);
					if (i == n + 1 || s[i - 1] == '1') break;
				}
			}
			cout << ans << "\n";
		}
			
	}
	return 0;
}