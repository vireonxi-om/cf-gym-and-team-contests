// Problem: Landscape Generator
// URL: https://codeforces.com/gym/104633/problem/E
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
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n - 1); i >= a; i--)
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);

#define rand Rand

LL cnt[3][N], f[2][N], a[N];
int n, k;

int main() {
    IO;
    cin >> n >> k;
    int l, r;
    int num;
    string s;
    repn(i, 1, k) {
        cin >> s >> l >> r;
        if (s[0] == 'R'|| s[0] == 'D') {
                if (s[0] =='R') num = 1;
                else num = -1;
                cnt[2][l] += num; cnt[2][r + 1] -= num;
        }
        else {
                int mid1 = (l + r) / 2;
                int mid2 = (l + r + 1) / 2;
                num = mid1 - l + 1;
                if (s[0] == 'H') {
                        cnt[1][mid1] += num;
                        f[1][mid1] -= 1;
                        f[1][l - 1] += 1;
                        cnt[0][mid2] += num;
                        f[0][mid2] -= 1;
                        f[0][r + 1] += 1;
                        if (mid1 == mid2) {
                                cnt[2][mid1] -= num; cnt[2][mid1 + 1] += num;
                        }
                }
                else {
                        cnt[1][r] += num;
                        f[1][r] -= 1;
                        f[1][mid2 - 1] += 1;
                        cnt[0][l] += num;
                        f[0][l] -= 1;
                        f[0][mid1 + 1] += 1;
                        if (mid1 == mid2) {
                                cnt[2][mid1] -= 1; cnt[2][mid1 + 1] += 1;
                        }
                        cnt[2][l] += - num - 1; cnt[2][r + 1] -= - num - 1;
                }
        }
    }
    LL sum = 0;
    repn(i, 1, n) {
        sum += cnt[2][i];
        a[i] = sum;
    }
    sum = 0;
    LL ids = 0;
    repn(i, 1, n) {
        sum += cnt[0][i];
        a[i] += sum;
        ids += f[0][i];
        sum += ids;
    }
    sum = 0; ids = 0;
    pern(i, 1, n) {
        sum += cnt[1][i];
        a[i] += sum;
        ids += f[1][i];
        sum += ids;
    }
    repn(i, 1, n) {
        cout << a[i] << "\n";
    }
    return 0;
}
