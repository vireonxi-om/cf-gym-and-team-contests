// Problem: ’S No Problem
// URL: https://codeforces.com/gym/104633/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n - 1); i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);

#define rand Rand

int n, ans, sum;
vector<PII> g[N];
PII mx[N][4], dp[N][2];
int best[N];
void dfs(int x, int fa) {
    mx[x][0] = mp(0, x);
    dp[x][0] = mp(0, x);
    for (auto p: g[x]) {
        int y = p.fi, w = p.se;
        if (y == fa) continue;
        dfs(y, x);
        PII cur = mp(mx[y][0].fi + w, y);
        if (cur > mx[x][3]) mx[x][3] = cur;
        if (mx[x][3] > mx[x][2]) swap(mx[x][3], mx[x][2]);
        if (mx[x][2] > mx[x][1]) swap(mx[x][2], mx[x][1]);
        if (mx[x][1] > mx[x][0]) swap(mx[x][1], mx[x][0]);
        cur = mp(best[y], y);
        if (cur > dp[x][1]) dp[x][1] = cur;
        if (dp[x][1] > dp[x][0]) swap(dp[x][1], dp[x][0]);
    }
    best[x] = max(best[x], mx[x][0].fi + mx[x][1].fi);

}
void dfs2(int x, int fa, int mlen, int clen) {
    ans = max(ans, clen + best[x]);
    vector<int> arr;
    arr.pb(mx[x][0].fi), arr.pb(mx[x][1].fi), arr.pb(mx[x][2].fi), arr.pb(mx[x][3].fi);
    arr.pb(mlen);
    sort(all(arr));
    ans = max(ans, arr[1] + arr[2] + arr[3] + arr[4]);
    for (auto p: g[x]) {
        int y = p.fi, w = p.se;
        if (y == fa) continue;
        int nmlen, nclen;
        if (y == mx[x][0].se) {
            nmlen = max(mx[x][1].fi, mlen) + w;
            nclen = max({clen, mx[x][1].fi + mx[x][2].fi, mx[x][1].fi + mlen});
        }
        else {
            nmlen = max(mx[x][0].fi, mlen) + w;
            if (y == mx[x][1].se) nclen = max({clen, mx[x][0].fi + mx[x][2].fi, mx[x][0].fi + mlen});
            else nclen = max({clen, mx[x][0].fi + mx[x][1].fi, mx[x][0].fi + mlen});
        }
        if (y == dp[x][0].se) nclen = max(nclen, dp[x][1].fi);
        else nclen = max(nclen, dp[x][0].fi);
        dfs2(y, x, nmlen, nclen);
    }
}
int main() {
    IO;
    cin >> n;
    rep(i, 1, n) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb(mp(y, w));
        g[y].pb(mp(x, w));
        sum += w + w;
    }
    dfs(1, 0);
    dfs2(1, 0, 0, 0);
    cout << sum - ans << "\n";
    return 0;
}
