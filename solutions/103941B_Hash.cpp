// Problem: Hash
// URL: https://codeforces.com/gym/103941/problem/B
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

const int N = 210000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

long long dp[N], num[N];


int main() {
    IO;
    int n;
    string s;
    cin >> s;
    n = s.length();
    rep(i, 0, n) {
        int t;
        if (s[i] == 'a') t = 1;
        else if (s[i] == 'e') t = 2;
        else if (s[i] == 'h') t = 3;
        else t = 4;
        num[i + 1] = t;
    }
    int len = min(15, n);
    repn(i, 1, len) num[n + i] = num[i];
    long long ans = 0;
    repn(st, 1, len) {
        int ed = st + n - 1;
        repn(i, 0, n + 20) dp[i] = 0;
        repn(i, st, ed) {
            long long sum = 0;
            repn(j, i, min(i + 14, ed)) {
                sum *= 31;
                sum += num[j];
                sum %= mod;
                dp[j] = max(dp[j], dp[i - 1] + sum); 
            }
        }
        ans = max(ans, dp[ed]);
    }
    cout << ans << "\n";
    return 0;
}



