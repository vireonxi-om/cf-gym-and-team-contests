// Problem: Pokémon Army (easy version)
// URL: https://codeforces.com/gym/302720/problem/C
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, p;
long long a[310000], result;
void solve(){
    memset(a, 0, sizeof(a));
    result=0;
    scanf("%d%d", &n, &p);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++){
        if (a[i]==a[i+1]) continue;
        else if(a[i]<=a[i-1] && a[i]<=a[i+1]) result-=a[i];
        else if(a[i]>=a[i-1] && a[i]>=a[i+1]) result+=a[i];
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
