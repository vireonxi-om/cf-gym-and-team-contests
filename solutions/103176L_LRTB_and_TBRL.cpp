// Problem: LRTB and TBRL
// URL: https://codeforces.com/gym/103176/problem/L
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

int n, r, c;
int fa[N];
set<int> f;

int findfa(int i) {
    return fa[i] == i ? i : fa[i] = findfa(fa[i]);
}

int main(){
    scanf("%d%d%d", &n, &r, &c);
    int now = 1, u, v;
    repn(i, 1, r * c) fa[i] = i;
    pern(j, 1, c) {
        repn(i, 1, r) {
            u = now; v = (i - 1) * c + j;
            int fau = findfa(u), fav = findfa(v);
            fa[fav] = fau;
            now ++;
        }
    }
    repn(i, 1, r * c) {
        f.insert(findfa(i));
    }
    int tot = f.size();
    LL ans = 1;
    repn(i, 1, tot){
        ans *= n;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}
