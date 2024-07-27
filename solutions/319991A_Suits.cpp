// Problem: Suits
// URL: https://codeforces.com/gym/319991/problem/A
// Rating: 800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int a, b, c, d, e, f;
ll ans;

int main(){
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int s1=min(a, d), s2=min(min(b, c), d);
    if(e>=f){
        ans=e*s1+f*min(s2, d-s1);
    }
    else{
        ans=f*s2+e*min(s1, d-s2);
    }
    printf("%lld\n", ans);
    return 0;
}