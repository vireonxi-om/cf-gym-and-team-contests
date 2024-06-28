// Problem: Miser
// URL: https://codeforces.com/gym/102896/problem/M
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

int n;
int last[N], val[N], du[N], ans;
vector<int> g[N];
queue<int> que;
int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			if (last[x]) g[i].pb(last[x]), du[last[x]]++;
			last[x] = i;
		}
	}
	repn(i, 1, 100000) if (last[i]) g[0].pb(last[i]), du[last[i]]++;
	que.push(0);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		ans = max(ans, val[now]);
		for (auto x: g[now]) {
			du[x]--;
			val[x] = max(val[x], val[now] + 1);
			if (du[x] == 0) que.push(x);
		}
	}
	cout << ans << endl;
	return 0;
}