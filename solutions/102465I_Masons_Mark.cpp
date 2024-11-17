// Problem: Mason's Mark
// URL: https://codeforces.com/gym/102465/problem/I
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

const int N = 11000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;
const int maxn = 100010;

int w, h;
char s[1100][1100];
int a[1100][1100];
queue<PII> q, qq;
vector<PII> nb1, nb2;
vector<PII> p[1000000];

void bfs1() {
    q.push(mp(1, 1));
    a[1][1] = -2;
    PII now, nxt;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        for (auto x: nb1) {
            nxt.fi = now.fi + x.fi; nxt.se = now.se + x.se;
            if (nxt.fi > h || nxt.fi < 1 || nxt.se > w || nxt.se < 1) continue;
            if (a[nxt.fi][nxt.se] != -1) continue;
            a[nxt.fi][nxt.se] = -2;
            q.push(nxt);
        }
    }
}

int main() {
    scanf("%d%d", &w, &h);
    repn(i, 1, h) {
        scanf("%s", s[i] + 1);
        repn(j, 1, w) if (s[i][j] == '#') a[i][j] = -1;
    }
    repn(i, -1, 1) repn(j, -1, 1) nb1.pb(mp(i, j));
    repn(i, -1, 1) if (i) nb2.pb(mp(i, 0));
    repn(j, -1, 1) if (j) nb2.pb(mp(0, j));
    bfs1();
    int pos = 0;
    repn(i, 1, h) {
        repn(j, 1, w) {
            if (a[i][j] == -1) {
                bool can = false;
                for (auto x: nb2) {
                    if (a[i + x.fi][j + x.se] == -1) can = true;
                }
                if (!can) {
                    a[i][j] = 0;    // !!!
                    continue;
                }
                pos ++;
                while (!qq.empty()) qq.pop();
                a[i][j] = pos;
                qq.push(mp(i, j));
                PII now, nxt;
                while(! qq.empty()) {
                    now = qq.front(); qq.pop();
                    p[pos].pb(now);
                    for (auto x: nb2) {
                        nxt.fi = now.fi + x.fi; nxt.se = now.se + x.se;
                        if (nxt.fi > h || nxt.fi < 1 || nxt.se > w || nxt.se < 1) continue;
                        if (a[nxt.fi][nxt.se] != -1) continue;
                        a[nxt.fi][nxt.se] = pos;
                        qq.push(nxt);
                    }
                }
            }
        }
    }
    int cnta = 0, cntb = 0, cntc = 0;
    repn(i, 1, pos) {
        sort(all(p[i]));
        int sti = p[i][0].fi, stj = p[i][0].se;
        int cnt = 0, x1 = 0, y1;
        for(auto x: p[i]) {
            if (x.fi != sti) break;
            cnt ++;
        }
        int mid = stj + cnt / 2, row = sti;
        //printf("%d %d\n", row, mid);
        while (a[row][mid] == i) {
            row ++; x1 ++;
        }
        y1 = cnt - 2 * x1;
        //printf("%d %d\n", x1, y1);
        if (a[sti + 2*x1 + 2 * y1][stj + x1] != i) cnta ++;
        else if (a[sti + x1][stj + x1 + y1] != i) cntc ++;
        else cntb ++;
    }

    printf("%d %d %d\n", cnta, cntb, cntc);
    return 0;
}



