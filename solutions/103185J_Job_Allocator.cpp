// Problem: Job Allocator
// URL: https://codeforces.com/gym/103185/problem/J
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
const LL INF = 1e15;
const int MAXN = 1001000;

int n, k, a[9][9][9][9][9][9][9][9], cnt[9];
char s[5];
vector<int> b[N];

int main() {
    scanf("%d%d", &n, &k);
    int num, t, tot = 1;
    repn(i, 1, n) {
        repn(j, 0, 8) cnt[j] = 0;
        scanf("%s", s + 1);
        scanf("%d", &num);
        if (s[1] == 'D') {
            repn(t, 1, 8) {
                cnt[t] = b[num][t];
            }
        }
        else {
            repn(j, 1, num) {
                scanf("%d", &t);
                cnt[t] ++;
            }
            if (s[1] == 'C') {
                repn(j, 0, 8) b[tot].pb(cnt[j]);
                tot ++;
            }
        }
        if (s[1] == 'J') {
            printf("%d\n", a[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]][cnt[7]][cnt[8]]);
        }
        else {
            int d = 1;
            if (s[1] == 'D') d = -1;
                repn(t1, 0, cnt[1]) {
                repn(t2, 0, cnt[2]) {
                    repn(t3, 0, cnt[3]) {
                        repn(t4, 0, cnt[4]) {
                            repn(t5, 0, cnt[5]) {
                                repn(t6, 0, cnt[6]) {
                                    repn(t7, 0, cnt[7]) {
                                        repn(t8, 0, cnt[8]) {
                                            a[t1][t2][t3][t4][t5][t6][t7][t8] += d;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

