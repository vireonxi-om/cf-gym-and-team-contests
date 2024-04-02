// Problem: Easy Math Problem
// URL: https://codeforces.com/gym/103145/problem/E
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p;

void solve(){
    scanf("%lld", &p);
    printf("%lld 3\n", 6*p);
    printf("%lld %lld %lld\n", p, 2*p, 3*p);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

