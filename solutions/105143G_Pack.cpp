// Problem: Pack
// URL: https://codeforces.com/gym/105143/problem/G
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
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int T;
LL n, m, a, b, k;
LL exgcd(LL a, LL b, LL &x, LL &y) {
    // ax + by = gcd(a, b)
    // time: O(log max(a, b))
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        LL r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
set<int> S;
int main() {
    IO;
    cin >> T;
    while (T--) {
        cin >> n >> m >> a >> b >> k;
        LL d = gcd(a, b);
        if (k % d) {
            cout << n + m << "\n";
            continue;
        }
        LL x0, y0, A, B;
        exgcd(a, b, x0, y0);
        x0 *= k / d, y0 *= k / d;
        A = b / d, B = a / d;
        LL ans = n + m;
        S.clear();
        LL l = 1, r = n;
        while (l <= n) {
            S.insert(n / l);
            r = n / (n / l);
            l = r + 1;
        }
        l = 1, r = m;
        while (l <= m) {
            S.insert(m / l);
            r = m / (m / l);
            l = r + 1;
        }
        for (auto p: S) {
            LL l = -inf, r = inf;
            while (l < r) {
                LL len = r - l;
                LL m1 = l + len / 3, m2 = r - len / 3;
                LL x1 = x0 + m1 * A, y1 = y0 - m1 * B;
                LL x2 = x0 + m2 * A, y2 = y0 - m2 * B;
                if (x1 < 0) l = m1 + 1;
                else if (y2 < 0) r = m2 - 1;
                else if (x2 * p > n) r = m2 - 1;
                else if (y1 * p > m) l = m1 + 1;
                else {
                    LL res1 = n + m - (x1 + y1) * p;
                    LL res2 = n + m - (x2 + y2) * p;
                    ans = min(ans, res1), ans = min(ans, res2);
                    if (res1 < res2) r = m2 - 1;
                    else l = m1 + 1;
                }
            }
            LL x = x0 + l * A, y = y0 - l * B;
            if (x >= 0 && y >= 0 && x * p <= n && y * p <= m) ans = min(ans, n + m - (x + y) * p);
        }
        cout << ans << "\n";
    }
    return 0;
}