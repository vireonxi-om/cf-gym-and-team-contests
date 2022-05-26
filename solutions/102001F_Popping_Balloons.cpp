// Problem: Popping Balloons
// URL: https://codeforces.com/gym/102001/problem/F
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
const LL INF = 1e15;
const int maxn = 100010;

int n, id[N];
LL a[N], b[N], m, tb[N];
stack<int> s;
vector<LL> ans;

int main(){
    scanf("%d%lld", &n, &m);
    repn(i, 1, n) scanf("%lld", &a[i]);
    repn(i, 1, n){ scanf("%lld", &b[i]); tb[i] = b[i];}
    int tot = n;
    repn(i, 1, n) {
        a[i] = a[i - 1] + a[i];
        if (a[i] > m) {
            tot = i - 1;
            break;
        }
    }
    if (tot == 0) {
        printf("-1\n");
        return 0;
    }
    repn(i, 1, tot){
        tb[i] = tb[i - 1] + tb[i];
        if (tb[i] < a[1]) continue;
        while (!s.empty() && b[s.top()] < b[i]) s.pop();
        s.push(i);
    }
    int len = s.size();
    if (len == 0) {
        printf("-1\n");
        return 0;
    }
    pern(i, 1, len) {
        id[i] = s.top();
        s.pop();
    }
    LL ext = 0; int pt = 1;
    bool can = true;
    repn(i, 1, tot) {
        LL b_t = a[i] - ext;
        while (pt <= len && tb[id[pt]] < b_t) pt ++;
        if (pt > len) {
            can = false;
            break;
        }
        int now = id[pt];
        if (ext + tb[now] <= m) ans.pb(ext + tb[now]);
        else break;
        ext += b[now];
    }
    if (can && ext + tb[tot] <= m) can = false;
    if (!can) printf("-1\n");
    else{
        int num = ans.size();
        printf("%d\n", num);
        for(auto x: ans) printf("%lld ", x);
        printf("\n");
    }
    return 0;
}