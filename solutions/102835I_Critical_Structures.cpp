// Problem: Critical Structures
// URL: https://codeforces.com/gym/102835/problem/I
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
const int M = 2100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, n, m;
int dfn[N], low[N], pp[N], f[N], cnt, bcn;
vector<int> g[N];
int st[N], tail;
int nans, mans, mx, ring;
void tarjan(int x, int par) {	
	int sc = 0;
	dfn[x] = low[x] = ++cnt;
	pp[x] = 1;
	st[++tail] = x;
	for (auto y: g[x]) {
		if (dfn[y] == 0) {
			int tmp = tail;
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x]) mans++;
			if (low[y] >= dfn[x]) {	
				sc++;
				ring++;
				mx = max(mx, f[y] + 1); 
				while (tail > tmp) {
					pp[st[tail]] = 0;
					tail--;
				}
			}
			else f[x] += f[y] + 1;
		}
		else if (y != par && pp[y]) {
			low[x] = min(low[x], dfn[y]);
			f[x] += dfn[y] < dfn[x];
		}
	}
	if (x != 1) sc++;
	nans += (sc >= 2);
}
int ans;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cnt = bcn = 0;
		repn(i, 1, n) dfn[i] = low[i] = pp[i] = f[i] = 0, g[i].clear();
		repn(i, 1, m) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y), g[y].pb(x);
		}
		nans = mans = mx = ring = tail = 0;
		tarjan(1, 0);
		mx = max(mx, f[1]);
		int d = __gcd(mx, ring);
		cout << nans << " " << mans << " " << ring / d << " " << mx / d << "\n";
	}
	return 0;
}