// Problem: Tennis Championship
// URL: https://codeforces.com/gym/328479/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[110000];

int main(){
    scanf("%lld", &n);
    a[1]=2; a[0]=1;
    int i=1;
    while(a[i]<=n){
        a[i+1]=a[i]+a[i-1];
        i++;
    }
    i--;
    printf("%d\n", i);
    return 0;
}

