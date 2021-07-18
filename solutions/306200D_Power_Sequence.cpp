// Problem: Power Sequence
// URL: https://codeforces.com/gym/306200/problem/D
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[110000];

int main(){
    scanf("%d", &n);
    ll sum=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    sort(a+1, a+n+1);
    ll result=sum-n;
    for(int i=1; ;i++){
        ll now=1, tot=0;
        for(int j=1; j<=n; j++){
            tot+=abs(now-a[j]);
            if(tot>result) break;
            now*=i;
        }
        if(tot>result) break;
        result=tot;
    }
    printf("%lld\n", result);
    return 0;
}
