// Problem: Kate's 2021 Celebration
// URL: https://codeforces.com/gym/102896/problem/K
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

int n, p = -1, id = -1;
char s[110];


int main(){
    scanf("%d", &n);
    int num;
    repn(i, 1, n) {
        scanf("%d%s", &num, s + 1);
        int len = strlen(s + 1);
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        repn(j, 1, len) {
            if (s[j] == '0') cnt0 ++;
            else if (s[j] == '1') cnt1 ++;
            else if (s[j] == '2') cnt2 ++;
        }
        if (cnt0 >= 1 && cnt1 >= 1 && cnt2 >= 2) {
            if (num < p && p != -1 || p == -1) {
                id = i; p = num;
            }
        }
    }
    if (id == -1) printf("0\n");
    else printf("%d\n", id);
    return 0;
}



