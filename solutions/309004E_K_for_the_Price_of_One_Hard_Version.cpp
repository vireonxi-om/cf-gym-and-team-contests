// Problem: K for the Price of One (Hard Version)
// URL: https://codeforces.com/gym/309004/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[210000], pre[210000];
ll p;

void solve(){
    scanf("%d%lld%d", &n, &p, &k);
    for(int i=1; i<=n; i++){scanf("%d", &a[i]); pre[i]=0;}
    sort(a+1, a+n+1);
    a[0]=0;
    for(int i=1; i<=k; i++) pre[i]=pre[i-1]+a[i];
    int result=0;
    for(int i=0; i<k; i++){
        ll now=pre[i];
        if(now>p) break;
        int j;
        for(j=1; i+j*k<=n; j++){
            now+=a[i+j*k];
            if(now>p) break;
        }
        j--;
        result=max(result, i+j*k);
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
