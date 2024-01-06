// Problem: Convenient For Everybody
// URL: https://codeforces.com/gym/316837/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, s, f, a[110000], pre[110000];


int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    scanf("%d%d", &s, &f);
    int t=f-s;
    for(int i=1; i<=n; i++) {
        pre[i]=pre[i-1]+a[i];
    }
    int m=0, ans=2e9;
    for(int i=1; i<=n; i++){
        int now;
        if(i<=n-t+1){
            now=pre[i+t-1]-pre[i-1];
        }
        else{
            now=pre[n]-pre[i-1]+pre[t-(n-i+1)];
        }
        int num=s-i+1;
        if(num<=0) num+=n;
        if(now>m){
            m=now;
            ans=num;
        }
        else if(now==m){
            ans=min(ans, num);
        }
    }
    printf("%d\n", ans);
    return 0;
}
