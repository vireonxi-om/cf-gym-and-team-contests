// Problem: K.O. Kids
// URL: https://codeforces.com/gym/104059/problem/K
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

const int N = 110000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;


int main() {
    IO;
    int n, k;
    string s;
    cin >> n >> k >> s;
    char cur = 'L';
    int cnt = 0;
    rep(i, 0, n) {
        if (s[i] != cur){
            cnt ++;
        }
        else {
            if (cur == 'L') cur = 'R';
            else cur = 'L';
        }
    }
    if (cnt >= k) cout << 0 << "\n";
    else cout << k - cnt << "\n";
    return 0;
}



