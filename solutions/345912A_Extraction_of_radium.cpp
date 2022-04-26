// Problem: Extraction of radium
// URL: https://codeforces.com/gym/345912/problem/A
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
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, m, q, num;
vector<int> a[N];
vector<PII> row, col;

int main(){
    scanf("%d%d%d", &n, &m, &q);
    rep(i, 0, n) {
        int maxi = 0, id = -1;
        rep(j, 0, m) {
            scanf("%d", &num);
            a[i].pb(num);
            if (num > maxi) { maxi = num; id = j;}
        }
        row.pb(mp(maxi, id));
    }
    rep(j, 0, m) {
        int maxi = 0, id = -1;
        rep(i, 0, n) {
            if (a[i][j] > maxi) { maxi = a[i][j]; id = i;}
        }
        col.pb(mp(maxi, id));
    }
    int tot = 0;
    rep(i, 0, n) {
        int id = row[i].se;
        if (col[id].se == i) tot ++;
    }
    int x, y, now;
    repn(i, 1, q) {
        scanf("%d%d%d", &x, &y, &now);
        x --; y --;
        if (row[x].se == y && col[y].se == x) {
            row[x].fi = now; col[y].fi = now;
        }
        else {
            int id = row[x].se;
            if (now > row[x].fi) {
                if (id != y && col[id].se == x) tot --;
                row[x].fi = now; row[x].se = y;
            }
            id = col[y].se;
            if (now > col[y].fi) {
                if (id != x && row[id].se == y) tot --;
                col[y].fi = now; col[y].se = x;
            }
            if (row[x].se == y && col[y].se == x) {
                tot ++;
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}


