// Problem: Toy Blocks
// URL: https://codeforces.com/gym/305901/problem/A
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sum, maxi, result;

void solve(){
    scanf("%lld", &n);
    maxi=0; sum=0;
    ll num;
    for(ll i=1; i<=n; i++){
        scanf("%lld", &num);
        maxi=max(maxi, num);
        sum+=num;
    }
    ll k;
    if(sum%(n-1)==0) k=sum;
    else k=sum+n-1-sum%(n-1);
    result=max(maxi*(n-1), k);
    result-=sum;
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
