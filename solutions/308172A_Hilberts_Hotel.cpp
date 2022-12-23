// Problem: Hilbert's Hotel
// URL: https://codeforces.com/gym/308172/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000], cnt[210000];

void solve(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) cnt[i]=0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        int t=(i+a[i])%n;
        if(t<0) t+=n;
        cnt[t]++;
    }
    bool can=true;
    for(int i=0; i<n; i++){
        if(cnt[i]!=1) can=false;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
