// Problem: Multi-judge Solving
// URL: https://codeforces.com/gym/322393/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll k, a[1100];

int main(){
    scanf("%d %lld", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    int ans=0;
    for(int i=1; i<=n; i++){
        if(a[i]<=2*k){ k=max(k, a[i]); continue;}
        else{
            while(k*2<a[i]){
                k*=2;
                ans++;
            }
            k=max(k, a[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
