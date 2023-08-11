// Problem: Make Numbers
// URL: https://codeforces.com/gym/102835/problem/B
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

int n, a[5], yes[20000];
string s;

void work(string st) {
    bool can = false;
    for (auto x:st) {
        if (x == '+' || x == '-' || x =='*') can = true;
    }
    if (!can) return;
    int ans = 0;
    int len = st.size();
    int pos = len - 1; int num1 = 0, num2 = 1, num3; bool m = false;
    while (pos >= 0) {
        num1 = 0;
        int p1 = pos;
        while (p1 -1 >= 0 && st[p1 - 1] - '0' > 0 && st[p1 - 1] - '0' < 10) {
            p1 --;
        }
        repn(i, p1, pos) {
            num1 *= 10;
            num1 += st[i] - '0';
        }
        pos = p1 - 1;
        if (pos >= 0) {
            if (st[pos] == '*'){
                m = true; num2 *= num1;
            }
            else {
                if (m) {
                    num3 = num1 * num2;
                    m = false; num2 = 1;
                }
                else num3 = num1;
                if (st[pos] == '+') ans += num3;
                else ans -= num3;
            }
            pos --;
        }
        else {
            if (m) num3 = num1 * num2;
            else num3 = num1;
            ans += num3;
        }
    }
    if (ans >= 0) yes[ans] = 1;
}

void dfs(int t, int y, int pos, string st) {
    if (t == 15) {
        work(st);
        return;
    }
    bool can = false;
    if (pos > 0 && st[pos - 1] - '0' > 0 && st[pos - 1] - '0' < 10) can = true;
    if (can) {
        dfs(t, 1, pos + 1, st + '+');
        dfs(t, 1, pos + 1, st + '-');
        dfs(t, 1, pos + 1, st + '*');
    }
    int num, tot = t; char ch;
    repn(i, 1, 4) {
        num = tot % 2; tot /= 2;
        if (num) continue;
        ch = '0' + a[i];
        dfs(t + (1 << (i - 1)), y, pos + 1, st + ch);
    }
}

int main(){
    repn(i, 1, 4) scanf("%d", &a[i]);
    dfs(0, 0, 0, s);
    int result = 0;
    repn(i, 0, 15000) if (yes[i]) result ++;
    //repn(i, 0, 15000) if(yes[i]) printf("%d ", i);
    printf("%d\n", result);
    return 0;
}




