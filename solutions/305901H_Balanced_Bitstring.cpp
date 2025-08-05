// Problem: Balanced Bitstring
// URL: https://codeforces.com/gym/305901/problem/H
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k;
char a[310000];

void solve(){
    scanf("%d%d", &n, &k);
    memset(a, '?', sizeof(a));
    char m;
    bool can=true;
    getchar();
    for(int i=1; i<=n; i++){
        scanf("%c", &m);
        if(a[i%k]!='?'){
            if(m!='?' && m!=a[i%k]) can=false;
        }
        else a[i%k]=m;
    }
    int cnt0=0, cnt1=0;
    for(int i=0; i<k; i++){
        if(a[i]=='1') cnt1++;
        if(a[i]=='0') cnt0++;
    }
    if(cnt0>k/2) can=false;
    else if (cnt1>k/2) can=false;
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

