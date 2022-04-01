// Problem: TreeBag and LIS
// URL: https://codeforces.com/gym/105143/problem/C
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

LL x;
int main() {
    IO;
    cin >> x;
    if (x == 0) {
        cout << "0\n";
        return 0;
    }
    if (x <= 100000) {
        repn(i, 1, x) cout << "1";
        cout << "\n";
        return 0;
    }
    repn(i, 1, 1000) cout << "7";
    repn(i, 1, 1000) cout << "8";
    while (x - 789000000 >= 10000) {
        cout << "9";
        x -= 789000000;
    }
    repn(i, 1, 10) cout << "4";
    repn(i, 1, 10) cout << "5";
    while (x - 45600 >= 10000) {
        cout << "6";
        x -= 45600;
    }
    cout << "01";
    int num = x / 12;
    int n3 = x % 12;
    repn(i, 1, n3) cout << "3";
    repn(i, 1, num - n3) cout << "2";
    cout << "\n";
    return 0;
}