// Problem: Almost Balanced Tree
// URL: https://codeforces.com/gym/102896/problem/A
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
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;
const int maxn = 100010;

int A, B, pos = 1, w[N], ch[N][2];
bool yes = true;


void dfs(int x, int a, int b) {
    if (yes == false) return;
    if (a == 0 && b == 0) {
        w[x] = 0; return;
    }
    if (b > 0){ w[x] = 2; b --;}
    else {w[x] = 1; a --;}
    if (a == 0 && b == 0) return;
    bool can = true;
    int la, lb, ra, rb;
    if (b > 0) {
        if (b % 2) {
            lb = b / 2 + 1; rb = b / 2;
            if (a == 0) can = false;
            else {
                if (a % 2) {
                    la = a / 2;
                    ra = a / 2 + 1;
                }
                else {
                    la = a / 2 - 1;
                    ra = a / 2 + 1;
                }
            }
        }
        else {
            lb = b / 2; rb = b / 2;
            la = a / 2; ra = a - la;
        }
    }
    else {
        lb = b / 2; rb = b / 2;
        la = a / 2; ra = a - la;
    }
    if (!can) {
        yes = false;
        return;
    }
    if (la || lb) {
        pos ++;
        ch[x][0] = pos;
        dfs(ch[x][0], la, lb);

    }
    if (ra || rb) {
        pos ++;
        ch[x][1] = pos;
        dfs(ch[x][1], ra, rb);

    }

}

int main(){
    scanf("%d%d", &A, &B);
    dfs(1, A, B);
    if (yes) {
        repn(i, 1, pos) {
            printf("%d %d %d\n", w[i], ch[i][0], ch[i][1]);
        }
    }
    else printf("-1\n");
    return 0;
}



