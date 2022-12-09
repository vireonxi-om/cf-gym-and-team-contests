// Problem: Guessing Game
// URL: https://codeforces.com/gym/103176/problem/G
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
const int M = 11000000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n;
int a, b;

int main(){
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    int m = 0, id, now;
    repn(i, 1, 100) {
        if (i == a || i == b) continue;
        if (i < a) now = i;
        else if (i > b) now = 100 - i + 1;
        else {
            now = 1;
            now += i - (i + a) / 2 - 1;
            now += (i + b + 1) / 2 - i - 1;
        }
        if (now >= m) { m = now; id = i;}
    }
    printf("%d\n", id);
    return 0;
}
