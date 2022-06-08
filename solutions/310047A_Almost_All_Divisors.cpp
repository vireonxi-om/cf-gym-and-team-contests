// Problem: Almost All Divisors
// URL: https://codeforces.com/gym/310047/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[310000];
ll x;

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    x=(ll)a[1]*a[n];
    vector<int> ans;
    for(int i=2; (ll)i*i<=x; i++){
        if(x%i==0){
            ans.push_back(i);
            if((ll)i*i!=x) ans.push_back(x/i);
        }
    }
    sort(ans.begin(), ans.end());
    bool can=true;
    if(ans.size()!=n) can=false;
    for(int i=1; i<=n; i++){
        if(ans[i-1]!=a[i]) can=false;
    }
    if(can) printf("%lld\n", x);
    else printf("-1\n");

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


