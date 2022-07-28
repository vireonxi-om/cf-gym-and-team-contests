// Problem: Maximum Subrectangle
// URL: https://codeforces.com/gym/312561/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, x, a[2100], b[2100], va[4100000], vb[4100000];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){ scanf("%d", &a[i]); a[i]+=a[i-1];}
    for(int i=1; i<=m; i++){ scanf("%d", &b[i]); b[i]+=b[i-1];}
    scanf("%d", &x);
    for(int i=1; i<=n; i++){
        for(int j=0; j+i<=n; j++)
            va[a[j+i]-a[j]]=max(va[a[j+i]-a[j]], i);
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j+i<=m; j++)
            vb[b[j+i]-b[j]]=max(vb[b[j+i]-b[j]], i);
    }
    for(int i=1; i<4100000; i++) vb[i]=max(vb[i], vb[i-1]);
    int result=0;
    for(int i=1; i<4100000; i++){
        if(va[i]==0) continue;
        if(i>x) break;
        int t=min(x/i, 4000001);
        result=max(result, va[i]*vb[t]);
    }
    printf("%d\n", result);
}