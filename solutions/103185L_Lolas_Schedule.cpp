// Problem: Lola's Schedule
// URL: https://codeforces.com/gym/103185/problem/L
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;

int n, x, s, t;
PII a[N];

int main() {
    scanf("%d%d", &n, &x);
    repn(i, 1, n) {
        scanf("%d%d", &s, &t);
        a[i].fi = s; a[i].se = s + t;
    }
    sort(a + 1, a + n + 1);
    int st, num1, num2, m = 1e9, ans;
    repn(i, 0, 480) {
        st = i;
        int cnt = 0;
        repn(j, 1, n) {
            if (a[j].se < st) continue;
            num1 = max((a[j].fi - st + x - 1) / x, 0);
            num2 = (a[j].se - st) / x;
            if (num1 > num2) continue;
            cnt += num2 - num1 + 1;
        }
        if (cnt < m) {
            m = cnt; ans = i;
        }
    }
    printf("%d %d\n", ans, m);
    return 0;
}

