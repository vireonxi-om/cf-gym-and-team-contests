// Problem: Rounding
// URL: https://codeforces.com/gym/102465/problem/E
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

const int N = 11000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;
const int maxn = 100010;

int n;
int a[N];
int l[N], r[N];
string s[N];
pair<double, double> ans[N];


int main(){
    scanf("%d", &n);
    int sum = 0;
    repn(i, 1, n) {
        cin >> s[i];
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int d = 100 - sum;
    d *= 100;
    int sl = 0, sr = 0;
    repn(i, 1, n) {
        if (a[i] == 0) {
            l[i] = 0; r[i] = 49;
        }
        else if (a[i] == 100) {
            l[i] = 50; r[i] = 0;
        }
        else {
            l[i] = 50; r[i] = 49;
        }
        sl += l[i];
        sr += r[i];
    }
    bool can = true;
    repn(i, 1, n) {
        int li = -50, ri = 49;
        if (a[i] == 0) li = 0;
        if (a[i] == 100) ri = 0;
        int L = d - (sr - r[i]), R = d + (sl - l[i]);
        li = max (li, L); ri = min(ri, R);
        if (li > ri) can = false;
        ans[i].fi = a[i] + (double)li / 100;
        ans[i].se = a[i] + (double)ri / 100;
    }
    if (can) {
        repn(i, 1, n) {
            cout << s[i];
            printf(" %.2f %.2f\n", ans[i].fi, ans[i].se);
        }
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}



