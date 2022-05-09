// Problem: Celex Update
// URL: https://codeforces.com/gym/307718/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a1, b1, a2, b2;
ll result;

void solve(){
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
    result=1;
    result*=(a2-a1);
    result*=(b2-b1);
    result++;
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
