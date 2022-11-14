// Problem: Tiling Polyomino
// URL: https://codeforces.com/gym/102920/problem/K
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
const LL INF = 1e15;
const int maxn = 100010;

int n;
char s[1100][1100];

int main(){
    scanf("%d", &n);
    repn(i, 1, n) {
        scanf("%s", s[i] + 1);
    }
    bool can = true;
    repn(i, 1, n) {
        repn(j, 1, n) {
            if (s[i][j] != '1') continue;
            if (j + 1 <= n && s[i][j + 1] == '1') {
                s[i][j] = '2'; s[i][j + 1] = '2';
            }
            else if (j > 1 && s[i][j - 1] =='2') {
                s[i][j - 2] = '4'; s[i][j - 1] = '4'; s[i][j] = '4';
            }
            else if (i > 1 && s[i - 1][j] == '3') {
                s[i - 2][j] = '5'; s[i - 1][j] = '5'; s[i][j] = '5';
            }
            else if (i < n && s[i + 1][j] == '1') {
                s[i][j] = '3'; s[i + 1][j] = '3';
            }
            else {
                can = false;
                break;
            }
        }
    }
    if (can) {
        repn(i, 1, n) printf("%s\n", s[i] + 1);
    }
    else printf("-1\n");
    return 0;
}
