// Problem: Eat More
// URL: https://codeforces.com/gym/103176/problem/E
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

int n, num, lc[M], rc[M];
LL a[N], k, sum[M];

void update(LL k) {
    sum[k] = (sum[lc[k]] + sum[rc[k]]) % mod;
}

int build(int rt, LL pos, LL l, LL r, LL t) {
    if (!rt) {
        rt = ++num;
    }
    if (l == r) {
        sum[rt] += t;
        sum[rt] %= mod;
        return rt;
    }
    LL mid = (l + r) / 2;
    if (pos > mid) rc[rt] = build(rc[rt], pos, mid + 1, r, t);
    else lc[rt] = build(lc[rt], pos, l, mid, t);
    update(rt);
    return rt;
}

LL ask(int k, LL l, LL r, LL a, LL b) {
    if (l == a && r == b || k == 0) return sum[k];
    LL mid = (l + r) / 2;
    LL res = 0;
    if (b <= mid) res = ask(lc[k], l, mid, a, b);
    else if (a > mid) res = ask(rc[k], mid + 1, r, a, b);
    else res = (ask(lc[k], l, mid, a, mid) + ask(rc[k], mid + 1, r, mid + 1, b));
    res %= mod;
    update(k);
    return res;
}

int main(){
    scanf("%d%lld", &n, &k);
    repn(i, 1, n) scanf("%lld", &a[i]);
    repn(i, 1, n){
        a[i] += a[i - 1];
    }
    repn(i, 0, n) a[i] += 1e14 + 1;
    build(0, a[0], 1, 2e14 + 1, 1);
    LL ans;
    repn(i, 1, n) {
        LL l = max((LL)1, a[i] - k), r = min((LL)2e14 + 1, a[i] + k);
        ans = ask(1, 1, 2e14 + 1, l, r);
        build(1, a[i], 1, 2e14 + 1, ans);
    }
    printf("%lld\n", ans);
    return 0;
}
