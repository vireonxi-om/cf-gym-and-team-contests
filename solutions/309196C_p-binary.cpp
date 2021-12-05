// Problem: p-binary
// URL: https://codeforces.com/gym/309196/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, p;

int cnt(ll num){
    int result=0;
    while(num>0){
        if(num%2){
            num--; result++;
        }
        num/=2;
    }
    return result;
}

int main(){
    scanf("%lld%lld", &n, &p);
    bool can=false;
    ll ans=n; int result;
    for(int i=1; i<=31; i++){
        ans-=p;
        if(ans<=0) break;
        if(cnt(ans)<=i && ans>=i){
            can=true; result=i; break;
        }
    }
    if(can) printf("%d\n", result);
    else printf("-1\n");
    return 0;
}
