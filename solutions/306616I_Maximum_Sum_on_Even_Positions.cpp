// Problem: Maximum Sum on Even Positions
// URL: https://codeforces.com/gym/306616/problem/I
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000], b1[110000], b2[110000];
ll result, s1[110000], s2[110000];

void solve(){
    scanf("%d", &n);
    int s=0, t=0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(i%2==0 && i>0) b1[++s]=a[i-1]-a[i];
        if(i%2==1) b2[++t]=a[i]-a[i-1];
    }
    s1[0]=0; s2[0]=0;
    for(int i=1; i<=s; i++) s1[i]=s1[i-1]+b1[i];
    for(int i=1; i<=t; i++) s2[i]=s2[i-1]+b2[i];
    ll p=0; result=0;
    for(int i=1; i<=s; i++){
        p=min(p, s1[i-1]);
        result=max(result, s1[i]-p);
    }
    p=0;
    for(int i=1; i<=t; i++){
        p=min(p, s2[i-1]);
        result=max(result, s2[i]-p);
    }
    for(int i=0; i<n; i+=2) result+=a[i];
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

