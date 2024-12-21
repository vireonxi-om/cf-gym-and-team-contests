// Problem: Mismatched Socks
// URL: https://codeforces.com/gym/101291/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1100];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll sum=0;
    for(int i=1; i<n; i++) sum+=a[i];
    if(sum<=a[n]) printf("%lld\n", sum);
    else printf("%lld\n", (sum+a[n])/2);
    return 0;
}
