// Problem: Custom-Made Clothes
// URL: https://codeforces.com/gym/105143/problem/F
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

int n, k, a[N];
int cal(int x) {
    a[0] = n;
    repn(i, 1, n) {
        a[i] = a[i - 1];
        while (a[i]) {
            cout << "? " << i << " " << a[i] << " " << x << endl;
            fflush(stdout);
            int res;
            cin >> res;
            if (res == 1) break;
            else a[i]--;
        }
    }
    int num = 0;
    repn(i, 1, n) num += n - a[i];
    return num;
}
int main() {
    IO;
    cin >> n >> k;
    int l = 1, r = n * n, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (cal(mid) < k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}