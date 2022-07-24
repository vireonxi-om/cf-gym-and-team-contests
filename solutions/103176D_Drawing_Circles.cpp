// Problem: Drawing Circles
// URL: https://codeforces.com/gym/103176/problem/D
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

int n;
double r1, r2;
priority_queue<pair<double, PDD>> p;

int main(){
    scanf("%lf%lf%d", &r1, &r2, &n);
    r1 = 1 / sqrt(r1);
    r2 = 1 / sqrt(r2);
    p.push(mp(-(r1 + r2), mp(r1, r2)));
    repn(i, 1, n) {
        auto it = p.top();
        p.pop();
        double r = -it.fi;
        r = 1 / r; r = r * r;
        r1 = it.se.fi; r2 = it.se.se;
        printf("%.8f\n", r);
        p.push(mp(- 2 * r1 - r2, mp(r1, r1 + r2)));
        p.push(mp(- 2 * r2 - r1, mp(r2, r1 + r2)));
    }
    return 0;
}
