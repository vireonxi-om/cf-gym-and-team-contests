// Problem: Party Lemonade
// URL: https://codeforces.com/gym/318002/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll ans[50], c[50], l;

int main(){
    scanf("%d%lld", &n, &l);
    for(int i=0; i<n; i++) scanf("%lld", &c[i]);
    for(int i=1; i<n; i++) c[i]=min(c[i], 2*c[i-1]);
    int now=0;
    while(l){
        ans[now]=l%2;
        l/=2;
        now++;
    }

    ll tot=0;
    for(int i=now; i>=n; i--){
        if(ans[i]) ans[i-1]+=2*ans[i];
    }
    for(int i=0; i<n; i++){
        tot+=c[i]*ans[i];
        if(i==n-1) break;
        tot=min(tot, c[i+1]);
    }
    printf("%lld\n", tot);
}
