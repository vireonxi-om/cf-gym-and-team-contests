// Problem: Cat Party (Hard Edition)
// URL: https://codeforces.com/gym/310047/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000], cnt[110000], num[110000];

int main(){
    scanf("%d", &n);
    int tot, l=1, r=1, result=1;
    scanf("%d", &a[1]); cnt[a[1]]++; tot++; num[1]=1;
    for(int i=2; i<=n; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++; int t=cnt[a[i]];
        num[t-1]--; num[t]++;
        if(t==1) tot++;
        if(t>r) r=t;
        if(t<l || num[l]==0) l=t;
        if(num[r]==tot-1){
            if(r*(tot-1)==(i-1) && l==1) result=i;
        }
        if(num[r]==tot && r==1) result=i;
        if(tot==1) result=i;
        if(num[r]==1){
            if(l*tot==i-1 && r==l+1) result=i;
        }
    }
    printf("%d\n", result);
    return 0;
}

