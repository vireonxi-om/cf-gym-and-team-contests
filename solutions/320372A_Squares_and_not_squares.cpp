// Problem: Squares and not squares
// URL: https://codeforces.com/gym/320372/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[210000];
vector<ll> sq, ts, tn;

int main(){
    scanf("%d", &n);
    for(int i=0; i<=40000; i++) sq.push_back((ll)i*i);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        ll ans;
        int t=sqrt(a[i]);
        if(t*t==a[i]){
            auto it=lower_bound(sq.begin(), sq.end(), a[i]);
            if((*it)==0) ans=2;
            else ans=1;
            tn.push_back(ans);
        }
        else{
            auto it=lower_bound(sq.begin(), sq.end(), a[i]);
            ans=(*it)-a[i];
            it--;
            ans=min(ans, a[i]-(*it));
            ts.push_back(ans);
        }
    }
    sort(tn.begin(), tn.end());
    sort(ts.begin(), ts.end());
    ll tot=0;
    int t=tn.size()-n/2;
    if(t>0){
        for(int i=0; i<t; i++) tot+=tn[i];
    }
    else for(int i=0; i<-t; i++) tot+=ts[i];
    printf("%lld\n", tot);
}
