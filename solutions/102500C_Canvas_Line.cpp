// Problem: Canvas Line
// URL: https://codeforces.com/gym/102500/problem/C
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 2100;
const int M = 510000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-12;
const double eps2 = 1e-12;

int n, p, num;
PII b[N];
int pos[N], cnt[N];
int yes[N], d[N];
vector<int> ans;
map<int, int> m;

int main() {
    scanf("%d", &n);
    repn(i, 1, n) scanf("%d%d", &b[i].fi, &b[i].se);
    sort(b + 1, b + n + 1);
    int tot = 0; pos[0] = -1;
    repn(i, 1, n) {
        if (pos[tot] != b[i].fi) tot ++;
        pos[tot] = b[i].fi;
        pos[++ tot] = b[i].se; d[tot] = 1;
    }
    scanf("%d", &p);
    repn(i, 1, p) {
        scanf("%d", &num);
        m[num] = 1;
        repn(j, 1, tot) {
            if (pos[j] > num) break;
            if (pos[j] == num) yes[j] = 1;
            else if (j < tot && pos[j + 1] > num) cnt[j + 1] ++;
        }
    }
    bool can = true;
    repn(i, 2, tot) {
        if (d[i]) {
            int t = yes[i] + yes[i - 1] + cnt[i];
            int t2;
            if (i < tot && d[i + 1]) t2 = yes[i + 1] + yes[i] + cnt[i + 1];
            else t2 = 0;
            if (t > 2) {can = false; break;}
            if (t == 2) continue;
            if (! yes[i] && t2 < 2) {
                yes[i] = 1; ans.pb(pos[i]); t ++;
            }
            rep(k, pos[i - 1] + 1, pos[i]) {
                if (t >= 2) break;
                if (!m.count(k)) {
                    ans.pb(k); m[k] = 1; t ++;
                }
            }
        }
    }
    if (can ) {
        int as = ans.size();
        printf("%d\n", as);
        for (auto x: ans) printf("%d ", x);
        printf("\n");
    }
    else printf("impossible\n");
    return 0;
}