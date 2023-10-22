// Problem: Nezzar and Symmetric Array
// URL: https://codeforces.com/gym/329456/problem/E
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a;

void solve(){
    a.clear();
    scanf("%d", &n);
    ll num;
    for(int i=1; i<=2*n; i++) {
        scanf("%lld", &num);
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    bool can=true;
    if(a[0]!=a[1] || a[0]%2) can=false;
    ll sum=0;
    for(int i=3; i<2*n; i+=2){
        if(!can) break;
        if(a[i]==a[i-2]) can=false;
        if(a[i-1]!=a[i]) can=false;
        if((a[i]-a[i-2])%(i-1)) can=false;
        sum+=(a[i]-a[i-2])/(i-1)*(n-(i-1)/2);
    }
    if(can) {
        if((a[0]/2-sum)<=0 || (a[0]/2-sum)%n) can=false;
    }
    if(can) printf("YES\n");
    else printf("NO\n");

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
