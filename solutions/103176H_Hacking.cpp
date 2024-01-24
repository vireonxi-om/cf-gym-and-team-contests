// Problem: Hacking
// URL: https://codeforces.com/gym/103176/problem/H
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

int n;
int a, b, c, d[5];

int main(){
    scanf("%d%d%d", &d[1], &d[2], &d[3]);
    scanf("%d%d%d", &a, &b, &c);
    int now = 3, ans = 0;
    while(now) {
        if (c > d[now]){
            now --;
            ans ++;
            break;
        }
        else now --;
    }
    while(now) {
        if (b > d[now]){
            now --;
            ans ++;
            break;
        }
        else now --;
    }
    while(now) {
        if (a > d[now]){
            now --;
            ans ++;
            break;
        }
        else now --;
    }
    printf("%d\n", ans);
    return 0;
}
