// Problem: Football
// URL: https://codeforces.com/gym/317861/problem/C
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k;

int main(){
    scanf("%d%d", &n, &k);
    bool can=true;
    if(n*(n-1)/2<k*n) can=false;
    if(can){
        printf("%d\n", n*k);
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=i+k; j++){
                int now=j;
                if(now>n) now-=n;
                printf("%d %d\n", i, now);
            }
        }
    }
    else printf("-1\n");
    return 0;
}
