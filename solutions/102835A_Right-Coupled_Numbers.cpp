// Problem: Right-Coupled Numbers
// URL: https://codeforces.com/gym/102835/problem/A
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
const LL INF = 1e17;
const int maxn = 100010;

int n;
vector<int> p[M];


void solve(){
    int num;
    scanf("%d", &num);
    int tot = p[num].size();
    bool can = false;
    int a, b;
    rep(i, 0, tot) {
        repn(j, i, tot) {
            a = p[num][i]; b = p[num][j];
            if (a * b != num) continue;
            if (a > b) swap(a, b);
            if ((double) a / b >= 0.5) can = true;
        }
    }
    if (can) printf("1\n");
    else printf("0\n");
}

int main(){
    int tot = 1 << 15;
    rep(i, 1, tot) {
        rep(j, 1, tot) {
            if (i * j > tot) break;
            p[i * j].pb(i);
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}




