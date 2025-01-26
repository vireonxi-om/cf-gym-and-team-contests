// Problem: Swapping Places
// URL: https://codeforces.com/gym/102501/problem/G
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
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;
int s, l;
map<string, int> name;
string sts[210];
vector<string> str;
queue<int> q[210];
int c[210][210], a[N], p[210], flag[N];
vector<string> ans;
queue<int> now;

int main(){
    IO;
    cin >> s >> l >> n;
    string st, st1;
    repn(i, 1, s) {
        cin >> st; str.pb(st);
    }
    sort(all(str)); int pos = 0;
    for (auto x: str){ name[x] = ++pos; sts[pos] = x;}
    int id1, id2;
    repn(i, 1, l) {
        cin >> st1 >> st;
        id1 = name[st1]; id2 = name[st];
        c[id1][id2] = 1; c[id2][id1] = 1;
    }
    repn(i, 1, s) c[i][i] = 1;
    repn(i, 1, n) {
        cin >> st;
        a[i] = name[st];
        if (p[a[i]] == 0) p[a[i]] = i;
    }
    repn(i, 1, s) {
        if (p[i] == 0) q[i].push(n + 1);
        repn(j, 1, p[i]) if (!c[i][a[j]]) q[i].push(j);
    }
    repn(i, 1, n) {
        /*
        cout << i << endl;
        repn(j, 1, s) {
            cout << j << ": ";
            while(!now.empty()) now.pop();
            while(!q[j].empty()) {
                cout << q[j].front() << " ";
                now.push(q[j].front()); q[j].pop();
            } cout << endl;
            while(!now.empty()) { q[j].push(now.front()); now.pop();}
        }
         */
        repn(j, 1, s) {
            while (!q[j].empty()) {
                if (flag[q[j].front()]) q[j].pop();
                else break;
            }
        }
        repn(j, 1, s) {
            if (q[j].empty()) {
                flag[p[j]] = 1;
                p[j] ++;
                while(p[j] <= n && a[p[j]] != j) {
                    if (c[a[p[j]]][j] == 0) q[j].push(p[j]);
                    p[j] ++;
                } //cout << "p[j] : " <<  p[j] << endl;
                if (p[j] == n + 1) {
                    while (!q[j].empty()) q[j].pop();
                    q[j].push(n + 1);
                }
                ans.pb(sts[j]);
                break;
            }
        }
    }
    for (auto x: ans) cout << x << ' '; cout << endl;
    return 0;
}

