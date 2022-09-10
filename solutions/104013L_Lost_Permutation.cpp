// Problem: Lost Permutation
// URL: https://codeforces.com/gym/104013/problem/L
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

const int N = 11000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;

int n;
int f[N], a[N], f2[N], b[N];

void solve() {
    cin >> n;
    cout << "?";
    repn(i, 1, n){
        if (i - 1) cout << " " << i - 1;
        else cout << " " << n;
    } 
    cout << endl; fflush(stdout);
    repn(i, 1, n) cin >> f[i];
    cout << "?";
    repn(i, 1, n){
        int num;
        if (i == 1) num = n;
        else if (i == 2) num = n - 1;
        else num = i - 2;
        cout << " " << num;
    } 
    cout << endl; fflush(stdout);
    repn(i, 1, n) cin >> f2[i];
    repn(i, 1, n) a[i] = 0;
    int pos;
    repn(i, 1, n) {
        if (f[i] == f2[i]) {
            a[f[i]] = n;
            b[n] = f[i];
            pos = f[i];
        }
    }
    while (1) {
        int nxt = f[pos];
        if (a[nxt] > 0) break;
        a[nxt] = a[pos] - 1;
        b[a[nxt]] = nxt;
        pos = nxt;
    }
    cout << "!";
    repn(i, 1, n) cout << " " << b[i];
    cout << endl;
    fflush(stdout);
}

int main() {
    IO;
    int t;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}



