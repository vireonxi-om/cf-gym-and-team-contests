// Problem: Improving IT
// URL: https://codeforces.com/gym/104059/problem/I
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

const int N = 510000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

long long dp[N];

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    repn(i, 2, n + 1) dp[i] = INF;
    repn(i, 1, n) {
        long long c, p;
        cin >> c;
        repn(j, 1, min(m, n - i + 1)) {
            cin >> p;
            dp[i + j] = min(dp[i + j], dp[i] - p + c);
        }
    }
    cout << dp[n + 1] << "\n";
    return 0;
}



