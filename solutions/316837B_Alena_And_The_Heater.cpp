// Problem: Alena And The Heater
// URL: https://codeforces.com/gym/316837/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000];
char b[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    scanf("%s", b+1);
    int l1=-2e9, r1=2e9;
    bool lyes=false, ryes=false;
    for(int i=5; i<=n; i++){
        if(b[i]!=b[i-1]){
            if(b[i]=='1'){
                lyes=true;
                l1=max(l1, a[i]); l1=max(l1, a[i-1]);
                l1=max(l1, a[i-2]); l1=max(l1, a[i-3]); l1=max(l1, a[i-4]);
            }
            else{
                ryes=true;
                r1=min(r1, a[i]); r1=min(r1, a[i-1]);
                r1=min(r1, a[i-2]); r1=min(r1, a[i-3]); r1=min(r1, a[i-4]);
            }
        }
    }
    int l=-1000000000, r=1000000000;
    if(lyes) l=l1+1;
    if(ryes) r=r1-1;
    printf("%d %d\n", l, r);
    return 0;
}
