// Problem: Commemorative Dice
// URL: https://codeforces.com/gym/102920/problem/B
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

const int N = 210000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, a[10], b[10];

int gcd (int a, int b) {
    return b == 0 ? a: gcd (b, a % b);
}

int main(){
    repn(i, 1, 6) scanf("%d", &a[i]);
    repn(i, 1, 6) scanf("%d", &b[i]);
    int cnt = 0;
    repn(i, 1, 6) {
        repn(j, 1, 6) {
            if (a[i] > b[j]) cnt ++;
        }
    }
    int ans = 36;
    int t = gcd (cnt, 36);
    ans /= t; cnt /= t;
    printf("%d/%d\n", cnt , ans);
    return 0;
}
