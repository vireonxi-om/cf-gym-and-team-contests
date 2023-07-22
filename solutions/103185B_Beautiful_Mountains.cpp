// Problem: Beautiful Mountains
// URL: https://codeforces.com/gym/103185/problem/B
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
const int maxn = 100010;

int n, a[N];
vector<int> dv[maxn];
int valid[N];

void mark(int x, int y) {
    for(auto i : dv[x]) {
        if (i >= y) valid[i] = 1;
    }
}

void check(bool invert) {
    int d = -1, p = -1, st = 0, lst;
    repn(i, 1, n) {
        int pv = d == -1 ? a[i] : a[d];
        if (a[i] == -1 || a[i] == pv) {
            if (st == 0) st = 1;
            else if (st == 1 || st == 2) st = 2;
            else if (st == 3) st = 3;
            else st = 4;
        }
        else if (a[i] > pv) {
            if (st <= 2) st = 1;
            else st = 4;
        }
        else {
            if (st <= 3) st = 3;
        }
        if (st != 2 && st != 3) {
            if (invert) {
                mark(n - i, i);
            }
            else mark(i, i);
        }
        if (a[i] != -1 && a[i - 1] != -1 && !invert) {
            if (a[i] > a[i - 1]) mark(i, 0);
            if (a[i] < a[i - 1]) mark(i - 2, 0);
        }
        if (a[i] != -1) {
            if (d != -1 && a[d] > a[i]) p = d;
            else if (d != -1 && a[d] < a[i] && p != -1) {
                if (!invert) mark(i, i - p);
                else mark(n - i, i - p);
            }
            d = i;
        }
    }
}

int main() {
    rep(i, 1, maxn) {
        for (int j = 0; j < maxn; j += i) dv[j].pb(i);
    }
    scanf("%d", &n);
    repn(i, 1, n) scanf("%d", &a[i]);
    check(false);
    int l = 1, r = n;
    while(l < r) swap(a[l ++], a[r --]);
    check(true);
    bool yes = false;
    repn(i, 3, n) if (valid[i] == 0) yes = true;
    if (yes) printf("Y\n");
    else printf("N\n");
    return 0;
}

