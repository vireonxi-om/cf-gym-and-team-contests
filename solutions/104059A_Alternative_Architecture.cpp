// Problem: Alternative Architecture
// URL: https://codeforces.com/gym/104059/problem/A
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

const int N = 1100000;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

long long a, b;

int main() {
    IO;
    cin >> a >> b;
    a --; b --;
    int cnt = 2;
    if (b < a) swap(a, b);
    long long tot = a * a;
    for (long long i = 1; i <= a; i ++) {
        long long j = sqrt(double(tot) - i * i + 0.1);
        if (j < i) break;
        if (j * j + i * i != tot) continue;
        long long ej = j * b / a, ei = i * b / a;
        if (ej * a != j * b || ei * a != i * b) continue;
        if (j > i) cnt += 4;
        else if (j == i) cnt += 2;
        //cout << i << j << "\n";
    }
    if (a == b) cnt /= 2;
    cout << cnt << "\n";
    return 0;
}



