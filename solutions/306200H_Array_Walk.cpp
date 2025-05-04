// Problem: Array Walk
// URL: https://codeforces.com/gym/306200/problem/H
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, z, a[110000];

void solve(){
    scanf("%d%d%d", &n, &k, &z);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int result=0;
    for(int i=z; i>=0; i--){
        int sum=0, maxi=0;
        for(int j=1; j<=k-2*i+1; j++){
            sum+=a[j];
            maxi=max(maxi, a[j]+a[j+1]);
        }
        result=max(result, sum+i*maxi);
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

/*30 29 5 42 8468 6335 6501 9170 5725 1479 9359
6963 4465 5706 8146 3282 6828 9962 492 2996 1943
4828 5437 2392 4605 3903 154 293 2383 7422 8717 9719 9896*/

