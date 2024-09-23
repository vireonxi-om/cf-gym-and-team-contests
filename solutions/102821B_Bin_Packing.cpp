// Problem: Bin Packing
// URL: https://codeforces.com/gym/102821/problem/B
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

const int N = 3100000;
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int a, b, c, d;

double cal(int a, int b, int c, int d) {
    if (a == c) return 0;
    if (a < c) return (double)(c - a) * b / 2;
    if (a > c) return (double)(a - c) * d / 2;
}

void solve(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    double ans = 1000000;
    ans = min(ans, cal(a, b, c, d));
    ans = min(ans, cal(a, b, d, c));
    ans = min(ans, cal(b, a, c, d));
    ans = min(ans, cal(b, a, d, c));
    ans += a * b + c * d;
    printf("%.5f\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    repn(i, 1, t){
        printf("Case %d: ", i);solve();
    }
    return 0;
}