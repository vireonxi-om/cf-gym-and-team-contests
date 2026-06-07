// Problem: Non-Integer Donuts
// URL: https://codeforces.com/gym/103185/problem/N
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;

int n;
char a[10];

int main() {
    scanf("%d", &n);
    int num = 0, cur, cnt = 0;
    repn(i, 0, n) {
        scanf("%s", &a);
        if (a[2] == '.') {
            cur = (a[1] - '0') * 100 + (a[3] - '0') * 10 + (a[4] - '0');
        }
        else cur = (a[1] - '0') * 1000 + (a[2] - '0') * 100 + (a[4] - '0') * 10 + (a[5] - '0');
        num += cur;
        if (i) {
            if (num % 100) cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

