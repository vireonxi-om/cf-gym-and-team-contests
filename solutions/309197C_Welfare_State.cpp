// Problem: Welfare State
// URL: https://codeforces.com/gym/309197/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, a[210000], suf[210000], last[210000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        int t;
        scanf("%d", &t);
        if(t==1){
            int x, y; scanf("%d%d", &x, &y);
            last[x]=i;
            a[x]=y;
        }
        else{
            int x; scanf("%d", &x);
            suf[i]=x;
        }
    }
    for(int i=q; i>=1; i--) suf[i]=max(suf[i], suf[i+1]);
    for(int i=1; i<=n; i++) printf("%d ", max(a[i], suf[last[i]+1]));
    printf("\n");
    return 0;
}