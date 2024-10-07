// Problem: Inverted Deck
// URL: https://codeforces.com/gym/102500/problem/I
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1100000;
const int M = 510000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-12;
const double eps2 = 1e-12;

int n;
int a[N], b[N];

int main() {
    scanf("%d", &n);
    repn(i, 1, n) {scanf("%d", &a[i]); b[i] = a[i];}
    sort(b + 1, b + n + 1);
    int l = n + 1, r = 0, flag = 0;
    repn(i, 1, n) {
        if (a[i] != b[i]) {
            l = i; break;
        }
    }
    pern(i, 1, n) {
        if (a[i] != b[i]) {
            r = i; break;
        }
    }
    bool yes = true;
    if (l <= r) {
        int len = r - l + 1;
        repn(k, 1, len) {
            if (a[l + k - 1] != b[r - k + 1]) yes = false;
        }
    }
    else if (l > r) {
        l = 1; r = 1;
    }
    if (yes) printf("%d %d\n", l, r);
    else printf("impossible\n");
    return 0;
}