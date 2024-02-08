// Problem: Throne
// URL: https://codeforces.com/gym/312858/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, s, k;

int gcd(int a, int b){
    return b==0? a : gcd(b, a%b);
}

int ex_gcd(int a, int b, int &x, int &y) {
    int ret, tmp;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ret = ex_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

void solve(){
    scanf("%d%d%d", &n, &s, &k);
    int a=k, b=n-s;
    int m=gcd(n, gcd(a, b));
    a/=m; b/=m; n/=m;
    int x, y;
    int t=ex_gcd(a, n, x, y);
    if(t!=1) printf("-1\n");
    else{
        x+=n; x%=n;
        printf("%lld\n", (ll)x*b%n);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
