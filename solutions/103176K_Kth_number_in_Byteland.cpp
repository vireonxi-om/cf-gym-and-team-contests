// Problem: Kth number in Byteland
// URL: https://codeforces.com/gym/103176/problem/K
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

const int N = 1100000;
const int M = 11000000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int num;
char s[100], ans[100];

int main(){
    scanf("%d", &num);
    int m = 0;
    num --;
    repn(i, 1, 10000) {
        s[i] = '0' + (num % 10);
        m = i;
        num /= 10; if (num == 0) break;
    }
    int now = 1;
    pern(i, 1, m) ans[now ++] = s[i];
    repn(i, 2, m) ans[now ++] = s[i];
    ans[now] = '\0';
    printf("%s\n", ans + 1);
    return 0;
}
