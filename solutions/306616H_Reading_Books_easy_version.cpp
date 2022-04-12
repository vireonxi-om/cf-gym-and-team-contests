// Problem: Reading Books (easy version)
// URL: https://codeforces.com/gym/306616/problem/H
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[210000], b[210000], c[210000];

int main(){
    scanf("%d%d", &n, &k);
    int cnta=0, cntb=0, cntc=0;
    for(int i=0; i<n; i++){
        int num, x, y;
        scanf("%d%d%d", &num, &x, &y);
        if(x==1 && y==1) c[++cntc]=num;
        else if(x==1) a[++cnta]=num;
        else if(y==1) b[++cntb]=num;
    }
    if(cnta+cntc<k || cntb+cntc<k){
        printf("-1\n"); return 0;
    }
    sort(a+1, a+cnta+1);
    sort(b+1, b+cntb+1);
    sort(c+1, c+cntc+1);
    ll result=1e11;
    for(int i=0; i<=min(k, cntc); i++){
        if(cnta+i>=k && cntb+i>=k){
            ll sum=0;
            for(int j=1; j<=k-i; j++) sum+=(a[j]+b[j]);
            for(int j=1; j<=i; j++) sum+=c[j];
            result=min(result, sum);
        }
    }
    printf("%lld\n", result);
    return 0;
}
