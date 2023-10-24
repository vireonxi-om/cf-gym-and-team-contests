// Problem: Cram Time
// URL: https://codeforces.com/gym/314705/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int a, b, n, m, ans[1100000];

int main(){
    scanf("%d%d", &a, &b);
    ll sum=a+b;
    int tot;
    for(tot=1; ; tot++){
        if((ll)tot*(tot+1)/2>sum) {tot--; break;}
    }
    int i=tot;
    while(a && i){
        if(a>i){ a-=i; ans[i]=1; n++;}
        else{ ans[a]=1; n++; break;}
        i--;
    }
    m=tot-n;
    printf("%d\n", n);
    for(int i=1; i<=tot; i++) if(ans[i]==1) printf("%d ", i); printf("\n");
    printf("%d\n", m);
    for(int i=1; i<=tot; i++) if(ans[i]==0) printf("%d ", i); printf("\n");
    return 0;
}