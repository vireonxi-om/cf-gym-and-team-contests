// Problem: Sum of Difference
// URL: https://codeforces.com/gym/312858/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[210000];
ll sum;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for(int i=2; i<=n; i++){
        ll now=a[i]-a[i-1];
        sum+=now*(i-1)*(n-i+1);
    }
    printf("%lld\n", sum);
    return 0;
}
