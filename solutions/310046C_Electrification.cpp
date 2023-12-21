// Problem: Electrification
// URL: https://codeforces.com/gym/310046/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, a[210000];
set<pair<int, int>> p;

void solve(){
    scanf("%d%d", &n, &k);
    p.clear();
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n-k; i++){
        p.insert(make_pair((a[i+k]-a[i]+1)/2, (a[i+k]+a[i])/2));
    }
    printf("%d\n", (*p.begin()).second);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}