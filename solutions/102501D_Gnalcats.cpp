// Problem: Gnalcats
// URL: https://codeforces.com/gym/102501/problem/D
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
const int M = 210000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
char s[2][N];
int nxt[2][M], len[2], val[2][M];
PII ch[M];
map<PII, int> m;

int main(){
    scanf("%s%s", s[0] + 1, s[1] + 1);
    rep(i, 0, N){
        repn(t, 0, 1){
            nxt[t][i] = i + 1;
            val[t][i + 1] = i + 1;
        }
    }
    nxt[0][N] = -1; nxt[1][N] = -1;
    int pos = N, vp = N;
    len[0] = strlen(s[0] + 1); len[1] = strlen(s[1] + 1);
    int f1 = -1, f2 = -1;
    int i1, i2, i3, vi1, vi2, vi3;
    repn(t, 0, 1) {
        pos = N;
        int num = -1;
        repn(i, 1, len[t]) {
            i1 = nxt[t][0]; i2 = nxt[t][i1]; i3 = nxt[t][i2];
            vi1 = val[t][i1]; vi2 = val[t][i2]; vi3 = val[t][i3];
            if (s[t][i] == 'C') {
                ++ pos;
                val[t][pos] = vi1;
                nxt[t][0] = pos; nxt[t][pos] = i1;
            }
            if (s[t][i] == 'D') {
                nxt[t][0] = i2;
            }
            if (s[t][i] == 'L') {
                if (!ch[vi1].fi) {num = i;  break;}
                ++ pos;
                val[t][pos] = ch[vi1].fi;
                nxt[t][0] = pos; nxt[t][pos] = i2;
            }
            if (s[t][i] == 'P') {
                if (!m.count(mp(vi1, vi2))) {
                    m[mp(vi1, vi2)] = ++ vp;
                    ch[vp].fi = vi1; ch[vp].se = vi2;
                }
                ++pos;
                val[t][pos] = m[mp(vi1, vi2)];
                nxt[t][0] = pos; nxt[t][pos] = i3;
            }
            if (s[t][i] == 'R') {
                if (!ch[vi1].se) {num = i;  break;}
                ++ pos;
                val[t][pos] = ch[vi1].se;
                nxt[t][0] = pos; nxt[t][pos] = i2;
            }
            if (s[t][i] == 'S') {
                nxt[t][0] = i2; nxt[t][i2] = i1; nxt[t][i1] = i3;
            }
            if (s[t][i] == 'U') {
                if (!ch[vi1].se) {num = i;  break;}
                ++ pos;
                val[t][pos] = ch[vi1].fi;
                nxt[t][0] = pos; nxt[t][pos] = pos + 1;
                ++ pos;
                val[t][pos] = ch[vi1].se;
                nxt[t][pos] = i2;
            }
        }
        if (num != -1) {
            if (t == 0) f1 = num;
            else f2 = num;
        }
    }
    bool can = true;
    if (f1 != -1 && f2 != -1) {
        printf("True\n");
        return 0;
    }
    else if (f1 != -1 || f2 != -1) {
        printf("False\n");
        return 0;
    }
    if (can) {
        int p1 = 0, p2 = 0;
        while(p1 != -1) {
            if (p2 == -1) can = false;
            //printf("%d %d\n", val[0][p1], val[1][p2]);
            if (val[1][p2] != val[0][p1]) {
                // printf("1\n");
                can = false; break;
            }
            p2 = nxt[1][p2]; p1 = nxt[0][p1];
            if (p1 == -1 && p2 != -1) can = false;
            //printf("%d %d\n", p1, p2);
            // printf("2\n");}
        }
    }
    if (can) printf("True\n");
    else printf("False\n");
    return 0;
}

