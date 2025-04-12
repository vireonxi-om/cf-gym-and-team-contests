// Problem: Kuroni and Impossible Calculation
// URL: https://codeforces.com/gym/308347/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, result;
int a[210000], dif[210000];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++) dif[i]=a[i]-a[1];
    if(n>m) result=0;
    else{
        result=1;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                result*=((dif[j]-dif[i])%m);
                result=result%m;
            }
        }
    }
    printf("%d\n", result);

    return 0;
}

