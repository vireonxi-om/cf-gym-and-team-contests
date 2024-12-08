// Problem: Walking Between Houses
// URL: https://codeforces.com/gym/314707/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, ans[210000];
ll s;

int main(){
    scanf("%d%d%lld", &n, &k, &s);
    ll a=s/k, b=s%k;
    bool can=true;
    if(b && a+1>n-1) can=false;
    else if(a>n-1 || a==0) can=false;
    if(!can){
        printf("NO\n");
        return 0;
    }
    int pos=1;
    ans[0]=1;
    while(pos<=b){
        if(pos%2==1) ans[pos]=ans[pos-1]+a+1;
        else ans[pos]=ans[pos-1]-a-1;
        pos++;
    }
    while(pos<=k){
        if(pos%2==1) ans[pos]=ans[pos-1]+a;
        else ans[pos]=ans[pos-1]-a;
        pos++;
    }
    printf("YES\n");
    for(int i=1; i<=k; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}