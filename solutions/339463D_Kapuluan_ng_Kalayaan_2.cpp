// Problem: Kapuluan ng Kalayaan 2
// URL: https://codeforces.com/gym/339463/problem/D
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
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n, m, k;
vector<pair<int, PII>> f;
int fa[N], sz[N];
int h[N];

int findfa(int i) {
    return fa[i] == i ? i : fa[i] = findfa(fa[i]);
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    int u, v, d;
    repn(i, 1, n) { fa[i] = i; sz[i] = 1;}
    repn(i, 1, m) {
        scanf("%d%d%d", &u, &v, &d);
        f.pb(mp(d, mp(u, v)));
    }
    repn(i, 1, k) scanf("%d", &h[i]);
    sort(h + 1, h + 1 + k);
    sort(all(f));
    int tot = f.size(), now = 0;
    LL num = 1;
    LL ans = (LL) n * n - n; ans %= mod;
    repn(i, 1, k) {
        while (now < tot && f[now].fi <= h[i]) {
            u = f[now].se.fi; v = f[now].se.se;
            int fu = findfa(u), fv = findfa(v);
            if (fu != fv){
                LL sz1 = sz[fu], sz2 = sz[fv];
                LL szt = sz1 + sz2; szt %= mod;
                ans = ans - szt * szt + sz1 * sz1 + sz2 * sz2;
                ans = (ans % mod) + mod;
                ans %= mod;
                fa[fv] = fu;
                sz[fu] = szt;
            }
            now ++;
        }
        num *= ans; num %= mod;
    }
    printf("%lld\n", num);
    return 0;
}