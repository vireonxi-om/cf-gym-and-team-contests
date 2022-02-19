// Problem: Color the Tree
// URL: https://codeforces.com/gym/102896/problem/C
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
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;
const int maxn = 100010;

int n, p[30];
vector<int> g[30];
vector<int> a[30];

void dfs(int u, int v) {
    a[u].pb(u);
    vector<int> now, n1;
    now.clear(); n1.clear();
    for (auto x: g[u]) {
        if (x == v) continue;
        dfs(x, u);
        n1.clear(); for(auto y : now) n1.pb(y);
        int len = n1.size(), pos = 1;
        for(auto y: a[x]) {
            now.pb(y);
            if (pos == 0){ rep(i, 0, len) now.pb(n1[i]); pos = 1;}
            else { for(int i = len - 1; i >=0 ; i --) now.pb(n1[i]); pos = 0;}
        }
    }
    for (auto y : now) a[u].pb(y);
}


int main(){
    scanf("%d", &n);
    repn(i, 2, n){
        scanf("%d", &p[i]);
        g[i].pb(p[i]);
        g[p[i]].pb(i);
    }
    dfs(1, 0);

    int tot = a[1].size();
    printf("%d\n", tot - 1);
    rep(i, 1, tot) printf("%d ", a[1][i]);
    printf("\n");
    return 0;
}



