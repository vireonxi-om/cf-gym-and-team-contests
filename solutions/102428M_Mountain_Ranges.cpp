// Problem: Mountain Ranges
// URL: https://codeforces.com/gym/102428/problem/M
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

int n, k;
int a[1100], yes[1100];

int main(){
    scanf("%d%d", &n, &k);
    repn(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) {
        if (a[i + 1] - a[i] <= k) yes[i] = 1;
    }
    int ans = 1, now = 1;
    bool st = false;
    repn(i, 1, n) {
        if (st) {
            if (yes[i]) now ++;
            else {
                st = false;
                ans = max(ans, now);
                now = 1;
            }
        }
        else {
            if (yes[i]) {
                st = true;
                now ++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}



