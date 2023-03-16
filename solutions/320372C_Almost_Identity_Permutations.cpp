// Problem: Almost Identity Permutations
// URL: https://codeforces.com/gym/320372/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k;

int main(){
    scanf("%d%d", &n, &k);
    ll ans=0;
    if(k==4){
        ans+=(ll)3*n*(n-1)*(n-2)*(n-3)/8;
        k--;
    }
    if(k==3){
        ans+=(ll)n*(n-1)*(n-2)/3;
        k--;
    }
    if(k==2){
        ans+=(ll)n*(n-1)/2;
        k--;
    }
    if(k==1) k--;
    if(k==0) ans+=1;
    printf("%lld\n", ans);
}
