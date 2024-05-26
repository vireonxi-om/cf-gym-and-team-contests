// Problem: Gene Folding
// URL: https://codeforces.com/gym/104633/problem/D
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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull)new char);

#define rand Rand

ull mod_list[5] = {
    1000000007, 998244353, 1000000009, 199707181, 200210183};
struct StringHash {
    int n;
    StringHash() {}
    const ull base = rand() >> 40, cont = rand() % ((1 << 10) - 1);
    ull mod = mod_list[rand() % 5];
    vector<ull> hsh, rhsh, pw;
    void init(string s, int _n) {
        n = _n;
        hsh.resize(n + 2), rhsh.resize(n + 2), pw.resize(n + 2);
        pw[0] = 1;
        rep(i, 1, n + 2) pw[i] = (pw[i - 1] * base) % mod;
        hsh[0] = rhsh[n + 1] = 0;
        repn(i, 1, n) hsh[i] = (hsh[i - 1] * base + s[i - 1] + cont + mod) % mod;
        pern(i, 1, n) rhsh[i] = (rhsh[i + 1] * base + s[i - 1] + cont + mod) % mod;
    }
    ull get_hsh(int l, int r) {
        ull res;
        if (l <= r) res = (hsh[r] - (hsh[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
        else swap(l, r), res = (rhsh[l] - (rhsh[r + 1] * pw[r - l + 1] % mod) + mod) % mod;
        return res;
    }
    int check_palindrome(int l, int r) {
        if (l > r) return 1;
        return get_hsh(l, r) == get_hsh(r, l);
    }
}A, B;
int n;
string s;
int main() {
    IO;
    cin >> s;
    n = s.size();
    A.init(s, n), B.init(s, n);
    int l = 1, r = n, cl = 1, cr = n;
    while (1) {
        int lenl = cl - l + 1, lenr = r - cr + 1;
        if (lenl <= lenr) {
            if (l + lenl + lenl - 1 > r) break;
            if (A.check_palindrome(l, l + lenl + lenl - 1) && B.check_palindrome(l, l + lenl + lenl - 1)) {
                l = cl = l + lenl;
            }
            else cl++;
        }
        else {
            if (r - lenr - lenr + 1 < l) break;
            if (A.check_palindrome(r - lenr - lenr + 1, r) && B.check_palindrome(r - lenr - lenr + 1, r)) {
               r = cr = r - lenr;
            }
            else cr--;
        }
    }
    cout << r - l + 1 << "\n";
    return 0;
}
