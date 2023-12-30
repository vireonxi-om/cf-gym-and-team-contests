// Problem: Destroying Array
// URL: https://codeforces.com/gym/328532/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[110000];
set<pair<int, int>> s;
multiset<ll> ans;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++) a[i]+=a[i-1];
    s.insert(make_pair(1, n));
    ans.insert(a[n]);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        auto it=s.upper_bound(make_pair(num, n+1));
        it--;
        int l=(*it).first, r=(*it).second;
        s.erase(it);
        auto it2=ans.lower_bound(a[r]-a[l-1]);
        ans.erase(it2);
        if(num>l){
            ans.insert(a[num-1]-a[l-1]);
            s.insert(make_pair(l, num-1));
        }
        if(num<r){
            ans.insert(a[r]-a[num]);
            s.insert(make_pair(num+1, r));
        }
        if(ans.empty()) printf("0\n");
        else{
            auto item=ans.end();
            item--;
            printf("%lld\n", (*item));
        }

    }
    return 0;
}