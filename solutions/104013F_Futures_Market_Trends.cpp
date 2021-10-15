// Problem: Futures Market Trends
// URL: https://codeforces.com/gym/104013/problem/F
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

const int N = 1000100;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

int n;
double P;
double d[3100], d2[3100], s[3100], s2[3100];

int main() {
    IO;
    cin >> n >> P;
    double nxt, cur;
    cin >> cur;
    repn(i, 2, n) {
        cin >> nxt;
        d[i] = nxt - cur;
        cur = nxt;
        d2[i] = d[i] * d[i];
    }
    repn(i, 1, n) {
        s[i] = d[i] + s[i - 1];
        s2[i] = d2[i] + s2[i - 1];
    }
    int ans = 0, ans1 = 0;
    repn(i, 2, n) {
        repn(j, i + 1, n) {
            int l = j - i + 1;
            double A = (s[j] - s[i - 1]) / l;
            double D = s2[j] - s2[i - 1] - 2 * A * (s[j] - s[i - 1]) + A * A * l;
            D /= l;
            D = sqrt(D);
            //cout << A << " " << D << "\n";
            if (A < eps && A > -eps) continue;
            if (D < eps && D > -eps) {
                if (A > - eps) ans ++;
                else ans1 ++;
            }
            else {
                if (A / D - P >= -eps) ans ++;
                else if (A / D + P <= eps) ans1 ++;   
            }
        }
    }
    cout << ans << " " << ans1 << "\n";
    return 0;
}



