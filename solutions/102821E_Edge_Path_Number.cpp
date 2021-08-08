// Problem: Edge, Path, Number
// URL: https://codeforces.com/gym/102821/problem/E
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

const int N = 110;
const int M = 11000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int T, cas, n, m, k, p, x;
vector<pair<int, int> > g[N], rg[N];
int dp[2][N][5][M];
int pw[5] = {1, 10, 100, 1000, 10000};

const int maxsz = 2e7 + 3;
template<typename key,typename val>
class hash_map{public:
  struct node{key u;val v;int next;};
  vector<node> e;
  int head[maxsz],nume,numk,id[maxsz];
  bool count(key u){
    int hs=(u%maxsz + maxsz) % maxsz;
    for(int i=head[hs];i;i=e[i].next)
      if(e[i].u==u) return 1;
    return 0;
  }
  val& operator[](key u){
    int hs=(u%maxsz + maxsz) % maxsz;
    for(int i=head[hs];i;i=e[i].next)
      if(e[i].u==u) return e[i].v;
    if(!head[hs])id[++numk]=hs;
    if(++nume>=e.size())e.resize(nume<<1);
    return e[nume]=(node){u,0,head[hs]},head[hs]=nume,e[nume].v;
  }
  void clear(){
    repn(i,0,numk)head[id[i]]=0;
    numk=nume=0;
    e.clear();
  }
};
hash_map<int, int> rec;

void work(int op, int len) {
	repn(i, 1, n) dp[op][i][0][0] = 1;
	repn(i, 1, len) {
		repn(j, 1, n) rep(k, 0, pw[i]) dp[op][j][i][k] = 0;
		repn(j, 1, n) {
			rep(k, 0, pw[i - 1]) {
				int x = j;
				if (op == 0) {
					for (auto p: g[j]) {
						int y = p.fi, w = p.se;
						int nw;
						nw = k * 10 + w;
						dp[op][y][i][nw] += dp[op][x][i - 1][k];
					}
				}
				else {
					for (auto p: rg[j]) {
						int y = p.fi, w = p.se;
						int nw;
						nw = k + w * pw[i - 1];
						dp[op][y][i][nw] += dp[op][x][i - 1][k];
					}
				}
			}
		}
	}
}
int main()
{
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m >> k >> p >> x;
		repn(i, 1, n) g[i].clear(), rg[i].clear();
		repn(i, 1, m) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			rg[v].pb(mp(u, w));
		}
		int k1 = k / 2, k2 = (k + 1) / 2;
		work(0, k1);
		work(1, k2);
		LL ans = 0;
		repn(i, 1, n) {
			rec.clear();
			rep(j, 0, pw[k1]) {
				if (dp[0][i][k1][j]) {
					rec[j * pw[k2] % p] = rec[j * pw[k2] % p] + dp[0][i][k1][j];
				}
			}
			rep(j, 0, pw[k2]) {
				if (dp[1][i][k2][j]) {
					int rem = (x - (j % p) + p) % p;
					ans = (ans + (LL)rec[rem] * dp[1][i][k2][j] % mod) % mod;
				}
			}
		}
		cout << "Case " << ++cas << ": " << ans << "\n";
	}
	return 0;
}