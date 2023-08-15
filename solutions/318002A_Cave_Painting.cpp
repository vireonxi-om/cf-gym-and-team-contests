// Problem: Cave Painting
// URL: https://codeforces.com/gym/318002/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll n, k;


int main(){
    scanf("%lld%lld", &n, &k);
    n++;
    bool can=true;
    for(ll i=k; i>=1; i--){
        if(n%i){can=false; break;}
    }
    if(can) printf("Yes\n");
    else printf("No\n");
    return 0;
}

