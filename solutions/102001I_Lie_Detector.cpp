// Problem: Lie Detector
// URL: https://codeforces.com/gym/102001/problem/I
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

int n;
int a[N];
char s[20];

int main(){
    scanf("%d", &n);
    repn(i, 1, n){
        scanf("%s", s + 1);
        if (s[1] == 'L') a[i] = 0;
        else a[i] = 1;
    }
    pern(i, 2, n) {
        if (a[i] == 0) a[i - 1] = (a[i - 1] ^ 1);
        else continue;
    }
    if (a[1]) printf("TRUTH\n");
    else printf("LIE\n");
    return 0;
}