// Problem: Hey Gamers
// URL: https://codeforces.com/gym/339463/problem/A
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

const int N = 210000;
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n, m;
char s[510][510];
vector<PII> g[60];

void solve() {
    scanf("%d%d", &n, &m);
    repn(i, 1, 52) g[i].clear();
    repn(i, 1, n) {
        scanf("%s", s[i] + 1);
    }
    repn(i, 1, n) {
        repn(j, 1, m) {
            if (s[i][j] == '|' || s[i][j] == '-') continue;
            int t = s[i][j];
            if (t > 96) t = t - 96 + 26;
            else if (t > 64) t = t - 64;
            g[t].pb(mp(i, j));
        }
    }
    bool can = true;
    int a, b, c, d;
    int cnt = 0;
    repn(i, 1, 52) {
        if (g[i].size() == 0) continue;
        if (g[i].size() != 2) {
            can = false;
            break;
        }
        a = g[i][0].fi; b = g[i][0].se;
        c = g[i][1].fi; d = g[i][1].se;
        if (a == c) {
            int l = min(b, d), r = max(b, d);
            repn(j, l + 1, r - 1) {
                if (s[a][j] != '|' && s[a][j] != '-') can = false;
                if (s[a][j] == '|') cnt ++;
                s[a][j] = '1';
            }
        }
        else if (b == d) {
            int l = min(a, c), r = max(a, c);
            repn(j, l + 1, r - 1) {
                if (s[j][b] != '-' && s[j][b] != '|') can = false;
                if (s[j][b] == '-') cnt ++;
                s[j][b] = '1';
            }
        }
        else can = false;
        if (!can) break;
    }
    if (can) printf("%d\n", cnt);
    else printf("F\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}