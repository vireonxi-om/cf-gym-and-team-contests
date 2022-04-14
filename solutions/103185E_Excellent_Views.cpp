// Problem: Excellent Views
// URL: https://codeforces.com/gym/103185/problem/E
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

int n, ans[N];
PII a[N];
set<int> b;
int sum[M], lz[M];

void update(int k) {
    sum[k] = sum[LC] + sum[RC];
}
void pushdown(int k, int l, int r) {
    if (lz[k]) {
        int mid = (l + r) / 2;
        sum[LC] = sum[LC] + (LL)(mid - l + 1) * lz[k];
        lz[LC] = lz[LC] + lz[k];
        sum[RC] = sum[RC] + (LL)(r - mid) * lz[k];
        lz[RC]= lz[RC] + lz[k];
        lz[k] = 0;
    }
}
void change(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        sum[k] = sum[k] + (LL)(r - l + 1) * c;
        lz[k] = lz[k] + c;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    if (b <= mid) change(LC, l, mid, a, b, c);
    else if (a > mid) change(RC, mid + 1, r, a, b, c);
    else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
    update(k);
}
LL ask(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return sum[k];
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    LL res = 0;
    if (b <= mid) res = ask(LC, l, mid, a, b);
    else if (a > mid) res = ask(RC, mid + 1, r, a, b);
    else res = ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b);
    update(k);
    return res;
}

int main() {
    scanf("%d", &n);
    repn(i, 1, n) {
        scanf("%d", &a[i].fi);
        a[i].fi = - a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    int id, l, r;
    repn(i, 1, n) {
        l = 1; r = n;
        id = a[i].se;
        auto it = b.upper_bound(id);
        if (it != b.end()) r = ((*it) + id - 1) / 2;
        if (it != b.begin()) {
            it --;
            l = ((*it) + id + 2) / 2;
        }
        b.insert(id);
        ans[id] = ask(1, 1, n, id, id);
        change(1, 1, n, l, r, 1);
    }
    repn(i, 1, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}

