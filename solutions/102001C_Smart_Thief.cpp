// Problem: Smart Thief
// URL: https://codeforces.com/gym/102001/problem/C
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
const int M = 2100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, k;
int a[11], len, num;
int last[N], pre[M], e[M], w[M];
stack<int> st;
void dfs(int x, int idx)
{
	while (last[x])
	{
		int i=last[x];
		last[x]=pre[last[x]];
		dfs(e[i], i);
	}
	st.push(idx);
}
void add(int x, int y, int z) {
	e[++num] = y, pre[num] = last[x], w[num] = z, last[x] = num;
}
int tmp[N];
int ans[N], nn;
int main()
{
	IO;
	cin >> n >> m >> k;
	if (k == 0) {
		repn(i, 1, n) cout << a[1];
		cout << "\n";
		return 0;
	}
	repn(i, 1, m) cin >> a[i];
	int base = 1;
	while (base < k) base *= m, len++;
	base /= m;
	len--;
	rep(i, 0, base) {
		int x = i;
		repn(j, 1, len) {
			tmp[j] = x % m;
			x /= m;
		}
		int cur = 0;
		pern(j, 1, len - 1) {
			cur = cur * m + tmp[j];
		}
		rep(j, 0, m) {
			if (i || j) add(i, cur * m + j, j + 1);
		}
	}
	dfs(0, 0);
	while (!st.empty()) {
		ans[nn++] = st.top();
		st.pop();
	}
	repn(i, 1, n) cout << a[1];
	repn(i, 1, k - 1) {
		cout << a[w[ans[i]]];
	}
	cout << "\n";
	return 0;
}