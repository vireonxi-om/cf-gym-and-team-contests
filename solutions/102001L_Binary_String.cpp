// Problem: Binary String
// URL: https://codeforces.com/gym/102001/problem/L
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
LL k;
string s, t, t1;

LL to_dem(string now) {
    int len = now.size();
    LL result = 0;
    rep(i, 0, len) {
        result *= 2;
        result += now[i] - '0';
    }
    return result;
}

int main(){
    scanf("%lld", &k);
    cin >> s;
    n = s.size();
    int cnt = 0; LL num = k;
    while(num) {
        cnt ++;
        num /= 2;
    }
    if (n > cnt) {
        int res = n - cnt;
        t += '1';
        rep(i, 1, n) {
            if (s[i] == '1') {
                if (res){
                    res --;
                    continue;
                }
                else t += '1';
            }
            else t += '0';
        }
        LL result;
        if (! res){ result = to_dem(t);}
        else {
            rep(i, 0, cnt) t1 += t[i];
            result = to_dem(t1);
        }
        if (result > k) printf("%d\n", n - cnt + 1);
        else printf("%d\n", n - cnt);
    }
    else {
        if (to_dem(s) > k) printf("1\n");
        else printf("0\n");
    }
    return 0;
}