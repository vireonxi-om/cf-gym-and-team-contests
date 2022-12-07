// Problem: Multiples of Length
// URL: https://codeforces.com/gym/306200/problem/F
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    printf("1 1\n");
    printf("%d\n", n-a[1]);
    if(n>1){
        printf("%d %d\n", 2, n);
        for(int i=2; i<=n; i++){
            ll t=(ll)a[i]*(n-1);
            printf("%lld ", t);
        }
        printf("\n");
    }
    else printf("1 1\n0\n");
    printf("1 %d\n", n);
    printf("%d ", -n);
    if(n>1) for(int i=2; i<=n; i++){
        ll t=(ll)a[i]*n;
        printf("%lld ", -t);
    }
    printf("\n");
    return 0;
}
