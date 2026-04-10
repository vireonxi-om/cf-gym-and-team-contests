// Problem: A Billionaire
// URL: https://codeforces.com/gym/103176/problem/A
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

const int N = 1100000;
const int M = 11000000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n;
LL k, e;
LL c[210];

int main(){
    scanf("%d%lld%lld", &n, &k, &e);
    repn(i, 1, n) scanf("%lld", &c[i]);
    sort(c + 1, c + n + 1);
    repn(i, 1, n) c[i] = c[i - 1] + c[i];
    LL d = 0;
    repn(i, 1, n) {
        d ++;
        if (d * e + k > c[i]) {
            continue;
        }
        else {
            d = (c[i] - k + e - 1) / e;
        }
    }
    printf("%lld\n", d);
    return 0;
}
