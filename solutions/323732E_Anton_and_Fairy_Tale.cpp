// Problem: Anton and Fairy Tale
// URL: https://codeforces.com/gym/323732/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;

int main(){
    scanf("%lld%lld", &n, &m);
    if(n<=m) printf("%lld\n", n);
    else{
        ll l=1, r=n, ans;
        while(l<=r){
            ll mid=(l+r)/2;
            if(((double)mid*mid+mid)>(double)2*n){ ans=mid; r=mid-1; continue;}
            ll now=mid*mid-mid;
            now/=2;
            if(now+m+mid>=n) {ans=mid; r=mid-1; }
            else l=mid+1;
        }
        printf("%lld\n", m+ans);
    }
    return 0;
}

