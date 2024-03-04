// Problem: Dazzling stars
// URL: https://codeforces.com/gym/102428/problem/D
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
const LL INF = 1e17;
const int maxn = 100010;

int n, x[1100], y[1100], b[1100];
double num[1100000][4];
int id[1100000][4];
vector<pair<double, PII>> p;
int tot[5000000];


int main(){
    scanf("%d", &n);
    repn(i, 1, n) {
        scanf("%d%d%d", &x[i], &y[i], &b[i]);
    }
    double pi = acos(-1);
    bool can = false, flag;
    int cnt = 0;
    double eps = 1e-7;
    repn(i, 1, n) {
        double arg;
        repn(j, 1, n) {
            if (b[i] <= b[j]) continue;
            cnt ++;
            arg = atan2(y[j] - y[i], x[j] - x[i]);
            flag = false;
            if (abs(arg) < 1e-8) {
                num[cnt][0] = 0; num[cnt][1] = pi;
                num[cnt][2] = 2 * pi; num[cnt][3] = 2 * pi;
            }
            else if (abs(arg - 2 * pi) < 1e-8 || abs(arg + 2 * pi) < 1e-8) {
                num[cnt][0] = 0; num[cnt][1] = 0;
                num[cnt][2] = pi; num[cnt][3] = 2 * pi;
            }
            else if (arg > 0) {
                num[cnt][0] = arg; num[cnt][1] = arg + pi;
                flag = true;
            }
            else {
                num[cnt][0] = 0; num[cnt][1] = pi + arg;
                num[cnt][2] = 2 * pi + arg; num[cnt][3] = 2 * pi;
            }
            num[cnt][0] -= eps; num[cnt][1] += eps; num[cnt][2] -= eps; num[cnt][3] += eps;
            repn(t, 0, 3) {
                if (flag && t == 2) break;
                p.pb(mp(num[cnt][t], mp(cnt, t)));
            }
        }
    }
    sort(all(p));
    int cnt1 = 0; double last = -1;
    for (auto t: p){
        //if (abs(last - t.fi) < 1e-8) id[t.se.fi][t.se.se] = cnt1;
        id[t.se.fi][t.se.se] = ++ cnt1;
        //last = t.fi;
    }
    repn(i, 1, cnt) {
        tot[id[i][0]] ++; tot[id[i][1]] --;
        if (id[i][2]){
            tot[id[i][2]] ++; tot[id[i][3]] --;
        }
    }
    //repn(i, 1, cnt) {
    //    printf("%.4f %.4f %.4f %.4f\n", num[i][0], num[i][1], num[i][2], num[i][3]);
    //    printf("%d %d %d %d\n", id[i][0], id[i][1], id[i][2], id[i][3]);
    //}
    int now = 0;
    repn(i, 1, cnt1) {
        //printf("%d ", tot[i]);
        now += tot[i];
        if (now == cnt) can = true;
    }
    if (cnt == 0) can = true;
    //printf("\n");
    if (can) printf("Y\n");
    else printf("N\n");
    return 0;
}



