// Problem: Icy Land
// URL: https://codeforces.com/gym/102001/problem/D
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

int n, m;
char s[510][510];

int main(){
    scanf("%d%d", &n, &m);
    repn(i, 1, n) {
        scanf("%s", s[i] + 1);
    }
    int cnt = 0;
    if (n >= 3 && m >= 3) {
        int cnt1 = 1, cnt2 = (n - 2) * (m - 2);
        repn(i, 2, n - 1){
            if (s[i][1] == '#' || s[i][m] == '#') cnt1 --;
        }
        repn(j, 2, m - 1) {
            if (s[1][j] == '#' || s[n][j] == '#') cnt1 --;
        }
        repn(i, 2, n - 1) {
            repn(j, 2, m - 1) {
                if (s[i][j] == '#') cnt2 --;
            }
        }
        if (cnt1 == 1) cnt ++;
        cnt += cnt2;
    }
    else if (n <= 2 && m <= 2) {
        cnt = 0;
    }
    else if (n <= 2) {
        repn(j, 2, m - 1) {
            if (s[1][j] != '#' && s[n][j] != '#') cnt ++;
        }
    }
    else if (m <= 2) {
        repn(i, 2, n - 1) {
            if (s[i][1] != '#' && s[i][m] != '#') cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}