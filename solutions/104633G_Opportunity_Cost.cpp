// Problem: Opportunity Cost
// URL: https://codeforces.com/gym/104633/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n - 1); i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);

#define rand Rand

int n;
LL mx[8], a[N], b[N], c[N];
int main() {
    IO;
    cin >> n;
    repn(i, 1, n) {
        cin >> a[i] >> b[i] >> c[i];
        mx[0] = max(mx[0], a[i] + b[i] + c[i]);
        mx[1] = max(mx[1], a[i] + b[i] + 0);
        mx[2] = max(mx[2], a[i] + 0 + c[i]);
        mx[3] = max(mx[3], a[i] + 0 + 0);
        mx[4] = max(mx[4], 0 + b[i] + c[i]);
        mx[5] = max(mx[5], 0 + b[i] + 0);
        mx[6] = max(mx[6], 0 + 0 + c[i]);
        mx[7] = max(mx[7], 0 + 0 + 0LL);
    }
    LL mn = INF;
    int pos = 0;
    repn(i, 1, n) {
        LL res = -INF;
        res = max(res, mx[0] - a[i] - b[i] - c[i]);
        res = max(res, mx[1] - a[i] - b[i]);
        res = max(res, mx[2] - a[i] - c[i]);
        res = max(res, mx[3] - a[i]);
        res = max(res, mx[4] - b[i] - c[i]);
        res = max(res, mx[5] - b[i]);
        res = max(res, mx[6] - c[i]);
        res = max(res, 0LL);
        if (res < mn) mn = res, pos = i;
    }
    cout << mn << " " << pos << "\n";
    return 0;
}
