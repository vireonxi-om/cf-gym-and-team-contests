// Problem: K-th Beautiful String
// URL: https://codeforces.com/gym/303728/problem/H
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k;

void solve(){
    scanf("%d%d", &n, &k);
    int i=1, j=k-1;
    for(; ; i++){
        j-=i;
        if(j<0){
            j+=i;
            break;
        }
    }
    for(int m=1; m<=n; m++){
        if(m==n-j || m==n-i) printf("b");
        else printf("a");
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

