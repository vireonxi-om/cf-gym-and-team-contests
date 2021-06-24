// Problem: Autochess
// URL: https://codeforces.com/gym/102821/problem/A
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

int n, m, k, a[N], cnt[N][5], l[N];
map<string, int> ch;
vector<int> pos[N][5];
string s, name[N];
priority_queue<int> lf;

void solve(){
    scanf("%d%d%d", &m, &n, &k);
    ch.clear();
    while (!lf.empty()) lf.pop();
    repn(i, 1, n){ a[i] = -1; lf.push(-i);}
    repn(i, 1, m){
        repn(j, 1, 3){
            cnt[i][j] = 0;
            pos[i][j].clear();
        }
    }
    int tot = 0;
    repn(z, 1, m) {
        cin >> s;
        int t;
        if (ch.count(s) == 0) {
            t = ++ tot;
            ch[s] = t;
            name[t] = s;
        }
        else t = ch[s];
        if (cnt[t][3]) continue;
        if (cnt[t][1] < k - 1) {
            if (lf.empty()) continue;
            cnt[t][1] ++;
            int p = -lf.top(); lf.pop();
            a[p] = t; l[p] = 1;
            pos[t][1].pb(p);
        }
        else {
            cnt[t][1] = 0;
            for(auto x : pos[t][1]){
                lf.push(-x); a[x] = -1;
            }
            pos[t][1].clear();
            if (cnt[t][2] < k - 1) {
                cnt[t][2] ++;
                int p = -lf.top(); lf.pop();
                a[p] = t; l[p] = 2;
                pos[t][2].pb(p);
            }
            else {
                cnt[t][2] = 0;
                for (auto x : pos[t][2]){
                    lf.push(-x); a[x] = -1;
                }
                pos[t][2].clear();
                int p = -lf.top(); lf.pop();
                a[p] = t; l[p] = 3;
                cnt[t][3] = 1;
            }
        }
    }
    repn(i, 1, n) {
        if (a[i] == -1) printf("-1");
        else{
            cout << name[a[i]];
            if (l[i] > 1) printf("%d", l[i]);
        }
        if (i < n) printf(" ");
        else printf("\n");
    }

}

int main(){
    int t;
    scanf("%d", &t);
    repn(i, 1, t){
        printf("Case %d: ", i);solve();
    }
    return 0;
}