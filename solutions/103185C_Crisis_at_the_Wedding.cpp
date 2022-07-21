// Problem: Crisis at the Wedding
// URL: https://codeforces.com/gym/103185/problem/C
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

int n;
LL a[N], b[N];

int main() {
    scanf("%d", &n);
    LL sum = 0;
    repn(i, 1, n) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sum /= n;
    repn(i, 1, n) b[i] = a[i] - sum;
    LL now = 0, tot = 0;
    repn(i, 1, n) {
        tot += now;
        if (b[i] > 0){ now += b[i]; b[i] = 0;}
        else if (b[i] < 0){
            if (b[i] + now >= 0) {
                now += b[i];
                b[i] = 0;
            }
            else {
                b[i] += now;
                now = 0;
            }
        }
    }
    repn(i, 1, n) {
        tot += now;
        if (b[i] != 0) now += b[i];
    }
    LL ans = tot;
    repn(i, 1, n) b[i] = a[n - i + 1] - sum;
    now = 0, tot = 0;
    repn(i, 1, n) {
        tot += now;
        if (b[i] > 0){ now += b[i]; b[i] = 0;}
        else if (b[i] < 0){
            if (b[i] + now >= 0) {
                now += b[i];
                b[i] = 0;
            }
            else {
                b[i] += now;
                now = 0;
            }
        }
    }
    repn(i, 1, n) {
        tot += now;
        if (b[i] != 0) now += b[i];
    }
    ans = min(ans, tot);
    printf("%lld\n", ans);
    return 0;
}

