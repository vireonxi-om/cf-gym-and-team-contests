// Problem: Hack a Contest
// URL: https://codeforces.com/gym/102821/problem/H
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
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, m;
LL a[N];
int t[20];

void solve(){
    scanf("%d%d", &n, &m);
    repn(i, 1, n) scanf("%lld", &a[i]);
    repn(i, 1, m) scanf("%d", &t[i]);
    sort(a + 1, a + n + 1);
    sort(t + 1, t + m +1);
    int now = 0;
    LL ans = 0;
    repn(i, 1, m){
        now += t[i];
        ans += a[now];
        ans += 20 * (t[i] - 1);
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    repn(i, 1, t){
        printf("Case %d: ", i);solve();
    }
    return 0;
}