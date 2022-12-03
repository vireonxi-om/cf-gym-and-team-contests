// Problem: Which Planet is This?!
// URL: https://codeforces.com/gym/104633/problem/O
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
vector<PII> a[2], b[2];
int n, pos[2];

int mincyc(vector<PII> &s) {
    int k = 0, i = 0, j = 1, n = s.size();
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) k++;
        else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1: j = j + k + 1;
            k = 0;
            if (i == j) i++;
        }
    }
    return min(i, j);
}
int cal(string s) {
    int n = s.size();
    int res = 0, cnt = 0, flag = 0, f = 1;
    rep(i, 0, n) {
        if (s[i] == '-') f = -1;
        else if (s[i] == '.') flag = 1;
        else {
            if (flag) cnt++;
            res = res * 10 + s[i] - '0';
        }
    }
    while (cnt < 4) res = res * 10, cnt++;
    return res * f;
}
int main() {
    IO;
    cin >> n;
    string s;
    int num1, num2;
    repn(j, 0, 1) {
        repn(i, 1, n) {
            string s, t;
            cin >> s >> t;
            num1 = cal(s), num2 = cal(t);
            a[j].pb(mp(num2, num1));
        }
        sort(all(a[j]));
        int last = a[j][a[j].size() - 1].fi;
        for (auto pr : a[j]) {
            b[j].pb(mp((pr.fi - last + 3600000) % 3600000, pr.se));
            last = pr.fi;
        }
        // for (auto x: b[j]) cout << "(" << x.fi << "," << x.se << ") ";
        // cout << endl;
        pos[j] = mincyc(b[j]);
    }
    bool can = true;
    repn(i, 0, n) {
        if (b[0][(pos[0] + i)%n] != b[1][(pos[1] + i) % n]) can = false;
    }
    if (can) cout << "Same\n";
    else cout << "Different\n";
    return 0;
}
