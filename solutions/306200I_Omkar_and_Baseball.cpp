// Problem: Omkar and Baseball
// URL: https://codeforces.com/gym/306200/problem/I
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[210000];

void solve(){
    scanf("%d", &n);
    int cnt=0, cnt1=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]==i) cnt++;
        if(i>1 && a[i]!=i && a[i-1]==i-1) cnt1++;
    }
    if(cnt==n) printf("0\n");
    else if(a[1]==1 && cnt1>1 || a[1]!=1 && cnt1>0)
        printf("2\n");
    else printf("1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
