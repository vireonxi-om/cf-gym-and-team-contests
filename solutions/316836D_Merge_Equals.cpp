// Problem: Merge Equals
// URL: https://codeforces.com/gym/316836/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
priority_queue<pair<ll, int>> a;
set<pair<int, ll>> ans;

int main(){
    scanf("%d", &n);
    ll num;
    for(int i=1; i<=n; i++){
        scanf("%lld", &num);
        a.push(make_pair(-num, -i));
    }
    while(!a.empty()){
        int np=a.top().second;
        ll now=a.top().first;
                a.pop();
        if(a.empty()){
            ans.insert(make_pair(-np, -now));
            break;
        }
        int nextp=a.top().second;
        ll next=a.top().first;
        if(now==next){
            a.pop();
            a.push(make_pair(2*now, nextp));
        }
        else{
            ans.insert(make_pair(-np, -now));
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans) printf("%lld ", x.second);
    printf("\n");
    return 0;
}