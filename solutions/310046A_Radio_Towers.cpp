// Problem: Radio Towers
// URL: https://codeforces.com/gym/310046/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, fib[210000];
const int MOD=998244353;

int bpow(int x, int y){
    int result=1;
    while(y){
        if(y%2==1){
            result=((ll)result*x)%MOD;
        }
        x=((ll)x*x)%MOD;
        y/=2;
    }

    return result;
}

int main(){
    scanf("%d", &n);
    fib[0]=0; fib[1]=1;
    for(int i=2; i<=n; i++) {
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=MOD;
    }
    int ans=bpow(2, n);
    ans=bpow(ans, MOD-2);
    ans=((ll)fib[n]*ans)%MOD;
    printf("%d\n", ans);
    return 0;
}