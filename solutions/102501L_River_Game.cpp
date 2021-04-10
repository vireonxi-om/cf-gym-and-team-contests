// Problem: River Game
// URL: https://codeforces.com/gym/102501/problem/L
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

const int N = 51;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, a[N][N], pp[N][N], cp[N][N], id[N][N], ban[N];
string s;
queue<PII> que;
const int wayx[4] = {0, 0, 1, -1};
const int wayy[4] = {1, -1, 0, 0};
int px[N], py[N], num, cnum, ppx[N], ppy[N];

const int maxsz = 2e7 + 3;
template<typename key, typename val>
class hash_map{public:
	struct node{key u; val v; int next;};
	vector<node> e;
	int head[maxsz], nume, numk, id[maxsz];
	bool count(key u) {
		int hs = (u % maxsz + maxsz) % maxsz;
		for (int i = head[hs]; i; i=e[i].next) 
			if (e[i].u == u) return 1;
		return 0;
	}
	val & operator [] (key u) {
		int hs = (u % maxsz + maxsz) % maxsz;
		for (int i = head[hs]; i; i = e[i].next)
			if (e[i].u == u) return e[i].v;
		if (!head[hs]) id[++numk]=hs;
		if (++nume >= e.size()) e.resize(nume << 1);
		return e[nume] = (node){u, 0, head[hs]}, head[hs] = nume, e[nume].v;
	}
	void clear() {
		repn(i, 0, numk) head[id[i]] = 0;
		numk = nume = 0;
		e.clear();
	}
};
hash_map<int, int> rec;
int dfs(int x) {
	if (rec.count(x)) return rec[x];
	int tmp[20];
	memset(tmp, 0, sizeof(tmp));
	rep(i, 0, num) if ((x & ban[i]) == 0) {
		tmp[dfs(x | (1 << i))] = 1;
	}
	rep(i, 0, 20) if (!tmp[i]) {
		return rec[x] = i;
	}
}
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> s;
		repn(j, 1, n) {
			if (s[j - 1] == '.') a[i][j] = 0;
			else if (s[j - 1] == '*') a[i][j] = 1;
			else a[i][j] = 2;
		}
	}
	int ans = 0;
	repn(i, 1, n) repn(j, 1, n) if (!pp[i][j] && a[i][j] == 1) {
		que.push(mp(i, j));
		pp[i][j] = 1;
		cnum = 0;
		memset(id, -1, sizeof(id));
		while (!que.empty()) {
			auto p = que.front();
			que.pop();
			int x = p.fi, y = p.se;
			rep(i, 0, 4) {
				int nx = wayx[i] + x;
				int ny = wayy[i] + y;
				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
				if (a[nx][ny] == 0 && !cp[nx][ny]) cp[nx][ny] = 1;
				if (a[nx][ny] == 1 && !pp[nx][ny]) {
					pp[nx][ny] = 1;
					que.push(mp(nx, ny));
				}
			}
		}
		repn(i, 1, n) repn(j, 1, n) if (cp[i][j]) {
			cp[i][j] = 0;
			num = 1;
			memset(id, -1, sizeof(id));
			id[i][j] = 0;
			que.push(mp(i, j));
			ppx[0] = i, ppy[0] = j;
			while (!que.empty()) {
				auto p = que.front();
				que.pop();
				int x = p.fi, y = p.se;
				rep(i, 0, 4) {
					int nx = wayx[i] + x;
					int ny = wayy[i] + y;
					if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
					if (cp[nx][ny]) {
						ppx[num] = nx, ppy[num] = ny;
						id[nx][ny] = num;
						num++;
						cp[nx][ny] = 0;
						que.push(mp(nx, ny));
					}
				}
			}
			rep(i, 0, num) {
				ban[i] = 1 << i;
				rep(j, 0, 4) {
					int nx = ppx[i] + wayx[j];
					int ny = ppy[i] + wayy[j];
					if (id[nx][ny] != -1) ban[i] |= 1 << id[nx][ny];
				}
			}
			rec.clear();
			ans ^= dfs(0);
		}
	}
	if (ans) cout << "First player will win\n";
	else cout << "Second player will win\n";
	return 0;
}