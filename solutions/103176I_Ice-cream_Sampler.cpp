// Problem: Ice-cream Sampler
// URL: https://codeforces.com/gym/103176/problem/I
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
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int num, ix = 8, iy = 1, ox = 13, oy = 1;
int a[15];
PII p[15];
int tot = 1e9;

void func(int i, int id) {
    int x, y;
    if (id <= 14) {
        x = 8 - (id + 1) / 2;
        y = 1;
    }
    else if (id <= 26) {
        x = 1;
        y = (id - 13) / 2;
    }
    else if (id <= 66) {
        y = 6;
        x = (id - 25) / 2;
    }
    else if (id <= 78) {
        x = 20;
        y = 7 - (id - 65) / 2;
    }
    else {
        y = 1;
        x = 21 - (id - 77) / 2;
        if (id >= 93) x --;
    }
    p[i] = mp(x, y);
}

void work(int len, int x, int y, int sum) {
    if (len == 11) {
        sum += abs(ox - x) + abs(oy - y);
        tot = min(tot, sum);
        return;
    }
    repn(i, 1, 10) {
        if (a[i]) continue;
        a[i] = 1;
        work(len + 1, p[i].fi, p[i].se, sum + abs(p[i].fi - x) + abs(p[i].se - y));
        a[i] = 0;
    }
}

int main(){
    repn(i, 1, 10) {
        scanf("%d", &num);
        func(i, num);
    }
    work(1, ix, iy, 0);
    printf("%d\n", tot);
    return 0;
}
