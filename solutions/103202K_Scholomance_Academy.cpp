// Problem: Scholomance Academy
// URL: https://codeforces.com/gym/103202/problem/K
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

const int N = 510000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n;
vector<int> a, b;

int main(){
    scanf("%d", &n);
    int num;
    repn(i, 1, n){
        char now='a';
        while(now != '+' && now != '-') scanf("%c", &now);
        scanf("%d", &num);
        if (now == '-') b.pb(-num);
        else a.pb(num);
    }
    sort(all(a)); sort(all(b));
    LL ta = a.size(), tb = b.size();
    LL tot = 0;
    rep(i, 0, tb) {
        num = - b[i];
        auto it = upper_bound(a.begin(), a.end(), num);
        if (it == a.end()) continue;
        tot += ta - (it - a.begin());
    }
    double ans = tot;
    ans = ans / (ta * tb);
    printf("%.14f\n", ans);
    return 0;
}

