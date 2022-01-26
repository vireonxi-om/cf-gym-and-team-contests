// Problem: Club Assignment
// URL: https://codeforces.com/gym/103119/problem/C
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
const int M = 3100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;


int T, n;
int a[N], way[N];
struct Trie {
	int ch[M][2], pos;
	int num[M], dep[M], tmp[32], val[M];
	
	vector<int> g[32];
	vector<int> id[M];
	void init() {
		pos = 1, ch[1][0] = ch[1][1] = num[1] = 0;
		repn(i, 0, 30) g[i].clear();
		id[1].clear();
	}
	int newnode(int d) {
		pos++;
		ch[pos][0] = ch[pos][1] = num[pos] = 0;
		dep[pos] = d;
		id[pos].clear();
		return pos;
	}
	void insert(int x, int idx) {
		int now = 1, y = x;
		rep(i, 0, 30) {
			tmp[i] = x & 1, x >>= 1;
		}
		reverse(tmp, tmp + 30);
		rep(i, 0, 30) {
			num[now]++;
			if (ch[now][tmp[i]]) now = ch[now][tmp[i]];
			else now = ch[now][tmp[i]] = newnode(dep[now] + 1);
		}
		id[now].pb(idx);
		num[now]++;
		val[now] = y;
	}
	vector<int> tp, cp;
	void dfs(int x) {
		if (ch[x][0] + ch[x][1] == 0) {
			rep(i, 0, num[x]) tp.pb(val[x]), cp.pb(id[x][i]);
			return;
		}
		if (ch[x][0]) dfs(ch[x][0]);
		if (ch[x][1]) dfs(ch[x][1]);
	}
	void work() {
		int ans = 0;
		way[1] = 1;
		repn(i, 2, n) way[i] = 2;
		repn(j, 1, pos) {
			g[dep[j]].pb(j);
		}
		rep(i, 1, 30) {
			int flag = 0;
			for (auto x: g[i]) {
				if (num[ch[x][0]] > 2 || num[ch[x][1]] > 2) {
					flag = 1;
					break;
				}
			}
			if (flag) continue;
			ans = 2e9;
			for (auto x: g[i]) {
				tp.clear();
				cp.clear();
				dfs(x);
				int cnt = 0;
				if (tp.size() == 1) {
					if (cnt == 0) way[cp[0]] = 1, cnt = 1;
					else way[cp[0]] = 2;
				}
				else if (tp.size() == 2) {
					way[cp[0]] = 1, way[cp[1]] = 2;
				}
				else if (tp.size() == 3) {
					int res = max(tp[0] ^ tp[1], tp[0] ^ tp[2]);
					res = max(res, tp[1] ^ tp[2]);
					ans = min(ans, res);
					if (res == (tp[0] ^ tp[1])) way[cp[0]] = way[cp[1]] = 1, way[cp[2]] = 2;
					else if (res == (tp[0] ^ tp[2])) way[cp[0]] = way[cp[2]] = 1, way[cp[1]] = 2;
					else way[cp[1]] = way[cp[2]] = 1, way[cp[0]] = 2;
				}
				else if (tp.size() == 4) {
					int res = 0;
					res = max(res, min(tp[0] ^ tp[1], tp[2] ^ tp[3]));
					res = max(res, min(tp[0] ^ tp[2], tp[1] ^ tp[3]));
					res = max(res, min(tp[0] ^ tp[3], tp[1] ^ tp[2]));
					ans = min(ans, res);
					if (res == min(tp[0] ^ tp[1], tp[2] ^ tp[3])) way[cp[0]] = way[cp[1]] = 1, way[cp[2]] = way[cp[3]] = 2;
					else if (res == min(tp[0] ^ tp[2], tp[1] ^ tp[3])) way[cp[0]] = way[cp[2]] = 1, way[cp[1]] = way[cp[3]] = 2;
					else way[cp[0]] = way[cp[3]] = 1, way[cp[1]] = way[cp[2]] = 2;
				}
			}
			break;
		}
		cout << ans << "\n";
		repn(i, 1, n) cout << way[i];
		cout << "\n";
		return;
	}
}t;
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		t.init();
		repn(i, 1, n) cin >> a[i], t.insert(a[i], i);
		t.work();
	}	
	return 0;
}