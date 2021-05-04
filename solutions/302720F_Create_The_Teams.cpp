// Problem: Create The Teams
// URL: https://codeforces.com/gym/302720/problem/F
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, result;
long long x, a[110000];

void solve(){
    result=0;
    scanf("%d%lld", &n, &x);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    int st=n, stop=0;
    while(st>0){
        for(int i=0; i<=st; i++){
            if(i==st){
                stop=1; break;
            }
            if(a[st-i]*(i+1)>=x){
                st=st-i-1;
                result++;
                break;
            }
        }
        if(stop==1) break;
        stop=0;
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
