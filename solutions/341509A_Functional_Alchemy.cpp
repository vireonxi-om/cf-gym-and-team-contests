// Problem: Functional Alchemy
// URL: https://codeforces.com/gym/341509/problem/A
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n, m;
LL k, num, a[20][5], b[20][5];
set<pair<int, LL>> s;

int main(){
    repn(i, 1, 10) scanf("%lld", &a[i][0]);
    scanf("%lld", &k);
    repn(i, 1, k) {
        scanf("%lld", &num);
        char c = 'a';
        int now = -1;
        int type = -1;
        while (c != '\n') {
            scanf("%c", &c);
            if (type > 0) continue;
            if (now == -1) {
                if (c > 64 && c <= 74) now = c - 64;
                else continue;
            }
            else {
                if (c > 64 && c <= 74) type = 1;
                else if (c == '*') type = 2;
                else continue;
            }
        }
        a[now][type] += num;
    }
    repn(t, 1, 10) {
        repn(i, 1, 10) {
            repn(j, 0, 2) b[i][j] = a[i][j];
            if (i == t) continue;
            if (b[i][2] == 0) {
                b[i][0] = 0; b[i][1] = 0;
            }
            else {
                if (b[i][0]) {
                    b[i][0] += b[i][1];
                    b[i][1] = 0;
                }
            }
        }
        s.clear();
        repn(i, 1, 10) {
            if (b[i][2] == 0 || b[i][0] == 0) continue;
            s.insert(mp(i, min(b[i][0], b[i][2])));
        }
        repn(i, 1, 10) {
            if (s.empty()) break;
            if (i == t || b[i][2] == 0 || b[i][1] == 0) continue;
            auto it = s.begin();
            int now = (*it).fi;
            b[i][0] = 1 + b[i][1]; b[i][1] = 0;
            s.erase(it);
            s.insert(mp(i, min(b[i][2], b[i][0])));
            b[now][0] --; b[now][2] --;
            if (b[now][0] == 0 || b[now][2] == 0) continue;
            s.insert(mp(now, min(b[now][2], b[now][0])));
        }
        LL sum = 0;
        repn(i, 1, 10) {
            if (i == t) continue;
            sum += min(b[i][0], b[i][2]);
        }
        b[t][0] += sum;
        if (b[t][1] && b[t][0]) b[t][0] += b[t][1];
        printf("%lld", b[t][0]);
        if (t != 10) printf(" ");
        else printf("\n");
    }
    return 0;
}