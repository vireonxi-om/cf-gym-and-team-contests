// Problem: Cyclic Permutations 
// URL: https://codeforces.com/gym/306616/problem/D
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000000007

int main(){
    int n;
    scanf("%d", &n);
    ll a=1, b=1;
    for(int i=1; i<=n; i++){
        a*=i;
        a=a%(N);
    }
    for(int i=1; i<=n-1; i++){
        b*=2;
        b=b%(N);
    }
    if(a<b) a+=N;
    printf("%lld\n", (a-b)%(N));
}
