// Problem: Bouncing Ball
// URL: https://codeforces.com/gym/306616/problem/B
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p, k, x, y, a[110000], sum[110000];

void solve(){
    scanf("%d%d%d", &n, &p, &k);
    ll result=1e11;
    for(int i=1; i<=n; i++){
        scanf("%1d", &a[i]);
        if(i>=p && a[i]==0) sum[(i-p)%k]++;
    }
    scanf("%d%d", &x, &y);
    for(int i=0; i<=n-p; i++){
        ll tot=(ll)i*y+(ll)x*sum[i%k];
        result=min(tot, result);
        sum[i%k]-=(1-a[i+p]);
    }
    printf("%lld\n", result);
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
