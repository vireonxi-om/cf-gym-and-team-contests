// Problem: Keylogger
// URL: https://codeforces.com/gym/103185/problem/K
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;

int n, x, m;
int t[760][760], p[10010];
LL dp[760], lz[3200];

void pushdown(int k, int l, int r) {
    if (lz[k]) {
        lz[LC] = (lz[LC] + lz[k]) % mod;
        lz[RC]= (lz[RC] + lz[k]) % mod;
        lz[k] = 0;
    }
}

void change(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        lz[k] = (lz[k] + c) % mod;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    if (b <= mid) change(LC, l, mid, a, b, c);
    else if (a > mid) change(RC, mid + 1, r, a, b, c);
    else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
}


void cal(int k, int l, int r) {
    if (l == r){ dp[l] = lz[k]; lz[k] = 0; return;}
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    cal(LC, l, mid); cal(RC, mid + 1, r);
}


int main() {
    scanf("%d%d", &n, &x);
    repn(i, 1, n) {
        repn(j, 1, n) scanf("%d", &t[i][j]);
        dp[i] = 1;
    }
    scanf("%d", &m); m--;
    repn(i, 1, m) scanf("%d", &p[i]);
    int l, r;
    repn(i, 1, m) {
        l = p[i] - x; r = p[i] + x;
        repn(j, 1, n) {
            if (!dp[j]) continue;
            auto it1 = lower_bound(t[j] + 1, t[j] + n + 1, l), it2 = upper_bound(t[j] + 1, t[j] + n + 1, r);
            it2 --;
            if (it1 == t[j] + n + 1 || it1 > it2) continue;
            change(1, 1, n, it1 - t[j], it2 - t[j], dp[j]);
        }
        cal(1, 1, n);
    }
    LL ans = 0;
    repn(j, 1, n) ans = (ans + dp[j]) % mod;
    printf("%lld\n", ans);
    return 0;
}

