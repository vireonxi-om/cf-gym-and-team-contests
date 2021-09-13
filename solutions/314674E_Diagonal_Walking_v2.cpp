// Problem: Diagonal Walking v.2
// URL: https://codeforces.com/gym/314674/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll m, n, k;

void solve(){
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k<max(m, n)){ printf("-1\n"); return;}
    if(abs(n-m)%2==0){
        if((k-max(m, n))%2==1) printf("%lld\n", k-2);
        else printf("%lld\n", k);
    }
    else printf("%lld\n", k-1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}