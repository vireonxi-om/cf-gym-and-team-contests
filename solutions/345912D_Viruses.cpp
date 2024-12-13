// Problem: Viruses
// URL: https://codeforces.com/gym/345912/problem/D
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

int a[510][510], d[510], cur[510], p[510];
vector<int> ans1, ans2;
int n;

int main(){
    scanf("%d", &n);
    repn(i, 1, n) repn(j, 1, n) scanf("%d", &a[i][j]);
    repn(i, 1, n) if (a[i][1] == i) d[i] = 1;
    repn(t, 1, n) {
        repn(i, 1, n) {
            int j = 1;
            while (d[j] != 1 && a[i][j] != i) {
                if (a[i][j] == t) break; j ++;
            }
            if (a[i][j] != t) continue;
            repn(k, 1, n) cur[k] = 0;
            repn(k, 1, j - 1) cur[a[i][k]] = 1;
            bool yes = true;
            repn(k, 1, j - 1) {
                bool yes1 = false;
                int id = a[i][k];
                repn(y, 1, n) {
                    if (!cur[a[id][y]]) {yes1 = true; break;}
                    if (a[id][y] == id) break;
                }
                if (yes1 == false) {
                    yes = false; break;
                }
            }
            if (yes) {
                p[t] = 1; break;
            }
        }
    }
    int q;
    scanf("%d", &q);
    repn(i, 1, n){
        if (d[i] == 1) ans1.pb(i);
        if (p[i] == 1) ans2.pb(i);
    }
    if (q == 1) {
        int tot = ans1.size();
        printf("%d\n", tot);
        for (auto x : ans1) printf("%d ", x); printf("\n");
    }
    else {
        int tot = ans2.size();
        printf("%d\n", tot);
        for (auto x : ans2) printf("%d ", x); printf("\n");
    }
    return 0;
}


