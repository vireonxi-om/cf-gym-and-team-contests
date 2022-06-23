// Problem: Crosswords
// URL: https://codeforces.com/gym/102465/problem/C
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

const int N = 510;
const int M = 500000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;
const int maxn = 100010;

int n, m;
int A, B;
int t1[M][26], t2[M][26], val1[M], val2[M];
string s;
vector<int> p1[M], p2[M];
int ans;

void dfs(int x, int y, int v[5], int h[5]) {
    //printf("%d %d: ", x, y);
    //repn(i, 1, m) printf("%d ", v[i]); printf("; ");
    //repn(i, 1, n) printf("%d ", h[i]); printf("\n");
    if (x > n) {ans ++; return;}
    int nx = x, ny = y + 1;
    if (y == m) {nx = x + 1; ny = 1;}
    int nv[5], nh[5];
    repn(i, 1, m) nv[i] = v[i];
    repn(i, 1, n) nh[i] = h[i];
    int vid = v[y], hid = h[x];
    int cur1 = 0, cur2 = 0;
    int tot1 = p1[vid].size(), tot2 = p2[hid].size();
    while (cur1 < tot1 && cur2 < tot2) {
        //printf("%d %d\n", cur1, cur2);
        if (p1[vid][cur1] == p2[hid][cur2]) {
            int ch = p1[vid][cur1];
            nv[y] = t1[vid][ch]; nh[x] = t2[hid][ch];
            //printf("%d\n", ch);
            dfs(nx, ny, nv, nh);
            cur1 ++; cur2 ++;
        }
        while (cur1 < tot1 && cur2 < tot2 && p1[vid][cur1] != p2[hid][cur2]) {
            while (cur1 < tot1 && p1[vid][cur1] < p2[hid][cur2]) cur1 ++;
            if (cur1 >= tot1) break;
            while (cur2 < tot2 && p1[vid][cur1] > p2[hid][cur2]) cur2 ++;
            if (cur2 >= tot2) break;
        }
    }

}

int main() {
    scanf("%d%d%d%d", &n, &A, &m, &B);
    int pos1 = 1;
    repn(i, 1, A) {
        cin >> s;
        int now = 1;
        rep(j, 0, n) {
            if (t1[now][s[j]-'a']) now = t1[now][s[j]-'a'];
            else { t1[now][s[j]-'a'] = ++ pos1; now = pos1;}
        }
        val1[now] ++;
    }
    int pos2 = 1;
    repn(i, 1, B) {
        cin >> s;
        int now = 1;
        rep(j, 0, m) {
            if (t2[now][s[j]-'a']) now = t2[now][s[j]-'a'];
            else {t2[now][s[j]-'a'] = ++ pos2; now = pos2; }
        }
        val2[now] ++;
    }
    repn(i, 1, pos1) {
        rep(j, 0, 26) if (t1[i][j]) p1[i].pb(j);
    }
    repn(i, 1, pos2) {
        rep(j, 0, 26) if (t2[i][j]) p2[i].pb(j);
    }
    //printf("%d %d\n", pos1, pos2);
    //repn(i, 1, pos1){ for (auto x: p1[i]) printf("%d ", x); printf("\n");}
    //repn(i, 1, pos2){ for (auto x: p2[i]) printf("%d ", x); printf("\n");}
    int nv[5], nh[5];
    repn(i, 1, m) nv[i] = 1;
    repn(i, 1, n) nh[i] = 1;
    dfs(1, 1, nv, nh);
    printf("%d\n", ans);
    return 0;
}



